#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>
#include <boost/interprocess/sync/named_condition.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include <boost/array.hpp>
#include <string>
#include <sstream>
#include <fstream>

int main()
{
    boost::interprocess::shared_memory_object::remove("be8c656b-7ef4-4bd5-af0c-07aa38fc75dd");
    boost::interprocess::named_mutex::remove("8e2d0809-7ca8-4f77-bed3-da61fd9863cf");
    boost::interprocess::named_condition::remove("aa70ab19-27ce-4962-a695-42f0e3f72f2d");

    boost::interprocess::managed_shared_memory managed_shm{ boost::interprocess::create_only, "be8c656b-7ef4-4bd5-af0c-07aa38fc75dd", 5120 };

    using char_allocator = boost::interprocess::allocator<char, boost::interprocess::managed_shared_memory::segment_manager>;
    using string = boost::interprocess::basic_string<char, std::char_traits<char>, char_allocator>;
    string *filename = managed_shm.construct<string>("Filename")(managed_shm.get_segment_manager());

    boost::array<char, 4096> *buffer = managed_shm.construct<boost::array<char, 4096>>("Buffer")();

    int *size = managed_shm.construct<int>("Size")(0);

    boost::interprocess::named_mutex mtx{ boost::interprocess::create_only, "8e2d0809-7ca8-4f77-bed3-da61fd9863cf" };
    boost::interprocess::named_condition cnd{ boost::interprocess::create_only, "aa70ab19-27ce-4962-a695-42f0e3f72f2d" };

    boost::interprocess::scoped_lock<boost::interprocess::named_mutex> lock{ mtx };
    cnd.wait(lock);

    std::ostringstream oss;
    while (*size)
    {
        oss << std::string{ buffer->data(), static_cast<std::size_t>(*size) };
        cnd.notify_all();
        cnd.wait(lock);
    }

    std::ofstream ofs{ filename->c_str() };
    if (ofs)
        ofs << oss.str();
}
