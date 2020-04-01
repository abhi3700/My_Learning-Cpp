/**
 * @brief Process the contents of an input stream line-by-line.
 * @details Process the contents of an input stream line-by-line.
 * @link https://cpppatterns.com/patterns/read-line-by-line.html
 */
#include <iostream>
#include <sstream>
#include <string>

int main() {
  std::istringstream stream{
                            "Abhijit is \n"
                            "a good \n"
                            "EOSIO Developer\n"
                            };
  
  std::string line;
  
  while(std::getline( stream, line )) {
      // Process line
      std::cout << line << std::endl;
  }

  return 0;
}
