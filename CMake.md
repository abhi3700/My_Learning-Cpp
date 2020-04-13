# CMake
## About
This is about learning how to compile C/C++ files:
* with independent platform support
* with external libraries

## Demo project: Example 1 - hello
Follow the steps:
* Create a folder project and name it as "hello".
* Create 2 files: 
  - `hello.cpp`
    ```cpp
    #include <iostream>

    int main() {
      std::cout << "Hello Abhijit!" << std::endl;
      return 0;
    }
    ```
  
  - `CMakeLists.txt`
    ```
    cmake_minimum_required(VERSION 2.8.9)
    project (hello)

    set(CMAKE_CXX_STANDARD  17)	// C++17
    add_executable(hello hello.cpp)
    ```

### M-1
* open bash-terminal at this location. 
* (OPTIONAL) Ensure that cmake is installed. If not Check by the followings: 
	- (to install) `$ sudo apt-get install cmake` 
	-	(to check) `$ cmake --version` 
	
* type `cmake .` - to **build** the project and to generate **Makefile**. <br/>
	CMake identified the environment settings for the linux device and created the Makefile for this project.
	
	Output:
```bash
-- The C compiler identification is GNU 7.3.0
-- The CXX compiler identification is GNU 7.3.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /mnt/f/Coding/C++/cpp-playground/hello
```
* type `$ make` to generate the output file i.e. `hello`.
	
	Output:
```bash
Scanning dependencies of target hello
[ 50%] Building CXX object CMakeFiles/hello.dir/helloworld.cpp.o
[100%] Linking CXX executable hello
[100%] Built target hello
```

* `./hello` - prints the output
	
	Output:
```bash
Hello Abhijit!
```

### CLion
* Create the folder as required - 

## Example 2
A more structured implementation of CMake with 
* all the build files inside `../student/build/`
* all the header files inside `../student/include/`
* all the source files inside `../student/src/`

Follow the steps:
* In ST3, open a folder named "student"
* open bash terminal here.
* `$ mkdir build include src` - create 3 folders: build, include, src.
* `$ touch CMakeLists.txt include/student.h src/student.cpp src/mainapp.cpp` - create the files.
* [OPTIONAL] view the tree - `$ tree -L 2`
<details>
	<summary><b>Output:</b></summary>
<p>

```bash
.
├── CMakeLists.txt
├── build
├── include
│   └── student.h
└── src
    ├── mainapp.cpp
    └── student.cpp

3 directories, 4 files
```
</p>
</details>

* edit the header files - `student.h`
* edit the source files - `student.cpp`, `mainapp.cpp`
* edit the `CMakeLists.txt` as:
<details>
	<summary><b>Output:</b></summary>
<p>

```txt
cmake_minimum_required(VERSION 2.8.9)
project(directory_test)

#Bring the headers, such as Student.h into the project
include_directories(include)

#Can manually add <table></table>he sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

add_executable(testStudent ${SOURCES})
```
</p>
</details>

* `cd build` - go to the build directory.
* `cmake .` - build the project
* `make` - create the target file `student`
* `./student` - to get the output


## Why this?
Usually, I choose to compile .cpp files with [CppFastOlympicCoding](https://packagecontrol.io/packages/CppFastOlympicCoding) package. 
While using **Boost** library, it didn't require any linkage.

But while using [libXL](http://www.libxl.com/home.html), the existing package couldn't link the library. That's why I had to learn CMake. 

## References
* https://cmake.org/cmake-tutorial/
* https://pmateusz.github.io/c++/cmake/2018/03/11/cmake-project-setup.html
* https://mirkokiefer.com/cmake-by-example-f95eb47d45b1
* https://www.selectiveintellect.net/blog/2016/7/29/using-cmake-to-add-third-party-libraries-to-your-project-1
* http://derekmolloy.ie/hello-world-introductions-to-cmake/
* https://tuannguyen68.gitbooks.io/learning-cmake-a-beginner-s-guide/content/chap1/chap1.html
