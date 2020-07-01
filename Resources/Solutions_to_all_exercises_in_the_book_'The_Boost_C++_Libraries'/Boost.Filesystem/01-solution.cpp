#include <boost/filesystem.hpp>
#include <stdexcept>
#include <iostream>

int main()
{
    try
    {
        boost::filesystem::path p = boost::filesystem::current_path();
        boost::filesystem::directory_iterator it{ p };
        while (it != boost::filesystem::directory_iterator{})
        {
            boost::filesystem::file_status s = boost::filesystem::status(*it);
            if (boost::filesystem::is_regular_file(s) && it->path().extension() == ".cpp")
                std::cout << it->path().filename() << '\n';
            ++it;
        }
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << '\n';
    }
}
