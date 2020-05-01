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
* `push_back()`
* `pop_back()`
* insert at random position by __iterator (position)__

##### List
* `push_front()`
* `push_back()`
* `push_back()`
* `pop_back()`
* insert at random position by __value__

##### Deque
* `push_front()`
* `push_back()`
* `push_back()`
* `pop_back()`
* insert at random position by __iterator (position)__
* `push_front` (from boost lib) [Example coding](https://github.com/abhi3700/cpp-playground/blob/master/libs/boost/examples/assign/assign_deque.cpp)
```cpp
std::deque<pair_type> d1;
push_front(d1) ("ram", "sita") ("abhi", "adi") ("laxman", "kalki");
...
...
// display the output
for(auto& [key, val] : d1) {
	std::cout << "key = " << key << ", val = " << val << std::endl;
}

```

	> NOTE:

	> - `deque` is best sequence container out of all. <br/>
	
	> - "Memory is allocated differently for vectors and queues. A vector always occupies a contiguous region of memory. If a vector grows too large, it may need to be moved to a new location where it will fit. A deque, on the other hand, can be stored in several non-contiguous areas; it is segmented. A member function, capacity(), returns the largest number of elements a vector can store without being moved, but capacity() isn’t defined for deques because they don’t need to be moved." <--- as quotes in __Book: OOP in C++__

#### Associative Container
##### Map
* `insert` (from boost lib) [Example code](https://github.com/abhi3700/cpp-playground/blob/master/libs/boost/examples/assign/assign_map.cpp)
* display the output
```cpp
for (auto& [key, val] : map_var) {
	std::cout << "key = " << key << ", val = " << val << std::endl;
}
```


### Algorithms
### Iterators
