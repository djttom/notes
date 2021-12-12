# C++ Notes

## References
cplusplus [**tutorial**](https://www.cplusplus.com/doc/totorial) and [**reference**](https://www.cplusplus.com/doc/reference)

## Basics
### Hello World in c++
```c++
#include <iostream>

int main() {
    std::count << "Hello World!\n";
}
```
```c++
// the minimal c++ program
int main() {}
```

### Name Visibility and Namespace
Variables with block scope are known as local variables.

The syntax to declare a namespace is:
```
namespace identifier
{
    named_entities
}
```
Use the scope operator :: to access variables outside the namespace.
```
myNamespace::a
myNamespace::b
```
The keyword `using` introduces a name into current code block. 
```
using namespace std;
cout << x << ‘\n’
cout << y << ‘\n’ 
```

### Variable Initialization
The c++ supports 3 kinds of initialization.
```
type identifier = initial_value;    // assignment initialization
type identifier (initial_value);    // constructor initialization 
type identifier {initial_value};    // uniform initialization (in c++2011)
```


c++ supports a couple of ways of [variable assignment and initialization](https://www.learncpp.com/cpp-tutorial/variable-assignment-and-initialization/)
```
int a;      // declare without initialization 
int a = 5;  // copy initialization, direct copy assignment of value 5 into variable a
int a (5);  // direct contructor initialization in parenthesis
int a {5};  // list/uniform/brace initialization in braces 
int a {};   // value initialization with 0 or empty depending on type
int a {0};  // zero initialization 

Best practice: Initialize variables upon creation; Initialization using braces whenever possible.

Type deduction with auto and decltype.
The compiler can automatically figure out the type of variable by the initializer. For example,
int x = 0; auto y = x;
int x = 0; decltype(x) y;  // same as int y;
```

## Misc
### smart pointers
A pointer points to an object but it does not indicate who owns the object, i.e., the ownership of the object.  
The smart pointers defined in **\<memory\>** are containers for pointer with ownership reference count.
- `unique_ptr`: represents exclusive ownership allows exact one owner of the underlying pointer.
- `shared_ptr`: represents shared ownership of pointer to object and maintains use reference count with all copies of the shared_ptr. 
- `weak_ptr`: represents copy of shared_ptr and has access to pointer to object but ownership, does not use reference count.

```c++
std:shared_ptr<int> foo (new int(10));
std:shared_ptr<int> foo = std::make_shared<int> (10);
```
