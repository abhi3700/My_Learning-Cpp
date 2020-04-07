## General
* #### what is the simple difference b/w __gcc__ & __g++__?
	- gcc: used mainly for C files.
	- g++: used mainly for C++ files.

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

## Input, Output stream
* #### Which one is faster - `std::endl` or `'\n'`?
	- `'\n'` as `std::endl` includes `\n` + `std::flush` <br/>
	- 6 times faster.
  [Reference 1](https://www.youtube.com/watch?v=6WeEMlmrfOI), [Reference 2](https://www.youtube.com/watch?v=GMqQOEZYVJQ)
* #### What is the alternative lib for `<stdio.h>`?
	- Ans.- `<cstdio>`
	- this lib is used in .cpp programs mainly for `printf`, `scanf` function.