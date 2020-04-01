 /**
 * @brief A random number generator for integer number.
 * @description it can be used for rolling dice, OTP generation purposes.
 */

#include <iostream>
#include <random>

int main() {
	std::random_device random_device;
	std::mt19937 random_engine{random_device()};
	std::uniform_int_distribution<int> rand_distribution{1000, 9999};	// define min, max
	int otp_num = die_distribution(random_engine);

	// Display OTP number randomly
	std::cout << otp_num << std::endl;

	return 0;

}
