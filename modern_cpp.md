# Modern C++ (C++11 & beyond)
## Old vs New
* Variable Initialization
	- `int a = 1;`
	- `int a{1};`
	- print using `	std::cout << a << std::endl;`
* String Initialization
	- `string s = "abhijit";`
	- `string s{"abhijit"};`
	- print using `	std::cout << s << std::endl;`
* Vector Initialization
	- 1
```cpp
vector <int> v;
v.push_back(10);
v.push_back(20);
```
	- 2
```cpp
vector <int> v{10,20};
```
	- print using
```cpp
//print
std::cout << v.at(0) << std::endl;		// print 0th i.e. 1st element
std::cout << v.at(1) << std::endl;		// print 1st i.e. 2nd element
std::cout << v.at(2) << std::endl;		// Gives Error: 'std::out_of_range'
```
* Map initialization
	- 1
```cpp
map<string, string> capitals = {
	{"UK", "london"}, {"India", "Delhi"}
};
```

	- 2
```cpp
map<string, string> capitals {
	{"UK", "london"}, {"India", "Delhi"}
};
```
	- print using
```cpp
for(auto&& i : capitals) {
	std::cout << i.first << ": " << i.second << std::endl;	
}
```
* Struct Initialization
	- define struct
```cpp
struct Person
{
	string name;
	int age;
};
```
	- 1
```cpp
Person p = {"abhijit", 27};
```
	- 2
```cpp
Person p{"abhijit", 27};
```
	- print using
```cpp
std::cout << p.name << ", " << p.age << std::endl;
```
* Namespace Initialization
	- 1
```cpp
namespace A {
	namespace B {
		namespace C {
			void bar(){};
		}
	}
}
```
	- 2
```cpp
namespace A::B::C {
	void bar(){};
}
```
	- calling in main function
```cpp
A::B::C::bar();
```