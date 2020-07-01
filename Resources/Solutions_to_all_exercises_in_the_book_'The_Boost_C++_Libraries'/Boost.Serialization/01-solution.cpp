#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>
#include <string>
#include <fstream>
#include <type_traits>
#include <stdexcept>
#include <iostream>

namespace boost {
namespace serialization {

struct saving {};
struct loading {};

template <class Archive>
void serialize(Archive &ar, std::runtime_error &ex, const unsigned int version, saving)
{
    ar << std::string{ ex.what() };
}

template <class Archive>
void serialize(Archive &ar, std::runtime_error &ex, const unsigned int version, loading)
{
    std::string s;
    ar >> s;
    ex = std::runtime_error{ s };
}

template <class Archive>
void serialize(Archive &ar, std::runtime_error &ex, const unsigned int version)
{
    auto tag = std::conditional_t<Archive::is_saving::value, saving, loading>{};
    serialize(ar, ex, version, tag);
}

}
}

void save(const std::runtime_error &ex)
{
    std::ofstream file{ "archive.txt" };
    boost::archive::text_oarchive oa{ file };
    oa << ex;
}

void load(std::runtime_error &ex)
{
    std::ifstream file{ "archive.txt" };
    boost::archive::text_iarchive ia{ file };
    ia >> ex;
}

int main()
{
    {
        std::runtime_error ex{ "my runtime error" };
        save(ex);
    }
    {
        std::runtime_error ex{ "" };
        load(ex);
        std::cout << ex.what() << '\n';
    }
}
