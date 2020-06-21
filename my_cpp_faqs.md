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


> NOTE:
> __Best practice__

> - Any variable that should not be modifiable after initialization and whose initializer is known at compile-time should be declared as constexpr.
> - Any variable that should not be modifiable after initialization and whose initializer is not known at compile-time should be declared as const.

<details>
	<summary>View code:</summary>

```cpp
constexpr double gravity { 9.8 }; // ok, the value of 9.8 can be resolved at compile-time
constexpr int sum { 4 + 5 }; // ok, the value of 4 + 5 can be resolved at compile-time
 
std::cout << "Enter your age: ";
int age;
std::cin >> age;
constexpr int myAge { age }; // not okay, age can not be resolved at compile-time
```
</details>

* #### `const` is used before or after datatype?
	- `const` is preferably used before datatype, although the other way is not wrong.
	- See the code below to understand:

<details>
	<summary>View code:</summary>

```cpp
const double gravity { 9.8 }; // preferred use of const before type
int const sidesInSquare { 4 }; // okay, but not preferred
```
</details> 

* #### How do I mix C & C++ code?
	- NOTES:
		+ You must use your C++ compiler when compiling `main()` (e.g., for static initialization)
		+ the C++ compiler is more careful/picky than your C compiler
	- call C function from within C++ file: Just declare the C++ function extern "C" (in your C++ code) and call it (from your C or C++ code).
		+ "*.c"
```c
		/* C code: */
    void f(int i)
    {
        /* ... */
    }
    int g(double d)
    {
        /* ... */
    }
    double h()
    {
        /* ... */
    }
```
		+ "*.cpp"
```console
		// C++ code
    extern "C" void f(int); // one way
    extern "C" {    // another way
        int g(double);
        double h();
    };
    void code(int i, double d)
    {
        f(i);
        int ii = g(d);
        double dd = h();
        // ...
    }
```
	- call C++ function from within C file: Just declare the C++ function extern "C" (in your C++ code) and call it (from your C or C++ code).
		+ "*.cpp"
```console
   // C++ code:
    extern "C" void f(int);
    void f(int i)
    {
        // ...
    }
```
		+ "*.c"
```console
		/* C code: */
    void f(int);
    void cc(int i)
    {
        f(i);
        /* ... */
    }
```

	[SOURCE](https://isocpp.org/wiki/faq/mixing-c-and-cpp)


* #### How can I use a non-system C header file in C++ code?
	- E.g.
```cpp
// This is C++ code
extern "C" {
  // Get declaration for f(int i, char c, float x)
  #include "my-C-code.h"
}
int main()
{
  f(7, 'x', 3.14);   // Note: nothing unusual in the call
  // ...
}
```

	[SOURCE](https://isocpp.org/wiki/faq/mixing-c-and-cpp)


* #### How can I modify my own C header file so, it's easier to `#include` them in C++ code?
	- Just add `extern "C" {}` using `#ifdef` & `#endif` at the top & bottom of the C header file (if editable).
		+ put in the beginning:
```c
#ifdef __cplusplus
extern "C" {
#endif
```
		+ put in the end:
```c
#ifdef __cplusplus
}
#endif
```
		+ the final C++ code:
```cpp
// This is C++ code
// Get declaration for f(int i, char c, float x)
#include "my-C-code.h"   // Note: nothing unusual in #include line
int main()
{
  f(7, 'x', 3.14);       // Note: nothing unusual in the call
  // ...
}
```

	[SOURCE](https://isocpp.org/wiki/faq/mixing-c-and-cpp)

* #### Difference b/w `typedef` and `using`?
	- Both are equivalent.
	- `typedef` has been used since C, but `using` is introduced in C++11.
	- `using` is a superset of `typedef` & it is also much more used with templates.
	- `using` is recommended as `typedef` could be deprecated in the future.

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

* #### `inline` function: whether to use or not?
	- Disclaimer: There is no simple & direct answer for this. 
	- History: It was introduced in __C__ language for fast execution by compiler to these inline functions. But, with time, modern compilers are intelligent enough to know which function to be given priority, especially in case of multi-threading.
	- __Small function:__ There's also a relatively simple & useful rule saying that functions which have short code and/or are typically called with compile time constant arguments so that most of their code computes a constant are typically good candidates for inlining. 
	- __Long function:__ Long functions are typically worse candidates for inlining, because the function call overhead is negligible compared to the things the functions actually do, and the main problem with inlining - large code size - becomes dominant.
	- It's usually a good idea to only explicitly enable the inlining of very short functions, and performance considerations are not the only reason.
	- In C++ you have to place the code in header files to enable inlining.
	- If your application is not CPU bound, you aren't getting any benefits from using an unsafe language like C++ except for extra quality time with the debugger.
	- Use `inline` for smaller functions, especially in case of Blockchain applications, where CPU resources are limited & a Smart Contract developer should write code efficiently.
	- Using the `inline` keyword should be kept to a minimum and reserved for only those functions that do very little and need to do it with minimal overhead, as demonstrated earlier.

	For more, refer to [this](http://yosefk.com/c++fqa/inline.html)

* #### Why there is `->` arrow in case of function?
	- it is basically, `<return type>`.
	- In C++11, 2 ways of defining function. The correct syntax is:
```cpp
return-type identifier ( argument-declarations... )

OR

auto identifier ( argument-declarations... ) -> return_type
```
	- Example:
```cpp
// Here, a lib: `result` has been used although. But, the function return_type is `double` & `auto` is the identifier.
auto Op(double x, double y) -> double {
  return Div(x, y)
  .and_then(Sqrt)
  .and_then(Log)
  .unwrap();
}
```

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

* #### `std::map<X, Y>` vs `std::list<std::pair<X, Y>>`?
	- `std::map<X, Y>`:
		+ is an ordered structure with respect to keys (that is, when you iterate over it, keys will be always increasing).
		+ supports unique keys (Xs) only
		+ offers fast find() method (O(log n)) which finds the Key-Value pair by Key
		+ offers an indexing operator __map[key]__, which is also fast

	- `std::list<std::pair<X, Y> >`:
		+ is a simple sequence of paired Xs and Ys. They remain in the order you put it in.
		+ can hold any number of duplicates
		+ finding a particular key in a list is O(N) (no special method)
		+ offers the __splice__ method.

	> NOTE: `std::vector<std::pair<X, Y>>` is better than this ^ (above), as it offers `O(log(N))` search. Even better would be `std::deque<std::pair<X, Y>>` (as that would have insertion from front & back both.)

* #### Which one to choose: `pair` (using STL) or `pair` (using Struct)?
	- `pair` (using STL) is actually a templated struct.
	- This is because, if a struct is defined, Also, it's elements type is to be defined. NOTE: you can't set auto.
	

## REFERENCES
* ISO CPP FAQs: https://isocpp.org/faq