/*
	deque operations:
	- front insert
	- back insert
	- front delete
	- back delete
	- read front element
	- read last element
*/

#include <iostream>
#include <deque>

int main() {
	std::deque<int> d;
	d.push_back(4);		// {4}
	d.push_back(5);		// {4, 5}
	d.push_back(45);	// {4, 5, 45}
	d.push_back(32);	// {4, 5, 45, 32}
	d.push_back(15);	// {4, 5, 45, 32, 15}
	std::cout << "The list is: \n" << "\n";
	for (std::deque<int>::iterator i = d.begin(); i != d.end(); ++i)
	{
		std::cout << *i << "\n";
	}
	d.pop_back();		// {4, 5, 45, 32}
	d.pop_front();		// {5, 45, 32}
	std::cout << "Now, The list is: \n" << "\n";
	for (std::deque<int>::iterator i = d.begin(); i != d.end(); ++i)
	{
		std::cout << *i << "\n";
	}

	std::cout << "The front element is: " << d.front() << "\n";
	std::cout << "The last element is: " << d.back() << "\n";
	
	return 0;
}
 
