* ### Function definition - 
  In **C++**, ```function``` declaration should be done, before its use. Or else, define entirely before its use in the main function<br/>
  E.g.
  ```cpp
  void foo(int); // Prototype declaration of foo, seen by main
                 // Must specify return type, name, and argument list types
  int main()
  {
    foo(2); // OK: foo is known, called even though its body is not yet defined
  }
  void foo(int x) //Must match the prototype
  {
    // Define body of foo here
  }
  ```
  
  In **Java**, there is no such rule. Define anywhere.

* ### Pointers & Reference
  In **C++**, define Reference (using the object and putting own label) like this:
  ```cpp
  Box& b;  // defining a reference like Java
  b.setLength(3.5);
  b.setBreadth(5.6);
  b.setHeight(6.7);
  ```
  and Pointer (like a new stack in the memory) like this:
  ```cpp
  Box* b = new Box(args);
  b->setLength(3.5);
  b->setBreadth(5.6);
  b->setHeight(6.7);
  ```
  
  In **Java**, no pointer only reference.
  ```java
  Box b;
  b.setLength(3.5);
  b.setBreadth(5.6);
  b.setHeight(6.7);
  ```
  
* ### `static` use in functions
  #### C++:
  `static` (in function) saves the state. For more, click [here](https://github.com/abhi3700/My_Learning-Cpp/blob/master/my_cpp_essentials.md#static-keyword)
  ```cpp
  #include <iostream>

  using namespace std;

  void func() {
      static int i = 0;
      cout << i;
      i++;
  }

  int main() {
      func();
      func();
      func();

      return 0;
  }
  ```
  Output:
  ```
  012
  ```  
  Here, `static` means the function saves the previous state and runs from there on next call.
  #### Java:
  static has no such role.
  ```java
  class Main {
      static void func() {
          /*static*/ int i = 0;
          System.out.println(i);
          i++;
      }
      public static void main(String[] args) {
          func();
          func();
          func();
      }
  }
  ```
  Output:
  ```
  0
  0
  0
  ```
  Here, use of `static` would give error.
  
