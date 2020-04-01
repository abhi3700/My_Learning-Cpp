## BASICS
### 1. Hello World

**Question**:
Print "Hello World"

**Solution**: 
```cpp
/*C++ Program to Print "Hello World"*/
#include <iostream>

int main()
{
    std::cout<<"Hello World"<<std::endl;
    return 0;
}
```
*****

### 2. Print Numbers

**Question**:
Enter any integer and print that number

**Solution**: 
```cpp
/*C++ Program to Print Number Entered by User*/
#include <iostream>

int main()
{
    int num;

    //input the number
    std::cout<<"Enter an integer \n";
    std::cin>>num;

    // Print the number
    std::cout<<"You entered "<<num<<std::endl;
    return 0;
}
```

*****

### 3. Add 2 numbers

**Question**:
Program to add 2 Numbers.

**Solution**: 
```cpp
/*C++ Program to Add 2 Numbers*/
#include <iostream>

int main()
{
    int a, b, c;
    // Enter a
    std::cout<<"Enter a: \n";
    std::cin>>a;

    // Enter b
    std::cout<< "Enter b: \n";
    std::cin>>b;

    c = a + b;
    std::cout<<"The addition of "<<a<<" and "<<b<<" is "<<c <<std::endl;
    return 0;
}
```

*****

### 4. Area of Circle

**Question**:
Program to calculate Area of Circle.

**Solution**: 
```cpp
/*C++ Program on Area of Circle*/
#include <iostream>

int main()
{
    int r; // radius of the circle
    double area;

    std::cout<<"Enter the radius :\n";
    std::cin>> r;

    // the area
    area = 3.14 * r * r;
    std::cout<<"The area of the circle: "<< area<<std::endl;
    return 0;
}
```

*****

### 5. Divisor & Dividend

**Question**:
Program to find Divisor and Dividend

**Solution**: 
```cpp
/*C++ Program to find Divisor and Dividend*/
#include <iostream>

int main()
{
    int dividend, divisor, quotient, remainder;

    // dividend
    std::cout<<"Enter the dividend: \n";
    std::cin>>dividend;

    // divisor
    std::cout<<"Enter the divisor: \n";
    std::cin>>divisor;

    quotient = dividend/divisor; //quotient
    remainder = dividend % divisor; //remainder

    std::cout<<"The quotient is "<<quotient<<std::endl;
    std::cout<<"The remainder is "<<remainder<<std::endl;
    return 0;
}
```

*****

### 6. Convert *C to *F

**Question**:
Program to convert Celsius and Fahrenheit

**Solution**: 
```cpp
/*C++ Program to convert Celsius and Fahrenheit*/
#include <iostream>

int main()
{
    float celsius, fahrenheit;

    std::cout<<"Enter temperature in Celsius: \n";
    std::cin>>celsius;

    fahrenheit = celsius * (9.0/5.0) + 32;
    std::cout<<"The temperature in Celsius is "<< celsius<<std::endl;
    std::cout<<"The temperature in Fahrenheit is "<< fahrenheit<<std::endl;

    return 0;
}
```

*****

### 7. Leap Year

**Question**:
Program to check a leap year

**HINT:** 
[(Source)](https://support.microsoft.com/en-us/help/214019/method-to-determine-whether-a-year-is-a-leap-year)
 To determine whether a year is a leap year, follow these steps:
1. If the year is evenly divisible by 4, go to step 2. ...
2. If the year is evenly divisible by 100, go to step 3. ...
3. If the year is evenly divisible by 400, go to step 4. ...
4. The year is a leap year (it has 366 days).
5. The year is not a leap year (it has 365 days).

**Solution**: 
```cpp
/*C++ Program to check a leap year*/
#include <iostream>

int main()
{
    int year; 
    std::cout<<"Enter a year: \n";
    std::cin>>year;

    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0) {
                std::cout<<"It is a leap year"<<std::endl;
            } 
            else {
                std::cout<<"It is NOT a leap year"<<std::endl;
            }
        } 
        else 
        {
                std::cout<<"It is NOT a leap year"<<std::endl;

        } 
    } 
    else 
    {
                std::cout<<"It is NOT a leap year"<<std::endl;

    }
    return 0;
}
```

*****

### 8. ASCII

**Question**:
Program to Print ASCII value

**Solution**: 
```cpp
/*C++ Program to Print ASCII value*/
#include <iostream>

int main()
{
    char c;
    std::cout<<"Enter a char: \n";
    std::cin>>c;

    std::cout<<"The ASCII value of "<<c<< " is "<< int(c)<<std::endl;
    return 0;
}
```

*****

### 9. Switch statement

**Question**:
Program to understand Switch statement

**Solution**: 
```cpp
/*C++ Program to understand Switch*/
#include <iostream>

int main()
{
    int choice;

    std::cout<<"Enter an integer number (1-5): \n";
    std::cin>>choice;

    switch(choice){
        case(1): std::cout<<"You entered 1"<<std::endl;
                break;
        case(2): std::cout<<"You entered 2"<<std::endl;
                break;
        case(3): std::cout<<"You entered 3"<<std::endl;
                break;
        case(4): std::cout<<"You entered 4"<<std::endl;
                break;
        case(5): std::cout<<"You entered 5"<<std::endl;
                break;
        default:
                std::cout<<"Invalid choice."<<std::endl;
                break;
    }
    return 0;
}
```

*****

### 10. If-else Statement

**Question**:
Program to understand If-else

**Solution**: 
```cpp
/*C++ Program to understand If-else*/
#include <iostream>

int main()
{
    int n; 
    std::cout<<"Enter an integer: \n";
    std::cin>>n;

    if(n % 2 == 0){
        std::cout<<"The number is EVEN."<<std::endl;
    } else {
        std::cout<<"The number is ODD."<<std::endl;
    }
    return 0;
}
```

*****
