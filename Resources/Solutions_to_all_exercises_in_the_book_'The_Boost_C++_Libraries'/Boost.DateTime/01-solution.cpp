#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>

int main()
{
    boost::gregorian::date today = boost::gregorian::day_clock::universal_day();
    boost::gregorian::date christmas{ today.year(), 12, 24 };
    std::cout << christmas.day_of_week() << '\n';
    boost::gregorian::day_iterator it{ christmas };
    ++it;
    std::cout << it->day_of_week() << '\n';
    ++it;
    std::cout << it->day_of_week() << '\n';
}
