#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <iostream>
#include <ios>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " <filename>\n";
        return 0;
    }

    boost::property_tree::ptree pt;
    boost::property_tree::read_json(argv[1], pt);

    for (const auto &child : pt.get_child("animals"))
    {
        std::cout << child.second.get_child("name").get_value<std::string>() << '\n';
        if (pt.get("log.all", false))
        {
            std::cout << child.second.get_child("legs").get_value<int>() << '\n';
            std::cout << std::boolalpha << child.second.get_child("has_tail").get_value<bool>() << '\n';
        }
    }
}
