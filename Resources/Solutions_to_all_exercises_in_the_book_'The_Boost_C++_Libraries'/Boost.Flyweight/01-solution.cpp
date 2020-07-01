#include <boost/flyweight.hpp>
#include <boost/flyweight/set_factory.hpp>
#include <boost/flyweight/no_locking.hpp>
#include <string>
#include <vector>

int main()
{
    using string_type = boost::flyweights::flyweight<std::string,
        boost::flyweights::set_factory<>, boost::flyweights::no_locking>;
    std::vector<string_type> countries;
    for (int i = 0; i < 500; ++i)
        countries.emplace_back("Germany");
    for (int i = 0; i < 500; ++i)
        countries.emplace_back("Netherlands");
}
