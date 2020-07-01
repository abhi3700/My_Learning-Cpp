#include <boost/spirit/include/qi.hpp>
#include <boost/fusion/include/std_tuple.hpp>
#include <boost/variant.hpp>
#include <vector>
#include <tuple>
#include <iostream>

using namespace boost::spirit;

using fraction_t = std::tuple<int, int>;
using number_t = boost::variant<fraction_t, double>;
using op_t = char;
using rhs_t = std::tuple<op_t, number_t>;
using calc_t = std::tuple<number_t, std::vector<rhs_t>>;

template <typename Iterator, typename Skipper>
struct calculator : qi::grammar<Iterator, calc_t(), Skipper>
{
    calculator() : calculator::base_type{ calc }
    {
        fraction = qi::int_ >> '/' >> qi::int_;
        number = fraction | qi::double_;
        op = qi::ascii::char_("+-");
        rhs = op >> number;
        calc = number >> *rhs;
    }

    qi::rule<Iterator, fraction_t(), Skipper> fraction;
    qi::rule<Iterator, number_t(), Skipper> number;
    qi::rule<Iterator, op_t(), Skipper> op;
    qi::rule<Iterator, rhs_t(), Skipper> rhs;
    qi::rule<Iterator, calc_t(), Skipper> calc;
};

struct get_number : boost::static_visitor<double>
{
    double operator()(double d) const
    {
        return d;
    }

    double operator()(const fraction_t &f) const
    {
        return static_cast<double>(std::get<0>(f)) / std::get<1>(f);
    }
};

int main()
{
    std::string s;
    std::getline(std::cin, s);
    auto it = s.begin();
    calculator<std::string::iterator, ascii::space_type> c;
    calc_t r;
    if (qi::phrase_parse(it, s.end(), c, ascii::space, r))
    {
        double d = boost::apply_visitor(get_number{}, std::get<0>(r));
        for (auto rhs : std::get<1>(r))
        {
            if (std::get<0>(rhs) == '+')
                d += boost::apply_visitor(get_number{}, std::get<1>(rhs));
            else
                d -= boost::apply_visitor(get_number{}, std::get<1>(rhs));
        }
        std::cout << d << '\n';
    }
}
