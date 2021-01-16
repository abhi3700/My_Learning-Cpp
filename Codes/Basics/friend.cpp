/*
		Use of `friend` keyword
		- The global operator function is made friend of this class so 
			that it can access private members
*/

#include <iostream>

class complex
{
private:
	int real, imag;

public:
	complex( int r=0, int i=0) : real(r), imag(i) {} 

	void print() {
		std::cout << real << " + " << imag << "i" << "\n";
	}

	friend complex operator +(const complex& c1, const complex& c2) {
		return complex(c1.real + c2.real, c1.imag + c2.imag);
	}


	// complex operator +(
	// 	// const complex& c1
	// 	complex const &c1
	// 	) 
	// {
	// 	complex res;
	// 	res.real = real + c1.real;
	// 	res.imag = imag + c1.imag;

	// 	return res;
	// }
};

int main() {
	complex c1(10, 5), c2(2, 4);
	auto c3 = c1 + c2;
	c3.print();

	return 0;
}

// *
/*#include<iostream> 
using namespace std; 

class Complex { 
private: 
	int real, imag; 
public: 
	Complex(int r = 0, int i =0) {real = r; imag = i;} 
	void print() { cout << real << " + i" << imag << endl; } 

// The global operator function is made friend of this class so 
// that it can access private members 
friend Complex operator + (Complex const &, Complex const &); 
}; 


Complex operator + (Complex const &c1, Complex const &c2) 
{ 
	return Complex(c1.real + c2.real, c1.imag + c2.imag); 
} 


int main() 
{ 
	Complex c1(10, 5), c2(2, 4); 
	Complex c3 = c1 + c2; // An example call to "operator+" 
	c3.print();

	return 0; 
} 
*/