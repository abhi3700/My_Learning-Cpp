* ### Editor - 
  **Sublime Text 3**.
  
* ### Compilers 
	**Windows** - mingw-w64 <br/>
	**MacOS** - Clang <br/>
	**Linux** - GCC 
	
	#### NOTE: Popular C++ compilers are mingw-w64 for Windows, Clang for XCode for macOS, and GCC on Linux. Make sure your compiler executable is in your platform path so the extension can find it. The extension also supports the Windows Subsystem for Linux.
	
* ### Installation
  In linux (Ubuntu), g++ is used to compile the C/C++ files.
  E.g. 
  ```
    g++ hello.cpp -o hello.out  // compile the C++ file.
  ```
    or
  ```
    g++ -std=c++11 hello.cpp -o hello.out   // compile the C++11 file.
  ```
  ```
    ./hello.out   // execute the output file.
  ```
	
* ### Fundamental types
	[SOURCE](https://msdn.microsoft.com/en-us/library/cc953fe1.aspx)
	
* ### Demerit of ```cin```:
  takes 
	- input as string only.
  - contnuous string as input, use alternative - ```getline```.
	
* ### References [SOURCE](https://www.youtube.com/watch?v=R4iviB8g12A)
	- concept introduced in C++.
	- **Rules:** TODO 
	- Example
	```cpp
	#include <iostream>

	using namespace std;

	// outputs variable on the console.
	void print(int var) {
		cout << var << endl;
	}


	int main() {
		int v = 5;

		// print the variable's value.
		print(v);	// 5

		int &p = v;

		// print the reference variable's value.
		print(p);	// 5	

		// increment the ref. variable.
		p++;	

		// print the incremented ref. variable.
		print(p);	// 6

		// print the actual variable now.
		print(v);	// 6

		return 0;
	}
	```
* ### Pointer - 
  here, any pointer has stored values as address
  E.g. 1
  ```cpp
  int a = 5;  // variable stores the value
  int *ptr = nullptr;  // declared and initialised the pointer
  ptr = &a;   // the pointer stores the memory address of the variable.
  ```  
  E.g. 2
  ```cpp
  /*For this program print for each variable
  **print the value of the variable, 
  **then print the address where it is stored. 
  */
  #include<iostream>
  #include<string>

  int main()
  {
      int givenInt = 5;
      float givenFloat = 5.0;
      double givenDouble = 5.6;
      std::string givenString = "abhijit";
      char givenChar = 'a';

      int *pointertogivenInt;
      pointertogivenInt = &givenInt;
      float *pointertogivenFloat;
      pointertogivenFloat = &givenFloat;
      double *pointertogivenDouble ;
      pointertogivenDouble = &givenDouble;
      std::string *pointertogivenString;
      pointertogivenString = &givenString;
      char *pointertogivenChar;
      pointertogivenChar = &givenChar;

      std::cout<<"The pointertogivenInt is "<<pointertogivenInt<<std::endl;
      std::cout<<"The value stored in pointertogivenInt is "<<*pointertogivenInt<<std::endl;

      std::cout<<"The pointertogivenFloat is "<<pointertogivenFloat<<std::endl;
      std::cout<<"The value stored in pointertogivenFloat is "<<*pointertogivenFloat<<std::endl;

      std::cout<<"The pointertogivenDouble is "<<pointertogivenDouble<<std::endl;
      std::cout<<"The value stored in pointertogivenDouble is "<<*pointertogivenDouble<<std::endl;

      std::cout<<"The pointertogivenString is "<<pointertogivenString<<std::endl;
      std::cout<<"The value stored in pointertogivenString is "<<*pointertogivenString<<std::endl;

      std::cout<<"The pointertogivenChar is "<<pointertogivenChar<<std::endl;
      std::cout<<"The value stored in pointertogivenChar is "<<*pointertogivenChar<<std::endl;
      return 0;
  }
  ```
  
  Another example of pointer with  `this`. Click [here](https://beginnersbook.com/2017/08/cpp-this-pointer/).
 
* ### Pre-increment & Post-increment - 
  Pre- operation & then assign the updated value (to the other var)
  Post - assign the original value (to the other var) & then update this var. 
  E.g. 
  ```cpp
  #include<iostream>

  using namespace std;

  int main()
  {
      int a, b = 0;
      int post, pre = 0;
      cout<<"Inital values: \t\t\tpost = "<<post<<" pre= "<<pre<<"\n";
      post = a++;  // post returns 0 (but a=1)
      pre = ++b;   // pre returns 1 (but a=1)
      cout<<"After one postfix and prefix: \tpost = "<<post<<" pre= "<<pre<<"\n";
      post = a++;  // post returns 1 (but a=2)
      pre = ++b;   // pre returns 2 (but a=2)
      cout<<"After two postfix and prefix: \tpost = "<<post<<" pre= "<<pre<<"\n";  
      return 0;
  }
  ```
  
* ### array - size or length of an array
  ```cpp
  sizeof(userInput)/sizeof(*userInput)  // 160/4 = 40 (defined like - e.g. arr[40])
  ```
  
* ### Function by call or by reference
  ```cpp
  #include<iostream>

  int increment(int input);
  int main()
  {
      int a = 34;
      std::cout<<"Before the function call a = "<<a<<"\n";
      a = increment(a);
      std::cout<<"After the function call a = "<<a<<"\n";
      return 0;
  }
  int increment(int input)
  {
      input++;
      std::cout<<"In the function call a = "<<input<<"\n";
      return input;
  }
  ```
  
  ```cpp
  #include<iostream>

  void increment(int &input); //Note the addition of '&'

  int main()
  {
      int a = 34;
      std::cout<<"Before the function call a = "<<a<<"\n";
      increment(a);
      std::cout<<"After the function call a = "<<a<<"\n";
      return 0;
  }
  void increment(int &input)//Note the addition of '&'
  {
      input++; //**Note the LACK OF THE addition of '&'**
      std::cout<<"In the function call a = "<<input<<"\n";
  }
  ```
  
* ### OOP (polymorphism, inheritance)
  E.g.
  ```cpp
  #include <iostream>
  // #include <sstream>


  class Car {   // a class has "data & variables" i.e. "attributes & behavior"
  public:
      int weight;
      std::string color;

      void brake(){   // function to display when called.
          std::cout<<"Brake is applied."<<std::endl;
      }

      int newWeight(){
          weight = 10;
          return weight;
      }

      int newWeight(int wei){  // explains Polymorphism
          weight = wei;
          return weight;
      }
  };

  class Car3: public Car{   // Explains Inheritance

      // No code written. Just calls the "attributes & behavior" of Parent class.
  };


  // Main function
  int main()
  {
      Car3 car1;  // declaration with child class NOT parent class

      car1.brake();
      std::cout<<car1.newWeight()<<std::endl;
      std::cout<<car1.newWeight(40)<<std::endl;

      return 0;
  }
  ```
  
* ### Templates - 
  [Source](http://www.learncpp.com/cpp-tutorial/131-function-templates/)
  Remember the Stencil analogy. Here, multiple functions with difference of parameter types can be represented with C++ templates.
  E.g. 'max' function
  ```cpp
  // int type
  int max(int x, int y)
  {
      return (x > y) ? x : y;    
  }
  ```
  
  ```cpp
  // double type
  double max(double x, double y)
  {
      return (x > y) ? x : y;    
  }
  ```
  Such functions can be represented with one function with generic type.
  ```cpp
  template <typename T>
  const T& max(const T& x, const T& y)
  {
      return (x > y) ? x : y;
  }
  ```
	
* ### C++ Multilevel Inheritance - 
  ```cpp
	class A
	{ 
	... .. ... 
	};
	class B: public A
	{
	... .. ...
	};
	class C: public B
	{
	... ... ...
	};
  ```

* ### Function by reference vs by value (/pointer) 
  ```cpp
  #include <iostream>

  // Function by reference
  void swap1(int &a, int &b) {
      int temp = a;
      a = b;
      b = temp;
      std::cout << "changed values a = " << a << " b = " << b <<"\n";
  }

  // Function by value
  void swap2(int *a, int *b) {
      int temp = *a;
      *a = *b;
      *b = temp;
      std::cout << "changed values a = " << *a << " b = " << *b <<"\n";

  }

  int p = 2;
  int q = 3;

  int main() {
    swap1(p, q); // pass by reference
    int *x = &p;
    int *y = &q;
    swap2(x, y); // pass by value
    return 0;
  }
  ```

> Say I want to share a web page with you. If I tell you the URL, I'm passing by reference. You can use that URL to see the same web page I can see. If that page is changed, we both see the changes. If you delete the URL, all you're doing is destroying your reference to that page - you're not deleting the actual page itself.

> If I print out the page and give you the printout, I'm passing by value. Your page is a disconnected copy of the original. You won't see any subsequent changes, and any changes that you make (e.g. scribbling on your printout) will not show up on the original page. If you destroy the printout, you have actually destroyed your copy of the object - but the original web page remains intact.
[Read more](https://stackoverflow.com/questions/373419/whats-the-difference-between-passing-by-reference-vs-passing-by-value#)

[SOURCE](https://www.geeksforgeeks.org/passing-by-pointer-vs-passing-by-reference-in-c/)

* ### `auto` keyword - called as "Type Inferring"
	it automatically takes the 'type' of the function, variable.
		
	```cpp
	/// This will work
	auto add(int x, int y)
	{
			return x + y;
	}
	
	/// This will NOT work. So, instead use templates.
	void addAndPrint(auto x, auto y)
	{
			std::cout << x + y;
	}
	```
	
	[SOURCE](http://www.learncpp.com/cpp-tutorial/4-8-the-auto-keyword/)

* ### `typedef` - Type definition
	- #### with Variables
	```cpp
	int current_speed ;
	int high_score ;


	void congratulate(int your_score) {
			if (your_score > high_score)
					...
	```
	
	& 
	
	```cpp
	typedef int km_per_hour ;
	typedef int points ;

	km_per_hour current_speed ;  //"km_per_hour" is synonymous with "int" here,
	points high_score ;          //and thus, the compiler treats our new variables as integers.


	void congratulate(points your_score) {
			if (your_score > high_score)
					...
	```
	
	are both identical.
	
	**Inference:** Both sections of code execute identically. However, the use of typedef declarations in the second code block makes it clear that the two variables, while represented by the same data type int, represent different or incompatible data. The definition in congratulate() of your_score indicates to the programmer that current_speed (or any other variable not declared as a points) should not be passed as an argument.
	
	- #### with Structs
	In terms of `struct` typedef is defined as:
	```cpp
	typedef struct {
    int data1;
    char data2;
	} newtype;
	```
	
	- #### with Pointers
	In terms of `pointers`, typedef is defined as;
	```cpp
	typedef int *intptr;   // type name: intptr
                       // new type: int*

	intptr ptr;            // same as: int *ptr
	```
	
	**Inference:** Above, intptr is a new alias with the pointer type int*. The definition, intptr ptr;, defines a variable ptr with the type int*. So, ptr is a pointer which can point to a memory with int type.
	```cpp
	typedef int *intptr;

	intptr cliff, allen;        // both cliff and allen are int* type

	intptr cliff2, *allen2;     // cliff2 is int* type, but allen2 is int** type
															// same as: intptr cliff2;
															//          intptr *allen2;
	```
	
  - #### with structure pointers
  ```cpp
  typedef struct Node Node;
  struct Node {
      int data;
      Node *nextptr;
  };
  ```
	 
	e.g. 2 -->
	```cpp
	struct Node *startptr, *endptr, *curptr, *prevptr, errptr, *refptr;
	```
	 &
	 
  ```cpp
  typedef struct Node* NodePtr;
  NodePtr startptr, endptr, curptr, prevptr, errptr, refptr;
  ```
  are identical.

  - #### with Function pointers
  TODO - https://en.wikipedia.org/wiki/Typedef#Using_typedef_with_function_pointers

  - #### with Arrays
  ```cpp
  typedef char arrType[6];    // type name: arrType
                          // new type: char[6]

  arrType arr={1,2,3,4,5,6};  // same as: char arr[6]={1,2,3,4,5,6}

  arrType *pArr;              // same as: char (*pArr)[6];
  ```
	 
  - #### Usage in C++
  ```cpp
  std::vector<std::pair<std::string, int> > values;
  for (std::vector<std::pair<std::string, int> >::const_iterator i = values.begin(); i != values.end(); ++i)
  {
     std::pair<std::string, int> const & t = *i;
     // do something
  }
   ```
   & 
  ```cpp
  typedef std::pair<std::string, int> value_t;
  typedef std::vector<value_t> values_t;

  values_t values;
  for (values_t::const_iterator i = values.begin(); i != values.end(); ++i)
  {
     value_t const & t = *i;
     // do something
  }
  ```
  are identical.
  
  - #### with templates
  TODO - https://en.wikipedia.org/wiki/Typedef#Use_with_templates

	
* ### Inline functions 
	- CPU stores the memory address of the instruction and then calls the function.
	- copies the arguments of the function on the stack.
	- if the **execution-time** of function < **switching-time** from the caller function to called function (callee).
	- E.g. 
		+ for Small function, the execution time < switching time.
		+ for Large function, the execution time > switching time.
	- C++ provides inline functions to reduce the function call (i.e. switching time).
	- syntax:
	```
	inline return-type function-name(parameters) 
	{
		// Do anything
	}
	```
	- #### NOTE: `inline` is not a command, but a request to the compiler.
	-  Compiler **may** not consider in these circumstances:
		+ If a function contains a loop. (for, while, do-while)
		+ If a function contains static variables.
		+ If a function is recursive.
		+ If a function return type is other than void, and the return statement doesn’t exist in function body.
		+ If a function contains switch or goto statement.
	- Advantages:
		+ Function call overhead doesn’t occur
		+ It also saves the overhead of push/pop variables on the stack when function is called.
		+ It also saves overhead of a return call from a function.
		+ For embedded systems, `inline` functions (if it is small) can yield less code than the function call.
	- Disadvantages:
		+ inlined function consumes additional registers.
		+ too many inline functions leads to large binary executable file size.
		+ too much inlining can reduce your instruction cache hit rate => low speed of instruction fetch from cache memory to primary memory.
		+ For many embedded systems, inline functions may not be useful because code size is more imp. than speed.
	- **Bad** inline programming style
  ```cpp
  class S
  {
  public:
    inline int square(int s) // redundant use of inline
    {
      // this function is automatically inline
      // function body
    }
  };
  ```
	- **Good** inline programming style
  ```cpp
  class S
  {
  public:
    int square(int s); // declare the function
  };
  inline int S::square(int s) // use inline prefix
  {
      // do something
  }
  ```
	
	Link - https://www.geeksforgeeks.org/inline-functions-cpp/

* ### `const` methods
	- `const` method function --> not allow them to modify the object on which they are called.
	- E.g.
  ```cpp
  #include<iostream>

  using namespace std;

  class Test {

      int value;

  public:
      Test(int v = 0) {value = v;}
      // We get compiler error if we add a line like "value = 100;"
      // in this function.
      int getValue() const {return value;}  
  };

  int main() {
      Test t(20);
      cout<<t.getValue();
      return 0;
  }
  ```
	- a `const` function can be called on any type of object.
	- But, a non-const function can be called by non-const objects.

	Like 

  ```cpp
  #include <iostream>

  using namespace std;

  class Test {
    int value;

    public:
        Test( int v ) {value = v;}

        int getValue() {return value;}
  };

  int main() {
    const Test t(20);
    std::cout << t.getValue() << std::endl;

    return 0;
  }
  ```

	gives an error:
		`passing 'const Test' as 'this' argument of 'int 
		Test::getValue()' discards qualifiers`
	
	Link - https://www.geeksforgeeks.org/const-member-functions-c/ 
	
* ### Access modifiers: `public` `private` `protected`
	#### Access Levels
	| **Modifier** |	**Class** |	**Package** |	**Subclass** |	**World** |
	|--------------|------------|-------------|--------------|-----------|
	| public	| Y |	Y |	Y |	Y |
	| protected |	Y |	Y |	Y |	N |
	| no modifier	| Y |	Y	| N	| N |
	| private	| Y	| N |	N	| N |
  
	Refer this [Link](https://www.geeksforgeeks.org/access-modifiers-in-c/)
  
* ### Tuples and Pairs
	- Tuples are objects that pack elements of -possibly- different types together in a single object, just like pair objects do for pairs of elements, but generalized for any number of elements.
	- `std::tuple<int, float>` is the **variable (or function) type**.
	- `std::make_tuple(1, 3.45f)` is the `output` used as `return` also.
	- Tuple: multiple values
	- Pair: 2 values
	- Code example:
	
  #### E.g. 1

  ```cpp
  #include <iostream>
  #include <tuple>

  using namespace std;

  tuple<int, int, char> foo(int n1, int n2) {
    return make_tuple(n2, n1, 'a');
  }

  pair<int, int> foo1(int n1, int n2) /*const*/ {
    return make_pair(n2, n1);
  }

  int main() {
    int a, b;
    char cc;

    // Tuple
    tie(a, b, cc) = foo(1, 2);
    cout << "values returned by Tuple: \n";
    cout << a << " " << b  << " " << cc << endl;

    // Pair
    pair<int, int> p = foo1(3, 4);
    cout << "values returned by Pair: \n";
    cout << p.first << " " << p.second;

    return 0;
  }
  ```
	
  #### E.g. 2
	
  ```cpp
  #include <iostream>
  #include <tuple>	// for tuple
  #include <string>	// for string

  int main() {
  int a;
  float b;
  char c;  
  std::string d;

  // Method - 1 
  // tie can contain upto any qty.
  std::tie(a, b, c, d) = std::make_tuple(1, 2.56f, 'c', "abhijit" );
  std::cout << a << " " 
        << b << " " 
        << c << " " 
        << d 
        << std::endl;

  // Method - 2 
  std::tuple<int, float, char, std::string> t = std::make_tuple(1, 2.56f, 'c', "abhijit" );		
  std::cout << std::get<0>(t) << " "
        << std::get<1>(t) << " "
        << std::get<2>(t) << " "
        << std::get<3>(t) << " "
        << std::endl;
  return 0;
  }
  ```

* ### `static` keyword
	- use in functions
  ```cpp
  // C++ program to demonstrate  
  // the use of static Static  
  // variables in a Function 
  #include <iostream> 
  #include <string> 
  using namespace std; 

  void demo() 
  {  
      // static variable 
      static int count = 0; 
      cout << count << " "; 

      // value is updated and 
      // will be carried to next 
      // function calls 
      count++; 
  } 

  int main() 
  { 
      for (int i=0; i<5; i++)     
          demo(); 
      return 0; 
  } 
  ```
	
**Output:**
	`0 1 2 3 4 `
	
  Here, due to `static` keyword use, the variable in the previous function call gets saved (or carried) in the next call and likewise. 
	
  [SOURCE](https://www.geeksforgeeks.org/static-keyword-cpp/)

* ### `char*` vs `string` vs `char[]`
#### `char*`
	```cpp
	// CPP program to illustrate assigning 
	// *char value to other variable  
	#include <iostream> 
	using namespace std; 

	int main() 
	{ 
			// This initialization gives warning in C++. 
			// "deprecated conversion from string constant 
			// to 'char*'" 
			char* str = "Hello"; 

			const char* str1 = "Hello"; // No warning 

			// trying to modify const string literal 
			// gives Runtime error 
			str[1] = 'o'; 

			cout << str << endl; 

			return 0; 
	}
	```
	output:
	```
	Segmentation Fault
	```
	
  #### `std::string` - append, substr, insert, find, replace
	```cpp
	// CPP program to illustrate  
	// std::string functions 
	#include <iostream> 
	using namespace std; 

	int main() 
	{ 
			// string assignment 
			string s1 = "Hello"; 
			string s2 = "World"; 

			// return length of string 
			cout << s1.size() << endl; // 5 
			cout << s2.length() << endl; // 5 

			// concatenate string using + operator. 
			s1 = s1 + s2; 
			cout << s1 << endl; // HelloWorld 

			// append string 
			s1.append("Geeks"); 
			cout << s1 << endl; // HelloWorldGeeks 

			string s3 = "HelloWorldGeeks"; 

			// compare two strings 
			if (s1.compare(s3) == 0) 
					cout << "true" << endl; 
			else
					cout << "false" << endl; 

			// substring of string s1 
			// substr(pos, length_of_substring) 
			string sub = s1.substr(0, 5); 
			cout << sub << endl; // Hello 

			// insert into string 
			// insert(pos, string) 
			s1.insert(10, "For"); 
			cout << s1 << endl; // HelloWorldForGeeks 

			string target = "World"; 

			// find a target string in s1 
			size_t pos = s1.find(target); 
			if (pos != std::string::npos) // npos=-1 
					cout << "Found at Position:" << pos << endl; // pos=5 

			// replace a portion of string s1 
			// replace(pos, length_of_portion, string_to_replace) 
			cout << s1.replace(5, 5, "Geeks") << endl; // HelloGeeksForGeeks 

			return 0; 
	}
	```
	
  #### `char[]`
	```cpp
	// CPP program to illustrate char 
	#include <iostream> 
	using namespace std; 

	int main() 
	{ 

			char str[] = "Hello"; 
			// or char str1[]={'H', 'e', 'l', 'l', 'o', '\0'}; 

			// modify string to "Hollo" 
			str[1] = 'o'; 

			cout << str << endl; 

			return 0; 
	} 
	```
  [SOURCE](https://www.geeksforgeeks.org/char-vs-stdstring-vs-char-c/)
	
  Hence, in C++, prefer `std::string` for string usage as it contains many other functions
	
* ### const
	- const in variables
	- const in pointers
	- const in function arguments and return
	- const class data members
	- const class object
	- const class member function
	
	[Source](https://www.studytonight.com/cpp/const-keyword.php)

* ### deque 
	**Code**:
  ```cpp
  // Operations: Front insert, Back insert, front delete, back delete, read front element, read back element
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
  ```
* #### atoi vs stoi
  in string conversion to integer<br/>
  [Code](https://github.com/abhi3700/cpp-playground/blob/master/basics/atoi_vs_stoi.cpp)
* #### lambda
```
[ capture clause ] (parameters) -> return-type  
{   
	 definition of method   
}
```
