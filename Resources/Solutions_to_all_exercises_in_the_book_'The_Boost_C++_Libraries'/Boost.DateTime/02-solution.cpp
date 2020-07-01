#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>

int main()
{
    boost::gregorian::date birthday{ 1970, 1, 1 };
    boost::gregorian::date today = boost::gregorian::day_clock::universal_day();
    boost::gregorian::date_duration dd = today - birthday;
    std::cout << dd.days() << '\n';
}
