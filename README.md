# C++ CodeDump
Personal repository dedicated to organizing C++ source code, experiments, and cheat sheets. 

Also featuring Also featuring [mini-games](https://github.com/0xSickb0y/CPPCodeDump/tree/main/games)!

### Structure of a C++ Program
```cpp
#include <iostream> // Standard I/O library
// Every C++ program consists of one or more functions.
// The main() function is the entry point of a C++ program.
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
// Statements in C++ end with a semicolon ;
```

### Using namespaces

```cpp
#include <iostream>

// Using Namespaces
namespace MyNamespace {
    int value = 42;

    void display() {
        std::cout << "Value: " << value << std::endl;
    }
}

int main() {
    // Using a namespace with scope resolution operator
    MyNamespace::display(); // Calls display function from MyNamespace

    // Using directive to bring all members into the current scope
    using namespace MyNamespace;
    display(); // No need to qualify with MyNamespace
    std::cout << "Value: " << value << std::endl;

    // Caution with using namespace
    using std::cout; // Prefer to use specific names
    using std::endl;

    // Using in a specific scope
    void myFunction() {
        using namespace MyNamespace; // Only within this function
        display(); // Works without qualification
    }

    return 0;
}
```

### Data Types
```cpp
int a;        // Integer data type
float b;      // Floating-point data type
double c;     // Double-precision floating-point data type
char d;       // Character data type
std::string str; // String data type
```

### Variables and Constants
```cpp
int variable = 5;        // Variables hold values that can change during program execution
const int CONSTANT = 10; // Constants are values that do not change during program execution
```

### Operators
```cpp
// Arithmetic operators: +, -, *, /, %
int sum = a + b;
int difference = a - b;
int product = a * b;
int quotient = a / b;
int remainder = a % b;

// Relational operators: ==, !=, <, >, <=, >=
if (a == b) { /*...*/ }
if (a != b) { /*...*/ }
if (a < b)  { /*...*/ }
if (a > b)  { /*...*/ }
if (a <= b) { /*...*/ }
if (a >= b) { /*...*/ }

// Logical operators: &&, ||, !
if (a && b) { /*...*/ }
if (a || b) { /*...*/ }
if (!a)     { /*...*/ }

// Assignment operators: =, +=, -=, *=, /=, %=
a = b;
a += b;
a -= b;
a *= b;
a /= b;
a %= b;
```

### Control Flow
```cpp
// if, else, else if: Conditional statements
if (condition) {
    // code
} else if (another_condition) {
    // code
} else {
    // code
}

// switch, case, default: Multi-branching conditional statement
switch (variable) {
    case 1:
        // code
        break;
    case 2:
        // code
        break;
    default:
        // code
        break;
}

// while, do-while, for: Looping constructs
while (condition) {
    // code
}

do {
    // code
} while (condition);

for (int i = 0; i < n; ++i) {
    // code
}
```

### Functions
```cpp
// Functions encapsulate a block of code.
return_type function_name(parameters) {
    // code
    return value; // Functions can return values using return.
}

// Lambda expressions (C++11 feature)
auto lambda = [](int a, int b) { return a + b; };
```

### Arrays and Vectors
```cpp
// Arrays are collections of elements of the same type.
int array[10]; // Arrays are zero-indexed.
array[0] = 1;  // Accessing array elements: array[index].

// std::vector: Dynamic array from STL
#include <vector>
std::vector<int> vec;
vec.push_back(1); // Add elements to vector
```

### Pointers and Smart Pointers
```cpp
// Pointers are variables that store memory addresses.
int *pointer;
pointer = &variable;  // Address of variable
*pointer = 10;        // Dereferencing pointer

// Smart pointers (C++11 feature)
#include <memory>
std::unique_ptr<int> ptr = std::make_unique<int>(10); // Unique pointer
std::shared_ptr<int> sharedPtr = std::make_shared<int>(20); // Shared pointer
```

### Memory Management
```cpp
#include <cstdlib>

int *ptr = (int *)malloc(sizeof(int)); // Allocates memory block
free(ptr); // Releases dynamically allocated memory

// C++ style allocation
ptr = new int; // Allocates memory
delete ptr; // Releases memory
```

### Structures and Unions
```cpp
// struct: Allows grouping of variables of different types.
struct Example {
    int integer;
    float decimal;
    char character;
};

// union: Similar to struct, but shares memory among its members.
union ExampleUnion {
    int integer;
    float decimal;
    char character;
};
```

### File Handling
```cpp
#include <fstream>
#include <iostream>

std::ofstream outfile("filename.txt");
outfile << "Hello, World!"; // Writing to file
outfile.close();

std::ifstream infile("filename.txt");
std::string line;
std::getline(infile, line); // Reading a line of text
infile.close();
```

### Preprocessor Directives
```cpp
#include <iostream> // #include: Includes header files.
#define PI 3.14    // #define: Defines constants and macros.

#ifdef DEBUG
// #ifdef, #ifndef, #endif: Conditional compilation directives.
#endif
```

### Bitwise Operators
```cpp
int a = 5, b = 3;
int result;

// &, |, ^, ~, <<, >>: Perform operations at bit level.
result = a & b;  // AND
result = a | b;  // OR
result = a ^ b;  // XOR
result = ~a;     // NOT
result = a << 1; // Left shift
result = a >> 1; // Right shift
```

### Function Pointers and Lambdas
```cpp
void (*func_ptr)(int);
void function(int a) {
    // code
}

func_ptr = &function; // Pointers that point to functions.
(*func_ptr)(5);       // Useful for implementing callback functions.

// Using lambdas as function objects
auto lambda = [](int x) { return x * x; };
```

### Multi-dimensional Arrays
```cpp
// Arrays with more than one dimension.
int matrix[3][4];
matrix[0][0] = 1; // Accessing elements: matrix[row][col]

// std::vector for multi-dimensional dynamic arrays
std::vector<std::vector<int>> matrix(3, std::vector<int>(4));
```

### Dynamic Memory Allocation
```cpp
#include <cstdlib>

int *ptr = (int *)malloc(10 * sizeof(int));  // Allocating memory at runtime
free(ptr); // Releasing allocated memory

// C++ style dynamic allocation
int *arr = new int[10]; // Allocating array
delete[] arr; // Releasing array
```

### Command Line Arguments
```cpp
int main(int argc, char *argv[]) {
    // Accessing arguments passed to main() function.
    std::cout << "Number of arguments: " << argc << std::endl;
    for (int i = 0; i < argc; i++) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }
    return 0;
}
```

### Header Files
```cpp
// Organizing code into reusable modules.
// myheader.h
#ifndef MYHEADER_H
#define MYHEADER_H

void myFunction();

#endif

// mysource.cpp
#include "myheader.h"
void myFunction() {
    // code
}

// main.cpp
#include "myheader.h"
int main() {
    myFunction();
    return 0;
}
```

### Classes and Objects
```cpp
// Classes are user-defined types that encapsulate data and functions.
class MyClass {
public:
    int data;
    void display() {
        std::cout << "Data: " << data << std::endl;
    }
};

MyClass obj; // Creating an object of MyClass
obj.data = 10;
obj.display();
```

### Constructors and Destructors
```cpp
class MyClass {
public:
    MyClass() { // Constructor
        std::cout << "Constructor called!" << std::endl;
    }
    
    ~MyClass() { // Destructor
        std::cout << "Destructor called!" << std::endl;
    }
};

MyClass obj; // Constructor called when object is created
```

### Inheritance
```cpp
class Base {
public:
    void display() {
        std::cout << "Base class" << std::endl;
    }
};

class Derived : public Base { // Derived class inherits from Base
public:
    void show() {
        std::cout << "Derived class" << std::endl;
    }
};

Derived obj;
obj.display(); // Accessing base class method
```

### Polymorphism
```cpp
class Base {
public:
    virtual void show() { // Virtual function for polymorphism
        std::cout << "Base class show" << std::endl;
    }
};

class Derived : public Base {
public:
    void show() override { // Override the base class method
        std::cout << "Derived class show" << std::endl;
    }
};

Base* b = new Derived();
b->show(); // Calls Derived's show() due to polymorphism
delete b; // Clean up
```

### Function Overloading
```cpp
void display(int a) {
    std::cout << "Integer: " << a << std::endl;
}

void display(double b) {
    std::cout << "Double: " << b << std::endl;
}

display(5);     // Calls display(int)
display(5.5);   // Calls display(double)
```

### Operator Overloading
```cpp
class Complex {
public:
    float real;
    float imag;

    Complex operator+(const Complex& other) { // Overloading + operator
        Complex temp;
        temp.real = real + other.real;
        temp.imag = imag + other.imag;
        return temp;
    }
};

Complex c1, c2, result;
result = c1 + c2; // Uses overloaded + operator
```

### Templates
```cpp
// Function template
template <typename T>
T add(T a, T b) {
    return a + b;
}

// Class template
template <typename T>
class Container {
public:
    T value;
    Container(T val) : value(val) {}
};

Container<int> intContainer(10); // Instantiating class template
Container<double> doubleContainer(10.5);
```

### Standard Template Library (STL)
```cpp
#include <vector>
#include <algorithm>

std::vector<int> vec = {1, 2, 3, 4, 5};
std::sort(vec.begin(), vec.end()); // Sorting using STL
```

### Exception Handling
```cpp
try {
    throw std::runtime_error("An error occurred");
} catch (const std::runtime_error& e) {
    std::cout << "Caught: " << e.what() << std::endl;
}
```

### Auto Keyword
```cpp
auto x = 10; // Automatically deduces type
auto y = 3.14; // Deduction to double
```

### nullptr
```cpp
int* ptr = nullptr; // null pointer (C++11 feature)
```

### Range-Based for Loops (C++11)
```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};
for (auto& element : vec) {
    std::cout << element << std::endl; // Iterating over a vector
}
```

### Lambda Expressions
```cpp
auto lambda = [](int a, int b) { return a + b; };
std::cout << lambda(5, 3) << std::endl; // Using the lambda
```

### Type Traits and Static Assertions (C++11)
```cpp
#include <type_traits>

static_assert(std::is_integral<int>::value, "Must be integral"); // Compile-time assertion
```

### Move Semantics and rvalue References (C++11)
```cpp
class MyClass {
public:
    MyClass(MyClass&& other) { // Move constructor
        // Transfer resources
    }
};

MyClass obj = MyClass(); // Uses move semantics
```
