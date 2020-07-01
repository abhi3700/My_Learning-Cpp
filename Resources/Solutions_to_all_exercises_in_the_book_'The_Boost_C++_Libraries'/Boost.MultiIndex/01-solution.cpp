#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>
#include <string>
#include <vector>
#include <iostream>

struct animal
{
    std::string name;
    int legs;
    bool has_tail;
};

class animals_container
{
public:
    void add(animal a)
    {
        animals.insert(a);
    }

    const animal *find_by_name(const std::string &name) const
    {
        auto &name_index = animals.get<0>();
        auto it = name_index.find(name);
        return (it != name_index.end()) ? &*it : nullptr;
    }

    std::vector<animal> find_by_legs(int from, int to) const
    {
        auto &legs_index = animals.get<1>();
        auto it = legs_index.lower_bound(from);
        auto end = legs_index.upper_bound(to);
        std::vector<animal> result;
        for (; it != end; ++it)
            result.push_back(*it);
        return result;
    }

    std::vector<animal> find_by_tail(bool has_tail) const
    {
        auto &tail_index = animals.get<2>();
        auto pair = tail_index.equal_range(has_tail);
        std::vector<animal> result;
        for (auto it = pair.first; it != pair.second; ++it)
            result.push_back(*it);
        return result;
    }

private:
    using animal_multi = boost::multi_index::multi_index_container<
        animal,
        boost::multi_index::indexed_by<
            boost::multi_index::hashed_unique<
                boost::multi_index::member<
                    animal, std::string, &animal::name
                >
            >,
            boost::multi_index::ordered_non_unique<
                boost::multi_index::member<
                    animal, int, &animal::legs
                >
            >,
            boost::multi_index::hashed_non_unique<
                boost::multi_index::member<
                    animal, bool, &animal::has_tail
                >
            >
        >
    >;

    animal_multi animals;
};

int main()
{
    animals_container animals;
    animals.add({ "cat", 4, true });
    animals.add({ "ant", 6, false });
    animals.add({ "spider", 8, false });
    animals.add({ "shark", 0, false });

    const animal *a = animals.find_by_name("cat");
    if (a)
        std::cout << "cat has " << a->legs << " legs\n";

    auto animals_with_6_to_8_legs = animals.find_by_legs(6, 9);
    for (auto a : animals_with_6_to_8_legs)
        std::cout << a.name << " has " << a.legs << " legs\n";

    auto animals_without_tail = animals.find_by_tail(false);
    for (auto a : animals_without_tail)
        std::cout << a.name << " has no tail\n";
}
