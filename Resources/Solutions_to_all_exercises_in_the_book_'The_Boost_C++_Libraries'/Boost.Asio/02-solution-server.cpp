#include <boost/asio.hpp>
#include <boost/asio/spawn.hpp>
#include <boost/array.hpp>
#include <boost/filesystem.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

std::string filename;
std::string file;
boost::asio::io_service io_service;
boost::asio::ip::tcp::endpoint endpoint{ boost::asio::ip::tcp::v4(), 9999 };
boost::asio::ip::tcp::acceptor acceptor{ io_service, endpoint };
boost::asio::ip::tcp::socket sock{ io_service };
boost::array<char, 4096> buffer;

int main()
{
    boost::asio::ip::tcp::resolver::query query{ boost::asio::ip::host_name(), "9999" };
    boost::asio::ip::tcp::resolver resolver{ io_service };
    boost::asio::ip::tcp::resolver::iterator it = resolver.resolve(query);
    boost::asio::ip::tcp::resolver::iterator end;
    while (it != end)
    {
        std::cout << it->endpoint().address() << '\n';
        ++it;
    }

    acceptor.listen();
    try
    {
        boost::asio::spawn(io_service, [](boost::asio::yield_context yield){
            acceptor.async_accept(sock, yield);
            boost::system::error_code ec;
            std::size_t bytes_transferred = boost::asio::async_read(sock, boost::asio::buffer(buffer), yield[ec]);
            while (bytes_transferred)
            {
                std::string data{ buffer.data(), bytes_transferred };
                if (filename.empty())
                {
                    std::istringstream iss{ data };
                    std::getline(iss, filename);
                    file = data;
                    file.erase(0, filename.size() + 1);
                    filename = boost::filesystem::path{ filename }.filename().string();
                }
                else
                {
                    file += data;
                }
                bytes_transferred = boost::asio::async_read(sock, boost::asio::buffer(buffer), yield[ec]);
            }
            std::ofstream ofs{ filename.c_str(), std::ios::out | std::ios::binary };
            if (ofs)
            {
                ofs << file;
                std::cout << filename << " received\n";
            }
        });
        io_service.run();
    }
    catch (std::system_error &ex)
    {
        std::cerr << ex.what() << '\n';
    }
}
