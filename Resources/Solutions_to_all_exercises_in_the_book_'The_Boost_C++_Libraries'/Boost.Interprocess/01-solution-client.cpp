#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>
#include <boost/interprocess/sync/named_condition.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include <boost/array.hpp>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstring>

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        std::cout << argv[0] << " <filename>\n";
        return 1;
    }

    std::string fn = argv[1];
    std::ifstream ifs{ argv[1], std::ios::in | std::ios::binary };
    if (!ifs)
    {
        std::cout << fn << " not found\n";
        return 2;
    }

    std::ostringstream oss;
    oss << ifs.rdbuf();
    std::string file = oss.str();

    boost::interprocess::managed_shared_memory managed_shm{ boost::interprocess::open_only, "be8c656b-7ef4-4bd5-af0c-07aa38fc75dd" };

    using char_allocator = boost::interprocess::allocator<char, boost::interprocess::managed_shared_memory::segment_manager>;
    using string = boost::interprocess::basic_string<char, std::char_traits<char>, char_allocator>;
    string *filename = managed_shm.find<string>("Filename").first;
    filename->assign(fn.begin(), fn.end());

    boost::array<char, 4096> *buffer = managed_shm.find<boost::array<char, 4096>>("Buffer").first;

    int *size = managed_shm.find<int>("Size").first;

    boost::interprocess::named_mutex mtx(boost::interprocess::open_only, "8e2d0809-7ca8-4f77-bed3-da61fd9863cf");
    boost::interprocess::named_condition cnd(boost::interprocess::open_only, "aa70ab19-27ce-4962-a695-42f0e3f72f2d");

    boost::interprocess::scoped_lock<boost::interprocess::named_mutex> lock{ mtx };

    std::string::size_type idx = 0;
    while (idx < file.size())
    {
        *size = std::min<int>(4096, file.size() - idx);
        std::memcpy(buffer->data(), file.c_str() + idx, *size);
        idx += *size;
        cnd.notify_all();
        cnd.wait(lock);
    }

    *size = 0;
    cnd.notify_all();
}
