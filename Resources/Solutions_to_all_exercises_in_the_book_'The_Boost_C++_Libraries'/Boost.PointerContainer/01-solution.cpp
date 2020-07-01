#include <boost/ptr_container/ptr_vector.hpp>
#include <algorithm>
#include <string>
#include <iterator>
#include <iostream>
#include <ios>

struct animal
{
    std::string name;
    int legs;
    bool has_tail;
};

std::ostream &operator<<(std::ostream &os, const animal &a)
{
    return os << a.name << ',' << a.legs << ',' << std::boolalpha << a.has_tail << '\n';
}

int main()
{
    boost::ptr_vector<animal> animals;
    animals.push_back(new animal{ "cat", 4, true });
    animals.push_back(new animal{ "spider", 8, false });
    animals.push_back(new animal{ "shark", 0, false });
    animals.sort([](const animal &lhs, const animal &rhs) { return lhs.legs < rhs.legs; });
    std::copy(animals.begin(), animals.end(), std::ostream_iterator<animal>(std::cout));
}
