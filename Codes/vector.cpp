#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::pair;

int main() {
	// METHOD-1
	// A vector with elements of string type
	std::cout << "METHOD-1" << std::endl;
	vector<string> x  = {"abhijit", "raja", "priti"};
	for(auto&& i : x) {
		std::cout << i << std::endl;
	}
	std::cout << "\n";
	
	// METHOD-2
	// A vector with elements of pair type
	std::cout << "METHOD-2" << std::endl;
	vector<pair<int, string>> x_pair = {
							{1, "abhijit"},
							{23, "raja"},
							{45, "priti"}
	};
	for (std::vector<pair<int, string>>::iterator i = x_pair.begin(); i != x_pair.end(); ++i)
	{
		std::cout << i->first << ", " << i->second << std::endl;
	}
	return 0;

}

