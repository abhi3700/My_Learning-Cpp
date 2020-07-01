#include <boost/algorithm/cxx11/iota.hpp>
#include <boost/algorithm/hex.hpp>
#include <array>
#include <iterator>
#include <iostream>

int main()
{
    std::array<char, 6> a;
    boost::algorithm::iota(a, 51);
    boost::algorithm::unhex(a, std::ostream_iterator<char>(std::cout));
}
