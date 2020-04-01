#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>
#include <iostream>
#include <string>

using namespace boost::multi_index;
using namespace std;

struct animal
{
	string name;
	uint64_t legs;
};

typedef multi_index_container<
	animal,
	indexed_by<
		hashed_non_unique<
			member<
				animal, string, &animal::name
			>
		>,
		hashed_non_unique<
			member<
				animal, uint64_t, &animal::legs
			>
		>
	>
> animal_multi;

int main() {
	animal_multi animals;
	animals.insert({"cat", 4});
	animals.insert({"pigeon", 2});
	animals.insert({"duck", 2});
	animals.insert({"whale", 0});

	cout << animals.count("pigeon") << endl;

	

	return 0;
} 

