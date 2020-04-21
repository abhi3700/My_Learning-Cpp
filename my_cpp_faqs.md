# C/C++ FAQs
## General
* #### what is the simple difference b/w __gcc__ & __g++__?
	- gcc: used mainly for C files.
	- g++: used mainly for C++ files.
* #### Why header files are separate than source files?
	- C++ separate definitions from declarations
	- It improves compile time because the compiler only needs the declarations in the header files. Unnecessary recompilations for implementation changes are therefore mitigated. (Yet, C++ is one of the slowest languages to compile.)
	- It structurally separates the interface of a class from the implementation.
	- You can build against code just by having the headers and don’t need access to the source code for the definitions/implementations
	- The bigger your project becomes, the better it is to structure your code like this, otherwise, your code might become hard to follow.

* #### `#define` directive vs `const int a` vs `constexpr int a`?
	- `#define PI 3.14`
		+ not recommended in C++ (since C++11 especially)
		+ does not support data type
	- `const int a`
		+ `constexpr` variable/function can be parsed into `const` var.
		+ non-const variable can be parsed (OK), but __may__ be evaluated in run-time
		+ non-const func can be parsed (OK), but evaluated in run-time 
	- `constexpr int a`
		+ only constexpr function should be assigned, or else gives error (for non-const & const)
		+ const variable is acceptable as a assignment to a constexpr variable/function

<details>
<summary>View the code below to understand better: (const vs constexpr)</summary>

```cpp
#include <iostream>

// const function
const int square1(int var) {
	return var ^ 2;
} 

// constexpr function
constexpr int square2(int var) {
	return var ^ 2;
} 

// non-const/constexpr function
int square3(int var) {
	return var ^ 2;
} 


int main() {
	// define variables
	const int var1 = 34;
	constexpr int var2 = 23424;
	int var3 = 4234;						// warning: g++: warning note - 'int var3' is not const

	// Case 1: assigning `const func` to `const variable`
	const int var4 = square1(var1);			// OK
	const int var5 = square1(var2);			// OK
	const int var6 = square1(var3);			// OK, may be evaluated at run time (as the var is non-const)

	// Case 2: assigning `const` func to `constexpr variable`
	constexpr int var7 = square1(var1);		// Error, g++: error - call to non-'constexpr' function 'const int square1(int)'
	constexpr int var8 = square1(var2);		// Error, g++: error - call to non-'constexpr' function 'const int square1(int)'
	constexpr int var9 = square1(var3);		// Error, g++: error - call to non-'constexpr' function 'const int square1(int)' 

	// Case 3: assigning `constexpr func` to `const variable`
	const int var10 = square2(var1);		// OK 
	const int var11 = square2(var2);		// OK
	const int var12 = square2(var3);		// OK, may be evaluated at run time (as the var is non-const)

	// Case 4: assigning `constexpr func` to `constexpr variable`
	constexpr int var13 = square2(var1);	// OK
	constexpr int var14 = square2(var2);	// OK,
	constexpr int var15 = square2(var3);	// Error, g++: error - the value of 'var3' is not usable in a constant expression 

	// Case 5: assigning `func` to `const variable`
	const int var16 = square3(var1);		// OK, evaluated in run-time (as the func is non-const)
	const int var17 = square3(var2);		// OK, evaluated in run-time (as the func is non-const)
	const int var18 = square3(var3);		// OK, evaluated in run-time (as the func is non-const)

	// Case 6: assigning `func` to `constexpr variable`
	constexpr int var19 = square3(var1);	// Error, g++: error - call to non-'constexpr' function 'int square3(int)' 
	constexpr int var20 = square3(var2);	// Error, g++: error - call to non-'constexpr' function 'int square3(int)'
	constexpr int var21 = square3(var3);	// Error, g++: error - call to non-'constexpr' function 'int square3(int)'

	return 0;
}
```

</details>



## Bits, Bytes
* #### Why `bool` type is stored in bytes rather than bit?
	Variables of type `bool` can have only two possible values: `true` and `false`.
	In theory, a `bool` type requires only one bit (not byte) of storage, but in practice compilers often store them as bytes because a byte can be quickly accessed, while an individual bit must be extracted from a byte, which requires additional time.
  
* #### Why `.f` is appended to a float number?
	- Ans.: `.` indicates that the literal is a floating point number rather than an integer <br/>
				`f` suffix tells the compiler the literal should be of type float rather than the default double type used for floating point literals.
	- `3.f` is short for `3.0f` - the number 3.0 as a floating point literal of type float. <br/>
		`3.` is equivalent to `3.0`, it's a double. `f` following a number literal makes it a float.
	- A good example is
```cpp
#include <iostream>
#include <cstdio>

int main() {
    auto a = 1.2;
    if (a == 1.2f) {
        printf("a is a float number.\n");
    }
    else {
        printf("a is NOT a float number.\n");
    }

    auto b = 1.2f;

    if (b == 1.2f) {
        printf("b is a float number.\n");
    }
    else {
        printf("b is NOT a float number.\n");
    }

    return 0;
}
```
	__Output:__
```console
a is NOT a float number.
b is a float number.
```

* #### `double` vs `float` data type?
  - `double` is more specific in terms of numbers after decimal.
  - `f` appended to any number for float.

* #### `10/3` vs `10.0/3` vs `10/3.0` vs `10.0/3.0`?
  - except 1st which gives result as `3`, rest 3 cases are going to give result as `3.3333`

## Arrays
* #### Why array is not recommended for modern C/C++ programs? What is the alternative then?
	- `std::vector<int>` is much faster & flexible than array. Note than use `#include <vector>`
	- vector implemented as a dynamic table.
	- array needs to be defined, but vector has no limitation.
	- methods of adding new elements: `push_back`, `emplace_back`
	- FACT:
```cpp
vec.emplace_back(val); // (preferred, C++11)
vec.push_back();	// (historically known)
```
	- __default container__ to store collections of items of same type. E.g. many integers can be stored in a `vector<int>` 

## Functions
* #### `const string& var` vs `string var`
	- `void f1(const std::string& s);`      // Pass by reference-to-const
	- `void f2(const std::string* sptr);`   // Pass by pointer-to-const
	- `void f3(std::string s);`             // Pass by value
	- `void g1(std::string& s);`      // Pass by reference-to-non-const
	- `void g2(std::string* sptr);`   // Pass by pointer-to-non-const

> NOTE: In the pass by reference-to-const and pass by pointer-to-const cases, any attempts to change the caller’s std::string within the f() functions would be flagged by the compiler as an error at compile-time. This check is done entirely at compile-time: there is no run-time space or speed cost for the const. In the pass by value case (f3()), the called function gets a copy of the caller’s std::string. This means that f3() can change its local copy, but the copy is destroyed when f3() returns. In particular f3() cannot change the caller’s std::string object.

## Pointers
* #### Does *p++ increment p, or what it points to?
  The postfix ++ and -- operators essentially have higher precedence than the prefix unary operators. Therefore, *p++ is equivalent to *(p++); it increments p, and returns the value which p pointed to before p was incremented. To increment the value pointed to by p, use (*p)++ (or perhaps ++*p, if the evaluation order of the side effect doesn't matter).

  ```cpp
  #include <iostream>

  int main() {
    int c = 3;		
    int* p = &c;		// `int` is of 4 bytes => a difference of 4 letters in hexadecimal

    std::cout << p << ": " << *p++ << std::endl;
    std::cout << p << ": " << ++*p << std::endl;
    return 0;
  }
  ```

  Output:
  ```
  0x61fec8: 3
  0x61fecc: 805331454
  ```

* #### Difference b/w Pointer & Array
  - `sizeof`
    + array - returns the amount of memory used by all elements in array.
    + pointer - only returns the amount of memory used by the pointer variable itself.
  - `& operator`
    + array - an alias for &array[0] and returns the address of the first element in array.
    + pointer - returns the address of pointer
  - `string initialization of character`
    + array - `char array[] = "abc"` sets the first four elements in arrayy to 'a', 'b', 'c', and '\0'
    + pointer - `char* pointer = "abc"` sets pointer to the address of the "abc" string (which may be stored in read-only memory and thus unchangeable).
  - `Assign`
    + array - cannot be assigned a value.
    + pointer - can be assigned a value.
  ```cpp
  int a[10];
  int *p;
  p = a;  /* legal */
  a = p;  /* illegal */
  ```
  - `Arithmetic`
    + array - NOT allowed.
    + pointer - allowed.
  ```cpp
  p++;  /* legal */
  a++;  /* illegal */
  ```

## Objects & Classes 
* #### Difference b/w `class` & `struct`?
	- `class` has by default members defined as `private`.
	- `struct` has by default members defined as `public`.

> NOTE: always define members as `private` & `public` in case of `class` & `struct`.

* #### How to access (set & get) a private variable of an object?
	- `set`
		+ M-1: paramterized constructor: E.g. `Test(int n): a(n) {}`
		+ M-2: create a set func: E.g.`set_var(int a){...}`
	- `get`
		+ M-1: create a set func: E.g.`get_var() {return a}`

## Input, Output stream

* #### Why '\n' is not used in `scanf`?
	- e.g. code:
	```cpp
	int n;
	scanf("%d\n", &n);
	printf("you typed %d\n", n);
	```
	- \n in a scanf format string does not mean to expect a newline,
	- it is to read and discard characters as long as each is a whitespace character.
	- In fact, any whitespace character in a scanf format string means to read and discard whitespace characters.
	- `scanf` was designed for free-format input, which is seldom what you want when reading from the keyboard.
	- By __'free format'__ we mean that scanf does not treat newlines differently from other whitespace. 
	- The format "%d %d %d" would be equally happy reading the input:
	```
	1 2 3
	or
	1
	2
	3
	```
	- Still, if one wants to use newline in `scanf`, then use like this: `scanf("%d%*[\n]", &n);`
	
* #### Which one is faster - `std::endl` or `'\n'`?
	- `'\n'` as `std::endl` includes `\n` + `std::flush` <br/>
	- 6 times faster.
  [Reference 1](https://www.youtube.com/watch?v=6WeEMlmrfOI), [Reference 2](https://www.youtube.com/watch?v=GMqQOEZYVJQ)
* #### What is the alternative lib for `<stdio.h>`?
	- Ans.- `<cstdio>`
	- this lib is used in .cpp programs mainly for `printf`, `scanf` function.

* #### `getline` vs `cin`?
	- `getline`
		+ used for __string__. e.g. "abhijit is a good boy"
	- `cin`
		+ used for __int__, __char__, __double__, __float__
		+ bascally can't leave `space` here as an input.
<details>
<summary>View code:</summary>

```cpp
getline(cin, str);
```
</details>

## Arrays and Strings
* #### `const char *` vs `std::string`
	- C
		+ defined by `const char*`
	- C++
		+ defined by `std::string`
```cpp
int main() {
	// M-1:
	std::string str_cpp = "abhijit";
	const char* str_c = str_cpp.c_str();

	// M-2:
	const char* str_c = "abhijit";	
	std::string str_cpp = str_c;

	std::cout << str_cpp << std::endl;
	std::cout << str_c << std::endl;

	return 0;
}
```

## Containers
* #### How to create multiple return types function in C++?
```cpp
#include <iostream>
#include <utility>

using std::string;


std::pair<string, int> set_weekno(string day, int num) {
	return std::make_pair(day, num);
}


int main() {
	// M-1:
	// std::pair<string, int> daynum_week;

	// daynum_week = std::make_pair("Sunday", 0);


	// std::cout << daynum_week.first << std::endl;
	// std::cout << daynum_week.second << std::endl;

// ---------------------------------------------------------------------------
	// M-2
	std::pair<string, int> a = set_weekno("Sunday", 0);

	std::cout << a.first << std::endl;		// Sunday
	std::cout << a.second << std::endl;		// 0


	return 0;
}
```

* #### Which one is best of `array`, `vector`, `list`, `deque`?
	- `array`
		+ need to mention the length
		+ doesn't suport member functions, unlike rest of them.
		+ slow & not flexible
	- `vector`
		+ doesn't allow push/pop elements from front.
	- `list` (doubly linked)
		+ doesn't support random access for iterators.
	- `deque`
		+ supports everything: __random access, bidirectional, forward, input, ouput__ iterators.

	> NOTE:

	> - `deque` is best sequence container out of all. <br/>
	
	> - "Memory is allocated differently for vectors and queues. A vector always occupies a contiguous region of memory. If a vector grows too large, it may need to be moved to a new location where it will fit. A deque, on the other hand, can be stored in several non-contiguous areas; it is segmented. A member function, capacity(), returns the largest number of elements a vector can store without being moved, but capacity() isn’t defined for deques because they don’t need to be moved." <--- as quotes in __Book: OOP in C++__


## REFERENCES
* ISO CPP FAQs: https://isocpp.org/faq