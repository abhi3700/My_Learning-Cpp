#include <boost/iostreams/device/file.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/filter/zlib.hpp>
#include <string>
#include <fstream>
#include <iostream>

using namespace std::string_literals;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " <filename>";
        return 0;
    }

    boost::iostreams::file_sink out{ argv[1] + ".unzip"s };
    boost::iostreams::filtering_ostream os;
    os.push(boost::iostreams::zlib_decompressor{});
    os.push(out);
    std::ifstream in{ argv[1] };
    os << in.rdbuf();
    os.pop();
}
