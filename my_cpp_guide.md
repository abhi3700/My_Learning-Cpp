# C++ Guide (A direct reference to C++ concepts)

## C++ Progamming Basics

## Loops and Decisions

## Structures

## Functions

## Objects and Classes
### Constructors
* __NOTES:__
	- `set`
		+ M-1: paramterized constructor: E.g. `Test(int n): a(n) {}`
		+ M-2: create a set func: E.g.`set_var(int a)`
	- `get`
		+ M-1: create a set func: E.g.`get_var() {return a}`


#### Copy constructor
<details>
<summary><b>View code: </b></summary>

```cpp
#include <iostream>

class Test
{
	int a;

public:
	// default constructor
	Test() {
		a = 0;
	}

	// parameterized constructor
	Test(int n) {
		a = n;
	}

	// copy constructor
	Test (Test& obj){
		a = obj.a;
	}

	void print() {
		std::cout << a << std::endl;
	}
	
};

int main() {
	Test A(10), B(20);
	A.print();
	B.print();

// =================================
	A = Test(B);
	A.print();
	B.print();

	return 0;
}
```
</details>

## Arrays and Strings

## Operator Overloading

## Inheritance

## Pointers

## Virtual Functions

## Streams and Files

## STL
<p align="left">
  <img src="./images/stl_diagram.jpg" alt="C++ Sequence Containers" width="" height="">
</p>

### Containers
<p align="left">
  <img src="./images/cpp_sequence_containers.jpg" alt="C++ Sequence Containers" width="" height="">
</p>

#### Sequence Container
##### Vector
* `size`
* `push_back()`
* `pop_back()`
* insert at random position by __iterator (position)__
* display all the elements	[Example code](https://github.com/abhi3700/cpp-playground/blob/master/libs/boost/examples/assign/assign_+=_op.cpp)
```cpp
// M-1
for (std::vector<int>::iterator i = v1.begin(); i != v1.end(); ++i)
{
	std::cout << *i << std::endl;
}

// M-2
for (int i = 0; i < v1.size(); ++i)
{
	std::cout << v1[i] << std::endl;
	// std::cout << v1.at(i) << std::endl;
}
```

##### List
* `size`
* `push_front()`
* `push_back()`
* `push_back()`
* `pop_back()`
* insert at random position by __value__
* display all the elements
	- assign elements as per boost assign [Example code](https://github.com/abhi3700/cpp-playground/blob/master/libs/boost/examples/assign/assign_listof_op.cpp)
```cpp
std::list<int> l1 = list_of(1) (21) (34) (55) (67);
std::list<int>::iterator it = l1.begin();

advance(it, 2);		// now positioned to '34'
advance(it, -1);		// now positioned to '21'
std::cout << *it << std::endl;		// '21'

// display the output
for (std::list<string>::iterator i = l1.begin(); i != l1.end(); ++i)
{
	std::cout << *i << std::endl;
}

```

##### Deque
* `size`
* `push_front()`
* `push_back()`
* `push_back()`
* `pop_back()`
* insert at random position by __iterator (position)__
* `push_front` (from boost lib) [Example coding](https://github.com/abhi3700/cpp-playground/blob/master/libs/boost/examples/assign/assign_pushfront_op.cpp)
	- access elements `d1.front().first == "laxman"` or `d1[0].first == "laxman"`
```cpp
// PREVIEW
std::deque<pair_type> d1;
push_front(d1) ("ram", "sita") ("abhi", "adi") ("laxman", "kalki");
...
...
// display the output
for(auto& [key, val] : d1) {
	std::cout << "key = " << key << ", val = " << val << std::endl;
}

```

##### Stack (LIFO Queue)
* `size`
* `top`
* `push`
* `pop`
* can't be inserted at a position. Basically, all the elements are stacked one over the other.
* display all the elements
	- assign using boost lib [Example code](https://github.com/abhi3700/cpp-playground/blob/master/libs/boost/examples/assign/assign_listof_op.cpp)
```cpp
// PREVIEW
std::stack<string> s1 = list_of("abhi") ("adi") ("victor") ("shyam")
while(!s1) {
    std::cout << s1.top() << std::endl;
    s1.pop()
}
```


	> NOTE:

	> - `deque` is best sequence container out of all. <br/>
	
	> - "Memory is allocated differently for vectors and queues. A vector always occupies a contiguous region of memory. If a vector grows too large, it may need to be moved to a new location where it will fit. A deque, on the other hand, can be stored in several non-contiguous areas; it is segmented. A member function, capacity(), returns the largest number of elements a vector can store without being moved, but capacity() isn’t defined for deques because they don’t need to be moved." <--- as quotes in __Book: OOP in C++__

#### Associative Container
##### Set
* <u>define:</u> Sets are a type of associative containers in which each element has to be unique, because the value of the element identifies it.

> NOTE: 
> - The value of the element __cannot be modified__ once it is added to the set, 
> - though it is possible to remove and add the modified value of that element.

* Some basic functions associated with Set:
	- `begin()` – Returns an iterator to the first element in the set.
	- `end()` – Returns an iterator to the theoretical element that follows last element in the set.
	- `size()` – Returns the number of elements in the set.
	- `max_size()` – Returns the maximum number of elements that the set can hold.
	- `empty()` – Returns whether the set is empty.
* a list of keys (of any type: int, string)
* print all the elements [Example code](https://github.com/abhi3700/cpp-playground/blob/master/base/set.cpp). Here is a preview:
```cpp
std::set<int> s1 = {1, 2, 3};
for (std::set<int>::iterator i = s1.begin(); i != s1.end(); ++i)
{
	std::cout << *i << std::endl;
}
```
* access each element by position
```cpp
std::set<int>::iterator = s1.begin()
advance(it, 2)		// set at position 2 i.e 3rd element
```

##### Multi-Set
* <u>define:</u> similar to set, with an exception that __multiple elements can have same values__.
* Some Basic Functions associated with multiset:
	- `begin()` – Returns an iterator to the first element in the multiset
	- `end()` – Returns an iterator to the theoretical element that follows last element in the multiset
	- `size()` – Returns the number of elements in the multiset
	- `max_size()` – Returns the maximum number of elements that the multiset can hold
	- `empty()` – Returns whether the multiset is empty

##### Map
* <u>define:</u> Each element has a key value and a mapped value. 

> NOTE: No two mapped values can have same key values. 

* Some basic functions associated with Map:
	- `begin()` – Returns an iterator to the first element in the map
	- `end()` – Returns an iterator to the theoretical element that follows last element in the map
	- `size()` – Returns the number of elements in the map
	- `max_size()` – Returns the maximum number of elements that the map can hold
	- `empty()` – Returns whether the map is empty
	- `pair insert(keyvalue, mapvalue)` – Adds a new element to the map
	- `erase(iterator position)` – Removes the element at the position pointed by the iterator
	- `erase(const g)` – Removes the key value ‘g’ from the map
	- `clear()` – Removes all the elements from the map
* `insert` (from boost lib) [Example code](https://github.com/abhi3700/cpp-playground/blob/master/libs/boost/examples/assign/assign_insert_op.cpp)
* display the output
```cpp
// PREVIEW
for (auto& [key, val] : map_var) {
	std::cout << "key = " << key << ", val = " << val << std::endl;
}
```

##### Multi-Map
* <u>define:</u> is just like Map, except for _"multiple elements can have same keys"_.
* `insert` (from boost lib) [Example code](https://github.com/abhi3700/cpp-playground/blob/master/libs/boost/examples/assign/assign_insert_op.cpp)
* Some Basic Functions associated with multimap:
	- `begin()` – Returns an iterator to the first element in the multimap
	- `end()` – Returns an iterator to the theoretical element that follows last element in the multimap
	- `size()` – Returns the number of elements in the multimap
	- `max_size()` – Returns the maximum number of elements that the multimap can hold
	- `empty()` – Returns whether the multimap is empty
	- `pair<int,int> insert(keyvalue,multimapvalue)` – Adds a new element to the multimap


#### Sequences
##### Pair
* a sequence of 2 elements
* [Example code 2](https://github.com/abhi3700/cpp-playground/blob/master/base/pair.cpp)
```cpp
std::pair<string, int> p1 = {"abhijit", 102};
p1.first;		// abhijit
p1.second;	// 102
```

##### Tuple
* a sequence of any number of elements
* [Example code 1](https://github.com/abhi3700/cpp-playground/blob/master/base/tuple_3.cpp), [Example code 2](https://github.com/abhi3700/cpp-playground/blob/master/base/tuple_5.cpp). Below is a small preview:
```cpp
std::tuple<string, int, int> t1 = {"abhijit", 102, 2423432};

std::cout << std::get<0>(t1) << std::endl;
std::cout << std::get<1>(t1) << std::endl;
std::cout << std::get<2>(t1) << std::endl;
```

#### Miscellaneous
##### Vector
* each element of 1
	- insertion:
		+ `std::vector<string> v1 += 1, 2, 33, 45, 64;`
		+ `std::vector<string> v1 = list_of ("abhijit") ("adi") ("victor")`
	- access:
	- print:
	- search: 
* each element of pair
	- insertion:
		+ `std::vector<std::pair<int, string>> v1 = list_of<std::pair<int, string>> (1, "abhijit") (4, "adi") (6, "victor")`
		+ `std::vector<std::pair<int, string>> v1 = map_list_of (1, "abhijit") (4, "adi") (6, "victor")`
	- access:
	- print:
	- search: 
* each element of tuple
	- insertion: 
		+ `std::vector<boost::tuple<int, string, int>> v1 = list_of<boost::tuple<int, string, int>> (1, "abhijit", 203) (4, "adi", 204) (6, "victor", 2035)`
		+ `std::vector<boost::tuple<int, string, int>> v1 = tuple_list_of (1, "abhijit", 203) (4, "adi", 204) (6, "victor", 2035)`
	- access:
```cpp
boost::get<0>(v[i])			// 1st tuple val of ith element of vector v	
boost::get<1>(v[i])			// 2nd tuple val of ith element of vector v	
boost::get<2>(v[i])			// 3rd tuple val of ith element of vector v	
```
	- print:
	- search: 

##### List
* List of pair:
	- insertion: `std::list<>`



#### SUMMARY
* __Insertion__
	- All containers have different insertion/assignment methods: `insert`, `list_of`, `map_list_of`, `+=`, `push_front`, `push_back`,....
* __Access__
	- by array. E.g. `v[i]`
	- by `at` function. E.g. `v.at(i)`
	- by _iterator_ technique: `*it`
```cpp
std::vector<int> v1;
std::vector<int>::iterator it = v1.begin();
std::advance(it, 2)   // from pos: 0 to 2
std::advance(it, -1)   // from pos: 2 to 1
std::cout << *it << std::endl;
```
* __Search__
	- by algorithm: `find`

### Algorithms
### Iterators
