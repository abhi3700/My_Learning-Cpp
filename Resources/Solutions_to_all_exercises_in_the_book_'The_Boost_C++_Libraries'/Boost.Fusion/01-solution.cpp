#include <boost/fusion/algorithm.hpp>
#include <boost/fusion/adapted.hpp>
#include <boost/math/constants/constants.hpp>
#include <iostream>

struct animal
{
    std::string name;
    int legs;
    bool has_tail;
};

BOOST_FUSION_ADAPT_STRUCT(animal,
    (std::string, name)
    (int, legs)
    (bool, has_tail)
)

struct important_numbers
{
    const float pi = boost::math::constants::pi<float>();
    const double e = boost::math::constants::e<double>();
};

BOOST_FUSION_ADAPT_STRUCT(important_numbers,
    (float, pi)
    (double, e)
)

template <class T>
void debug(const T &t)
{
    boost::fusion::for_each(t, [](auto e) { std::cout << e << '\n';  });
}

int main()
{
    animal a{ "cat", 4, true };
    debug(a);

    important_numbers in;
    debug(in);
}
