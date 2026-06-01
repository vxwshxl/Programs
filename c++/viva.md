# C++ Viva Questions (100 Questions with Answers)


Questions are grouped by topic and ordered roughly from basics to advanced,
matching the concepts used in the programs in this folder.

---

## A. Basics & Fundamentals

**1. What is C++?**
C++ is a general-purpose, object-oriented programming language developed by Bjarne Stroustrup
as an extension of the C language ("C with Classes").

**2. Who developed C++ and when?**
Bjarne Stroustrup at Bell Labs, around 1979–1983.

**3. What are the main features of C++?**
Object-oriented, portable, fast, supports OOP (encapsulation, inheritance, polymorphism),
has a rich standard library, and allows both procedural and object-oriented programming.

**4. What is the difference between C and C++?**
C is procedural; C++ supports both procedural and object-oriented programming. C++ adds classes,
objects, inheritance, polymorphism, function overloading, references, and exception handling.

**5. What is a header file?**
A file containing function declarations and macro definitions, included using `#include`.
Example: `<iostream>` for input/output.

**6. What is `using namespace std;`?**
It tells the compiler to use the standard namespace, so we can write `cout` instead of `std::cout`.

**7. What is the role of `main()`?**
It is the entry point of every C++ program; execution begins here.

**8. What are `cin` and `cout`?**
`cin` is the standard input stream (keyboard) using `>>`; `cout` is the standard output stream
(screen) using `<<`.

**9. What is `endl`?**
A manipulator that inserts a newline and flushes the output buffer.

**10. What are the fundamental data types in C++?**
`int`, `float`, `double`, `char`, `bool`, `void`, and modifiers like `long`, `short`, `unsigned`.

**11. What is the difference between `float` and `double`?**
`double` has higher precision (usually 8 bytes) than `float` (usually 4 bytes).

**12. What is type casting?**
Converting one data type to another, e.g. `(int)3.5` or `static_cast<int>(x)`.

**13. What is the modulus operator?**
`%` returns the remainder of integer division. Used to find digits, even/odd, factors.

**14. What is operator precedence?**
The order in which operators are evaluated in an expression (e.g. `*` before `+`).

**15. What is the ternary operator?**
`condition ? value_if_true : value_if_false;` — a shorthand for `if-else`.

---

## B. Control Flow

**16. What are control statements?**
Statements that control the flow of execution: decision-making (`if`, `switch`) and loops.

**17. Difference between `while` and `do-while` loop?**
`while` checks the condition before executing; `do-while` executes at least once before checking.

**18. What is the difference between `break` and `continue`?**
`break` exits the loop entirely; `continue` skips the current iteration and moves to the next.

**19. What is a nested loop?**
A loop inside another loop — used for patterns, matrices, and Pascal's triangle.

**20. What is an infinite loop?**
A loop whose condition never becomes false, e.g. `while(true)`.

**21. What is a switch statement?**
A multi-way branch that compares a variable against multiple `case` values.

---

## C. Functions

**22. What is a function?**
A block of code that performs a specific task and can be reused.

**23. What is function declaration vs definition?**
Declaration (prototype) tells the compiler the function's name, return type, and parameters;
definition contains the actual body.

**24. What is the difference between call by value and call by reference?**
Call by value passes a copy (original unchanged); call by reference passes the actual variable
(original can be modified).

**25. What is recursion?**
A function that calls itself. Used for factorial, Fibonacci, and power calculation.

**26. What is a default argument?**
A parameter that takes a default value if no argument is passed during the call.

**27. What is an inline function?**
A function whose code is inserted at the call site to reduce function-call overhead, declared
with the `inline` keyword.

**28. What is function overloading?**
Defining multiple functions with the same name but different parameter lists. Resolved at compile time.

**29. What is function overriding?**
Redefining a base class function in the derived class with the same signature.

**30. What is the difference between overloading and overriding?**
Overloading = same name, different parameters (compile-time); overriding = same signature in
base & derived (run-time, needs inheritance).

**31. What is variable scope?**
The region where a variable is accessible — local (inside a block) or global (whole program).

---

## D. Arrays & Strings

**32. What is an array?**
A collection of elements of the same data type stored in contiguous memory locations.

**33. What is the index of the first array element?**
0 (zero-based indexing).

**34. What is a two-dimensional array?**
An array of arrays, used to represent matrices (rows × columns).

**35. What is linear search?**
Searching for an element by checking each item sequentially from start to end.

**36. What is bubble sort?**
A sorting algorithm that repeatedly swaps adjacent elements if they are in the wrong order.

**37. How are strings represented in C++?**
As character arrays (C-style strings) ending with a null character `\0`, or using the `string` class.

**38. What does `strlen()` do?**
Returns the length of a string (number of characters before `\0`).

**39. What does `strcmp()` do?**
Compares two strings; returns 0 if equal, negative/positive otherwise.

**40. What does `strcat()` do?**
Concatenates (joins) two strings.

**41. What is an ASCII value?**
A numeric code representing a character (e.g. 'A' = 65, 'a' = 97). Used to convert case.

---

## E. Pointers & Memory

**42. What is a pointer?**
A variable that stores the memory address of another variable.

**43. What is the `this` pointer?**
An implicit pointer available in every non-static member function that points to the current object.

**44. What is dynamic memory allocation?**
Allocating memory at run time using `new` and freeing it using `delete`.

**45. What is the difference between `new` and `malloc()`?**
`new` is a C++ operator that also calls the constructor; `malloc()` is a C function that only
allocates raw memory.

**46. What is a memory leak?**
Memory allocated with `new` but never freed with `delete`, wasting memory.

**47. What is the difference between a reference and a pointer?**
A reference is an alias for an existing variable and cannot be null or reassigned; a pointer holds
an address and can be reassigned.

---

## F. Classes & Objects (OOP Core)

**48. What is OOP?**
Object-Oriented Programming — a paradigm based on objects that combine data and functions.

**49. What are the four pillars of OOP?**
Encapsulation, Abstraction, Inheritance, and Polymorphism.

**50. What is a class?**
A user-defined data type that acts as a blueprint for creating objects.

**51. What is an object?**
An instance of a class.

**52. What are access specifiers?**
`private`, `public`, and `protected` — they control the visibility of class members.

**53. What is the default access specifier in a class?**
`private`.

**54. What is encapsulation?**
Wrapping data and functions into a single unit (class) and restricting direct access to data.

**55. What is data hiding?**
Keeping data members `private` so they can only be accessed through member functions.

**56. What is abstraction?**
Showing only essential features and hiding implementation details.

**57. What is the scope resolution operator?**
`::` — used to define a member function outside the class and to access global/static members.

**58. What is the difference between a structure and a class?**
In a `struct`, members are `public` by default; in a `class`, they are `private` by default.

---

## G. Constructors & Destructors

**59. What is a constructor?**
A special member function with the same name as the class, automatically called when an object is
created. It has no return type.

**60. What are the types of constructors?**
Default, parameterized, copy, and dynamic constructors.

**61. What is a default constructor?**
A constructor with no parameters.

**62. What is a parameterized constructor?**
A constructor that takes arguments to initialize an object.

**63. What is a copy constructor?**
A constructor that creates a new object as a copy of an existing object; takes a reference to the
same class as parameter.

**64. What is a dynamic constructor?**
A constructor that allocates memory dynamically (using `new`) when an object is created.

**65. What is constructor overloading?**
Having multiple constructors in the same class with different parameter lists.

**66. What is a destructor?**
A special member function (`~ClassName()`) called automatically when an object is destroyed; used
to release resources. It has no parameters and no return type.

**67. Can a constructor be overloaded? Can a destructor?**
Constructors can be overloaded; destructors cannot (only one per class).

**68. What is the order of constructor and destructor calls?**
Constructors are called in order of object creation; destructors are called in reverse order.

**69. Can a constructor be virtual?**
No, constructors cannot be virtual. Destructors can and often should be virtual in base classes.

---

## H. Static & Friend

**70. What is a static data member?**
A class member shared by all objects of the class; only one copy exists, regardless of object count.

**71. What is a static member function?**
A function that can access only static members and is called using the class name.

**72. What is a friend function?**
A non-member function granted access to the private and protected members of a class using the
`friend` keyword.

**73. What are the characteristics of a friend function?**
It is not a member, is declared inside the class with `friend`, but defined outside; it can access
private data and is not called using an object.

**74. What is a friend class?**
A class whose members can access the private/protected members of another class.

---

## I. Inheritance

**75. What is inheritance?**
The mechanism by which one class (derived) acquires the properties and behavior of another class (base).

**76. What are the advantages of inheritance?**
Code reusability, extensibility, and easier maintenance.

**77. What is a base class and a derived class?**
The base (parent) class is inherited from; the derived (child) class inherits from it.

**78. What are the types of inheritance?**
Single, multiple, multilevel, hierarchical, and hybrid inheritance.

**79. What is single inheritance?**
One derived class inherits from one base class.

**80. What is multiple inheritance?**
A class inherits from more than one base class.

**81. What is multilevel inheritance?**
A class is derived from another derived class (a chain).

**82. What is hierarchical inheritance?**
Multiple derived classes inherit from a single base class.

**83. What is hybrid inheritance?**
A combination of two or more types of inheritance.

**84. What is the diamond problem?**
An ambiguity in multiple inheritance where a class inherits the same base twice through two paths;
solved using a virtual base class.

**85. What is a virtual base class?**
A base class declared `virtual` so that only one copy of its members is inherited, avoiding ambiguity.

**86. What is the order of constructor calls in inheritance?**
Base class constructor is called first, then the derived class constructor.

---

## J. Polymorphism

**87. What is polymorphism?**
The ability of a function or object to take multiple forms ("one name, many forms").

**88. What are the types of polymorphism?**
Compile-time (static) via overloading; run-time (dynamic) via virtual functions/overriding.

**89. What is a virtual function?**
A member function declared with `virtual` in the base class, allowing it to be overridden and
resolved at run time (dynamic binding).

**90. What is a pure virtual function?**
A virtual function with no definition, declared as `virtual void f() = 0;`. It makes the class abstract.

**91. What is an abstract class?**
A class with at least one pure virtual function; it cannot be instantiated.

**92. What is the difference between early binding and late binding?**
Early (static) binding is resolved at compile time; late (dynamic) binding is resolved at run time
using virtual functions.

**93. What is operator overloading?**
Giving an existing operator a new meaning for user-defined types (objects).

**94. Which operators cannot be overloaded?**
`.` (dot), `::`, `?:`, `sizeof`, and `.*`.

---

## K. Templates

**95. What is a template?**
A feature that allows writing generic code that works with any data type.

**96. What is a function template?**
A function defined with `template <class T>` that works for multiple data types.

**97. What is a class template?**
A class defined with a generic type parameter so objects can be created for different data types.

**98. What is the advantage of templates?**
Code reusability — write once and use with many data types, avoiding code duplication.

---

## L. File Handling & Exceptions

**99. What is file handling and which streams are used?**
Storing data permanently in files. C++ uses `ifstream` (read), `ofstream` (write), and `fstream`
(both), along with modes like `ios::in`, `ios::out`, and `ios::app`.

**100. What is exception handling in C++?**
A mechanism to handle run-time errors gracefully using `try` (code that may fail), `throw` (raise
an exception), and `catch` (handle it) — for example, handling a divide-by-zero error.

---

### Bonus Rapid-Fire

- **What is `iomanip` used for?** Formatting output (`setw`, `setprecision`).
- **What is `eof()`?** A function that returns true at the end of a file.
- **Is `conio.h` standard C++?** No, it is Turbo C++ / DOS specific (`getch()`, `clrscr()`).
- **What is the size of `int`?** Typically 2 or 4 bytes depending on the compiler.
- **What is a null character?** `'\0'`, marks the end of a C-style string.
