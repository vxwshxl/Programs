# C++ Prerequisites

This document lists every concept you need to understand the programs in this folder.
The programs range from simple number-logic problems to full Object-Oriented Programming
(OOP) topics, templates, file handling, and exception handling.

---

## 1. Basic Language Fundamentals

These are needed for almost every program (e.g. *dividend and divisor*, *reverse of a number*,
*sum of digits*, *factors*, *prime check*, *power without predefined function*).

- **Structure of a C++ program** — `#include`, `int main()`, `return 0;`
- **Header files** — `<iostream>`, `<conio.h>`, `<cmath>`, `<cstring>`, `<fstream>`, `<iomanip>`
- **Namespaces** — `using namespace std;`
- **Input / Output** — `cin`, `cout`, `<<` (insertion), `>>` (extraction), `endl`
- **Data types** — `int`, `float`, `double`, `char`, `bool`, `long`
- **Variables, constants and literals**
- **Operators**
  - Arithmetic (`+ - * / %`)
  - Relational (`< > <= >= == !=`)
  - Logical (`&& || !`)
  - Assignment & compound (`= += -= *= /= %=`)
  - Increment / decrement (`++`, `--`)
  - Modulus `%` (used heavily for digits, factors, even/odd)
- **Type casting** (implicit and explicit)
- **Operator precedence and associativity**

## 2. Control Flow

Used in number programs like *prime numbers 1 to n*, *Pascal triangle*, *Krishnamurthy number*,
*magic matrix*, *Armstrong number*, *factorial*, *Fibonacci*.

- **Conditional statements** — `if`, `if-else`, `else-if` ladder, nested `if`
- **switch-case**
- **Loops** — `for`, `while`, `do-while`
- **Nested loops** (patterns, matrices, tables)
- **Jump statements** — `break`, `continue`, `return`
- **Ternary operator** `?:`

## 3. Functions

Needed for *sum of fractional series (function)*, *bubble sort with function overriding*,
*GCD using friend function*, *function overloading* programs.

- **Function declaration, definition and calling**
- **Function parameters** — pass by value, pass by reference (`&`), pass by pointer
- **Return values**
- **Default arguments**
- **Function prototypes**
- **Recursion** (factorial, Fibonacci, power)
- **Scope of variables** — local vs global
- **`inline` functions**
- **Function overloading** — same name, different parameters
  *(used in: cft and price, largest of three, etc.)*

## 4. Arrays and Strings

Used in *smallest and largest in array*, *linear search*, *reverse array*, *matrices*,
*string length*, *concatenate strings*, *strcmp*, *uppercase conversion*.

- **One-dimensional arrays**
- **Two-dimensional arrays** (matrices — add, transpose, magic matrix)
- **Array traversal, searching and sorting** (bubble sort, linear search)
- **C-style strings** (`char[]`) and string functions
  - `strlen()`, `strcpy()`, `strcat()`, `strcmp()`
- **String I/O** — `cin.getline()`, `gets()` / `puts()` (legacy)
- **ASCII values** (used in lowercase→uppercase conversion)

## 5. Pointers and Memory

Needed for *uses of this pointer*, *dynamic constructor*, *swap using pointers*.

- **Pointers basics** — `*`, `&`, dereferencing
- **`this` pointer**
- **Dynamic memory allocation** — `new` and `delete`
- **References vs pointers**

## 6. Object-Oriented Programming (Core)

This is the heart of most programs in this folder.

### 6.1 Classes and Objects
- **Class definition**, **objects**, **members** (data + functions)
- **Access specifiers** — `private`, `public`, `protected`
- **Member functions** — inside vs outside class (`::` scope resolution)
- **Data hiding & encapsulation**
- **Abstraction**

### 6.2 Constructors and Destructors
*(factorial/multiplication table using constructors, destructor programs, swap with destructor)*
- **Constructor** — same name as class, no return type
- **Types of constructors**
  - Default constructor
  - Parameterized constructor
  - Copy constructor
  - **Dynamic constructor** (uses `new` for allocation)
- **Constructor overloading**
- **Destructor** — `~ClassName()`, called automatically, releases resources
- **Order of construction and destruction**

### 6.3 Static Members
*(sum of nth terms using static members)*
- **Static data members** — shared across all objects
- **Static member functions**

### 6.4 Friend Functions
*(GCD using friend function, transpose matrix)*
- **Friend function** — non-member with access to private data
- **Friend classes**

## 7. Inheritance

Many programs are built specifically to demonstrate inheritance types.

- **Base class and derived class**
- **Modes of inheritance** — `public`, `private`, `protected`
- **Types of inheritance**
  - **Single inheritance** *(Armstrong number)*
  - **Multiple inheritance** *(circle properties)*
  - **Multilevel inheritance** *(Fibonacci series)*
  - **Hierarchical inheritance** *(add two matrices)*
  - **Hybrid inheritance** *(transpose matrix)*
- **Constructor calling order in inheritance**
- **Ambiguity in multiple inheritance**
- **Virtual base class** *(pattern program)* — solves the diamond problem

## 8. Polymorphism

- **Compile-time (static) polymorphism**
  - **Function overloading**
  - **Operator overloading** *(decimal to binary, this folder)*
  - **Function overriding** *(bubble sort)*
- **Run-time (dynamic) polymorphism**
  - **Virtual functions** *(area of circle, reverse array)*
  - **`virtual` keyword**, vtable concept
  - **Pure virtual functions & abstract classes** (concept)
- **Operator overloading**
  - Overloading operators using member / friend functions
  - `operator+`, `operator<<`, etc.

## 9. Templates (Generic Programming)

*(largest of three, odd or even, sum of nth terms, circle and rhombus perimeter)*
- **Function templates** — `template <class T>`
- **Class templates**
- **Template with multiple parameters**
- Why templates → write once, use for many data types

## 10. File Handling

*(rectangle perimeter to file, linear search to file, string to file, sum of odd/even to files,
leap year check, prime numbers to file)*
- **File streams** — `ifstream`, `ofstream`, `fstream`
- **Opening modes** — `ios::in`, `ios::out`, `ios::app`, `ios::trunc`
- **Writing to a file** (`<<`) and **reading from a file** (`>>`, `getline`)
- **`open()` and `close()`**
- **Checking if file opened** (`is_open()`, `eof()`)

## 11. Exception Handling

*(divide by zero exception handling)*
- **`try`, `catch`, `throw`**
- **Multiple catch blocks**
- **Standard exceptions** (concept)
- Why exceptions → graceful error handling at run time

## 12. Mathematical / Logical Concepts

Background knowledge for the number-based programs:

- **Quotient & remainder** (division algorithm)
- **Reversing a number / sum of digits** (using `% 10` and `/ 10`)
- **Factorial, GCD, factors, prime numbers**
- **Fibonacci series**
- **Armstrong number, Krishnamurthy number**
- **Number base conversions** — decimal ↔ binary
- **Series summation** — fractional series, sin(x) via Taylor series
- **Pascal's triangle, magic matrix**
- **Power computation** (without `pow()`)
- **Unit conversions** — hours→minutes/seconds, CFT (cubic feet) and pricing
- **Geometry** — circle, rectangle, rhombus (area, perimeter), leap year logic

## 13. Tools & Environment

- A C++ compiler — **g++ (GCC)**, **Turbo C++**, or any IDE (Code::Blocks, Dev-C++, VS Code)
- Note: `<conio.h>` and `getch()`/`clrscr()` are **Turbo C++ specific** and not standard C++
- Compiling from terminal:
  ```bash
  g++ "1. dividend and divisor - quotient and remainder.cpp" -o program
  ./program
  ```

---

### Quick Concept-to-Program Map

| Concept | Example Program |
|---|---|
| Basic I/O & operators | 1, 2, 3, 33 |
| Constructors | 7, 15, 16 |
| Dynamic constructor | 15, 16 |
| Destructor | 18, 41, 48 |
| `this` pointer | 5 |
| Single inheritance | 34 |
| Multiple inheritance | 19 |
| Multilevel inheritance | 30 |
| Hierarchical inheritance | 26 |
| Hybrid inheritance | 27 |
| Virtual base class | 47 |
| Function overloading | 25 |
| Function overriding | 11 |
| Operator overloading | 32 |
| Virtual function | 45, 46 |
| Friend function | 23, 27 |
| Static members | 35 |
| Function template | 42, 43 |
| Class template | 28, 44 |
| File handling | 22, 29, 31, 40, 49, 52 |
| Exception handling | 20 |
| Arrays / matrices | 14, 26, 27, 56 |
| Strings | 36, 37, 38, 31 |
