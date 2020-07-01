#include <boost/asio.hpp>
#include <boost/asio/spawn.hpp>
#include <boost/array.hpp>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstring>

std::string filename;
std::string file;
boost::asio::io_service io_service;
boost::asio::ip::tcp::resolver resolver{ io_service };
boost::asio::ip::tcp::socket sock{ io_service };
boost::array<char, 4096> buffer;
std::size_t sent = 0;

int main(int argc, const char *argv[])
{
    if (argc < 3)
    {
        std::cerr << argv[0] << " <IP address> <filename>\n";
        return 1;
    }

    filename = argv[2];
    std::ifstream ifs{ argv[2], std::ios::in | std::ios::binary };
    if (!ifs)
    {
        std::cerr << filename << " not found\n";
        return 2;
    }

    std::ostringstream oss;
    oss << ifs.rdbuf();
    file = oss.str();

    boost::asio::ip::tcp::resolver::query query{ argv[1], "9999" };
    try
    {
        boost::asio::spawn(io_service, [&query](boost::asio::yield_context yield){
            boost::asio::ip::tcp::resolver::iterator it = resolver.async_resolve(query, yield);
            sock.async_connect(*it, yield);
            std::cout << "Transferring " << filename << std::flush;
            std::memcpy(buffer.c_array(), filename.c_str(), filename.size());
            buffer[filename.size()] = '\n';
            boost::asio::async_write(sock, boost::asio::buffer(buffer, filename.size() + 1), yield);
            while (sent < file.size())
            {
                std::cout << "." << std::flush;
                std::size_t size = std::min(sizeof(buffer), file.size() - sent);
                std::memcpy(buffer.c_array(), file.c_str() + sent, size);
                sent += boost::asio::async_write(sock, boost::asio::buffer(buffer, size), yield);
            }
            std::cout << "done\n";
        });
        io_service.run();
    }
    catch (std::system_error &ex)
    {
        std::cerr << ex.what() << '\n';
    }
}
