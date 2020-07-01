#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cctype>

int main()
{
    std::cout << "What is your name?\n";
    std::string name;
    std::getline(std::cin, name);

    boost::algorithm::trim(name);

    std::vector<std::string> names;
    boost::algorithm::split(names, name, boost::algorithm::is_space(), boost::algorithm::token_compress_on);

    std::for_each(names.begin(), names.end(), [](std::string &s) {
        boost::algorithm::to_lower(s);
        s[0] = std::toupper(s[0]);
    });

    std::cout << "Hello, " << boost::algorithm::join(names, " ") << "!\n";
}
