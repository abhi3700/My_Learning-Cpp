# C++ Guide (A direct reference to C++ concepts)

## Basics
* `pragma`
	- `#pragma once` used to remove the duplicate header files (if included), during a compilation.

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
* <u>define:</u>
	- Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container. 
	- Vector elements are placed in __contiguous__ storage _so that they can be accessed and traversed using iterators_. 

> NOTE:
> - In vectors, data is inserted at the end. 
> - Inserting at the end takes differential time, as sometimes there may be a need of extending the array. 
> - Removing the last element takes only constant time because no resizing happens. 
> - Inserting and erasing at the beginning or in the middle is linear in time.

* Certain functions associated with the vector are:
	- <u>Iterators</u>
		+ `begin()` – Returns an iterator pointing to the first element in the vector
		+ `end()` – Returns an iterator pointing to the theoretical element that follows the last element in the vector
		+ `rbegin()` – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
		+ `rend()` – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
		+ `cbegin()` – Returns a constant iterator pointing to the first element in the vector.
		+ `cend()` – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
		+ `crbegin()` – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
		+ `crend()` – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)* `size`
	- <u>Capacity</u>
		+ `size()` – Returns the number of elements in the vector.
		+ `max_size()` – Returns the maximum number of elements that the vector can hold.
		+ `capacity()` – Returns the size of the storage space currently allocated to the vector expressed as number of elements.
		+ `resize(n)` – Resizes the container so that it contains ‘n’ elements.
		+ `empty()` – Returns whether the container is empty.
		+ `shrink_to_fit()` – Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
		+ `reserve()` – Requests that the vector capacity be at least enough to contain n elements.* `push_back()`
	- <u>Element access</u>
		+ `reference operator [g]` – Returns a reference to the element at position ‘g’ in the vector
		+ `at(g)` – Returns a reference to the element at position ‘g’ in the vector
		+ `front()` – Returns a reference to the first element in the vector
		+ `back()` – Returns a reference to the last element in the vector
		+ `data()` – Returns a direct pointer to the memory array used internally by the vector to store its owned elements.
	- <u>Modifiers</u>
		+ `assign()` – It assigns new value to the vector elements by replacing old ones
		+ `push_back()` – It push the elements into a vector from the back
		+ `pop_back()` – It is used to pop or remove elements from a vector from the back.
		+ `insert()` – It inserts new elements before the element at the specified position
		+ `erase()` – It is used to remove elements from a container from the specified position or range.
		+ `swap()` – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
		+ `clear()` – It is used to remove all the elements of the vector container
		+ `emplace()` – It extends the container by inserting new element at position
		+ `emplace_back()` – It is used to insert a new element into the vector container, the new element is added to the end of the vector
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
* <u>define:</u> 
	- Lists are sequence containers that allow __non-contiguous__ memory allocation. 
	- As compared to vector, list has slow traversal, but once a position has been found, insertion and deletion are quick.
	- Normally, when we say a List, we talk about doubly linked list.
	- For implementing a singly linked list, we use forward list.
* Functions used with List:
	- `front()` – Returns the value of the first element in the list.
	- `back()` – Returns the value of the last element in the list .
	- `push_front(g)` – Adds a new element ‘g’ at the beginning of the list .
	- `push_back(g)` – Adds a new element ‘g’ at the end of the list.
	- `pop_front()` – Removes the first element of the list, and reduces size of the list by 1.
	- `pop_back()` – Removes the last element of the list, and reduces size of the list by 1
	- `list::begin()` and `list::end()` in C++ STL– begin() function returns an iterator pointing to the first element of the list
	- `end()` – end() function returns an iterator pointing to the theoretical last element which follows the last element.
	- list `rbegin()` and `rend()` function in C++ STL– rbegin() returns a reverse iterator which points to the last element of the list. rend() returns a reverse iterator which points to the position before the beginning of the list.
	- list `cbegin()` and `cend()` function in C++ STL– cbegin() returns a constant random access iterator which points to the beginning of the list. cend() returns a constant random access iterator which points to the end of the list.
	- list `crbegin()` and `crend()` function in C++ STL– crbegin() returns a constant reverse iterator which points to the last element of the list i.e reversed beginning of container. crend() returns a constant reverse iterator which points to the theoretical element preceding the first element in the list i.e. the reverse end of the list.
	- `empty()` – Returns whether the list is empty(1) or not(0).
	- `insert()` – Inserts new elements in the list before the element at a specified position.
	- `erase()` – Removes a single element or a range of elements from the list.
	- `assign()` – Assigns new elements to list by replacing current elements and resizes the list.
	- `remove()` – Removes all the elements from the list, which are equal to given element.
	- `list::remove_if()` in C++ STL– Used to remove all the values from the list that correspond true to the predicate or condition given as parameter to the function.
	- `reverse()` – Reverses the list.
	- `size()` – Returns the number of elements in the list.
	- `list resize()` function in C++ STL– Used to resize a list container.
	- `sort()` – Sorts the list in increasing order.
	- list `max_size()` function in C++ STL– Returns the maximum number of elements a list container can hold.
	- `list unique()` in C++ STL– Removes all duplicate consecutive elements from the list.
	- `list::emplace_front()` and `list::emplace_back()` in C++ STL– emplace_front() function is used to insert a new element into the list container, the new element is added to the beginning of the list. emplace_back() function is used to insert a new element into the list container, the new element is added to the end of the list.
	- `list::clear()` in C++ STL– clear() function is used to remove all the elements of the list container, thus making it size 0.
	- `list::operator=` in C++ STL– This operator is used to assign new contents to the container by replacing the existing contents.
	- `list::swap()` in C++ STL– This function is used to swap the contents of one list with another list of same type and size.
	- list `splice()` function in C++ STL– Used to transfer elements from one list to another.
	- list `merge()` function in C++ STL– Merges two sorted lists into one
	- list `emplace()` function in C++ STL– Extends list by inserting new element at a given position.* `size`
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
* <u>define:</u> 
	- Double ended queues are sequence containers with the feature of expansion and contraction on both the ends.
	- They are similar to vectors, but are more efficient in case of insertion and deletion of elements. Unlike vectors, __contiguous storage allocation may not be guaranteed__.
	- Double Ended Queues are basically an implementation of the data structure double ended queue. 
	- A queue data structure allows insertion only at the end and deletion from the front. 
	- This is like a queue in real life, wherein people are removed from the front and added at the back. 
	- Double ended queues are a special case of queues where insertion and deletion operations are possible at both the ends.
* Functions used with Deque:
	- The functions for __deque__ are same as __vector__, with an addition of `push` and `pop` operations for both front and back.
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
* <u>define:</u> 
	- A stack is a container adapter. It's sole purpose is to take some other type of container (a std::deque by default) and restrict the visible interface to that container to the few operations allowed for a stack. Among other things, that means that the only element in a stack that you can observe is the top.

	- If you need to observe other elements being stored, then you don't want to use a stack. The most obvious choice is to use a std::deque (or std::vector) directly. When you need stack-like access, you can use push_back, back and pop_back to get it. When you need access to internal elements, you can use begin(), end(), operator[], at(), etc., to get that.

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

* [set of 1 element](https://github.com/abhi3700/cpp-playground/blob/master/libs/boost/examples/container/stack_element_1.cpp)

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
