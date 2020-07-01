#include <boost/utility/enable_if.hpp>
#include <boost/type_traits.hpp>
#include <boost/type_index.hpp>
#include <string>
#include <iostream>

template <class T>
typename boost::enable_if_c<boost::has_post_increment<T>::value>::type print_has_post_increment()
{
    std::cout << boost::typeindex::type_id<T>().pretty_name() << " has a post increment operator.\n";
}

template <class T>
typename boost::enable_if_c<!boost::has_post_increment<T>::value>::type print_has_post_increment()
{
    std::cout << boost::typeindex::type_id<T>().pretty_name() << " has NO post increment operator.\n";
}

int main()
{
    print_has_post_increment<int>();
    print_has_post_increment<long>();
    print_has_post_increment<std::string>();
}
