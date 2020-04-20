# C++ Guide (A direct reference to C++ concepts)

## C++ Progamming Basics

## Loops and Decisions

## Structures

## Functions

## Objects and Classes

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

	> NOTE:

	> - `deque` is best sequence container out of all. <br/>
	
	> - "Memory is allocated differently for vectors and queues. A vector always occupies a contiguous region of memory. If a vector grows too large, it may need to be moved to a new location where it will fit. A deque, on the other hand, can be stored in several non-contiguous areas; it is segmented. A member function, capacity(), returns the largest number of elements a vector can store without being moved, but capacity() isn’t defined for deques because they don’t need to be moved." <--- as quotes in __Book: OOP in C++__


### Algorithms
### Iterators
