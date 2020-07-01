#include <boost/bimap.hpp>
#include <boost/bimap/multiset_of.hpp>
#include <boost/bimap/support/lambda.hpp>
#include <boost/optional.hpp>
#include <string>
#include <vector>
#include <iostream>

struct animal
{
    std::string name;
    int legs;

    animal(std::string n, int l) : name(n), legs(l) {}
};

class animals_container
{
public:
    void add(animal a)
    {
        animals.insert({ a.name, a.legs });
    }

    boost::optional<animal> find_by_name(const std::string &name) const
    {
        auto it = animals.left.find(name);
        return boost::make_optional<animal>(it != animals.left.end(), { it->first, it->second });
    }

    std::vector<animal> find_by_legs(int from, int to) const
    {
        auto pair = animals.right.range(from <= boost::bimaps::_key, boost::bimaps::_key < to);
        std::vector<animal> result;
        for (auto it = pair.first; it != pair.second; ++it)
            result.push_back({ it->second, it->first });
        return result;
    }

private:
    using animals_bimap = boost::bimap<std::string, boost::bimaps::multiset_of<int>>;
    animals_bimap animals;
};

int main()
{
    animals_container animals;
    animals.add({ "cat", 4 });
    animals.add({ "ant", 6 });
    animals.add({ "spider", 8 });
    animals.add({ "shark", 0 });

    auto shark = animals.find_by_name("shark");
    if (shark)
        std::cout << "shark has " << shark->legs << " legs\n";

    auto animals_with_4_to_6_legs = animals.find_by_legs(4, 7);
    for (auto animal : animals_with_4_to_6_legs)
        std::cout << animal.name << " has " << animal.legs << " legs\n";
}
