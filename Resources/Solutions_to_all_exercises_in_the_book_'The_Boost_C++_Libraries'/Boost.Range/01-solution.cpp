#include <boost/range/irange.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/range/algorithm.hpp>
#include <iterator>
#include <iostream>

int main()
{
    auto filtered_range = boost::adaptors::filter(boost::irange(0, 100), [](int i) { return i % 2; });
    boost::range::copy(filtered_range, std::ostream_iterator<int>(std::cout, ","));
}
