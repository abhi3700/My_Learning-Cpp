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
std::list<string> l1 = list_of("abhi") ("jdsf") ("ndbjcsd") ("ndbsjv");

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
##### Map
* `insert` (from boost lib) [Example code](https://github.com/abhi3700/cpp-playground/blob/master/libs/boost/examples/assign/assign_insert_op.cpp)
* display the output
```cpp
// PREVIEW
for (auto& [key, val] : map_var) {
	std::cout << "key = " << key << ", val = " << val << std::endl;
}
```


### Algorithms
### Iterators
