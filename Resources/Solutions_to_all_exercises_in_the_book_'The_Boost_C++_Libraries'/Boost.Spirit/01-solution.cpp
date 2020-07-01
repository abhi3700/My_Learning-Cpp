#include <boost/spirit/include/qi.hpp>
#include <boost/fusion/include/std_tuple.hpp>
#include <vector>
#include <tuple>
#include <iostream>

using namespace boost::spirit;

template <typename Iterator, typename Skipper>
struct calculator : qi::grammar<Iterator, std::tuple<int, std::vector<std::tuple<char, int>>>(), Skipper>
{
    calculator() : calculator::base_type{ calc }
    {
        op = qi::ascii::char_("+-");
        rhs = op >> qi::int_;
        calc = qi::int_ >> *rhs;
    }

    qi::rule<Iterator, char(), Skipper> op;
    qi::rule<Iterator, std::tuple<char, int>(), Skipper> rhs;
    qi::rule<Iterator, std::tuple<int, std::vector<std::tuple<char, int>>>(), Skipper> calc;
};

int main()
{
    std::string s;
    std::getline(std::cin, s);
    auto it = s.begin();
    calculator<std::string::iterator, ascii::space_type> c;
    std::tuple<int, std::vector<std::tuple<char, int>>> r;
    if (qi::phrase_parse(it, s.end(), c, ascii::space, r))
    {
        int i = std::get<0>(r);
        for (auto rhs : std::get<1>(r))
        {
            if (std::get<0>(rhs) == '+')
                i += std::get<1>(rhs);
            else
                i -= std::get<1>(rhs);
        }
        std::cout << i << '\n';
    }
}
