#include <boost/scope_exit.hpp>
#include <string>
#include <cstdio>

void write_to_file(const std::string &s)
{
    std::FILE *file = std::fopen("01-solution-test.txt", "a");
    BOOST_SCOPE_EXIT(file)
    {
        std::fclose(file);
    } BOOST_SCOPE_EXIT_END
    std::fprintf(file, s.c_str());
}

int main()
{
    write_to_file("Hello, ");
    write_to_file("world!");
}
