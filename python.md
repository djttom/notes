# Python 3 note

## Introduction
In command line type python or python3.9 to start the interpreter.  
Type `ctrl+d` or `exit()` or `quit()` to exit the interpreter.  
The `import sys` to include the sys module. The arguments are in `sys.argv`.   
In interpreter interactive mode, type `help(<name>)` to get help information like `help(sys)` and `help(len)`.  

By default, Python source files are treated as encoded in UTF-8.  
A special comment is used to declare the encoding `# -*- coding: cp1252 -*-` 

The interpreter can be used as a calculator. Try the numbers, strings, lists, and etc.  
The division / always returns a float `8/5=1.6` while floor division gets an integer result `8//5=1`.  
The 'single', "double", '''triple''', """triple""" quotes are used for strings. 

#### List Example
The most versatile compound data type is the list, which can be written as a list of comma-separated values (items) between square brackets. The list supports the index from **0 for the first item or -1 for the last item**, slice, copy, assignment, nest. Some built-in functions like len() also apply to lists. 
Below is a small example of Python programming including assignment, while loop, and print.
```python
# Fibonacci series: (within 100) 
# The sum of two elements defines the next 
a, b = 0, 1
while a < 100: 
    print(a)
    a, b = b, a+b 
```

#### Coding Style in PEP 8
Important points in coding style from PEP 8 are below. 
- Use 4-space indentation. 
- Wrap lines so that they don’t exceed 79 characters. 
- Use blank lines to separate functions, class, and large blocks of code inside functions. 
- Use docstrings. 
- Use spaces around operators and after commas. 
- The convention is to use UpperCamelCase for classes and lowercase_with_underscores for functions and methods. 

## Control Flow tools 
Python control flow includes **if/elif/else, while, for, range(), break/continue/else, pass, function**. 
```python
words = [‘apple’, ‘peach’, ‘pear’]
for w in words:
    print(w, len(w)) 

for i in range(10): or for i in range(0,10,3):

while True: 
    pass  

# The code below prints whether a number less than 10 is a prime number or not. 
for n in range(2, 10):
    for x in range (2, n):
        if n % x == 0: 
             print(n, ‘equals’, x, ‘*’, n//x)
             break
    else: 
        print(n, ‘is a prime number’)
```

### Function 
It is possible to define functions with a variable number of arguments.  
`def ask_ok(prompt, retries=3, remainder='Please try again'): `

When a final parameter of form \*\*name is present, it receives a dictionary containing all keyword arguments.  
When a parameter of form *name is present, it receives a tuple containing the positional arguments.  
`def func(arg0, *args, **keyword_args):`

`def func(pos1, pos2, /, pos_or_word1, pos_or_word2, *, kwd1, kwd2): `  
If the / is present, then it is used to separate the positional-only arguments and the positional-or-keyword arguments.   
If no / is present, then there is no positional-only argument.  
The * is used to mark the keyword-only arguments after it. 

A function can be defined with an arbitrary number of arguments. These arguments will be wrapped in a tuple.  
Zero or more normal arguments can be placed before it. Any number of keyword-only arguments can be placed after it.  
The arbitrary \*\*name dictionary arguments should be the final parameter.  
`def arbit_func(arg0, arg1, *args, arg4=’a4’, arg5=’a5’, **kwargs): `

Function annotations are completely optional metadata information about the types used by user-defined functions. See PEP 3170 and PEP 484 for detail information. 
```python
def func(ham: str, eggs: str = ‘eggs’) -> str: 
    “”” function documentation string here “””
    print(“Annotations:”, func.__annotations__)
    print(“Arguments:”, ham, eggs)
    return ham + ‘ and ‘ + eggs
func(‘spam’)
Annotations: {‘ham’: <class ‘str’>, ‘return’: <class ‘str’>’, ‘eggs’: <class ‘str’>}
Arguments: spam eggs
spam and eggs 
```

## Data Structures - List, Tuple, Set, Dict
The built-in data structures include lists, tuples and sequence, sets, dictionaries, and etc.

### List
The list data type has some basic methods. Use help(list) to get the help information. They are `list.append(), list.extend(), list.insert(), list.remove(), list.pop(), list.clear(), list.index(), list.count(), list.reverse(), list.sort(), list.copy().`  
The lists can be used as stacks, where the last element added is the first element retrieved (last-in, first-out). The two methods are list.append() and list.pop().  
The lists can be used as queues too, where the first element added is the first element retrieved (first-in, first-out).  
List comprehensions provide a concise way to create lists from other iterables. A list comprehension consists of brackets containing an expression followed by a for clause, then zero or more for clauses and or if clauses.  
```python
squares = [x*x for x in range(10)] 
xy =  [(x,y) for x in [1,2,3] for y in [2,3,4] if x != y] 
The nested list comprehensions. 
[[row[i] for row in ll] for i in range(4)] where ll is a list of list. 

Its general syntax is below. 
[expression for item1 in iterable1 if condition1 
            for item2 in iterable2 if condition2
            … 
            for itemN in iterableN if conditionN]
It is roughly equivalent to the following code. 
s = []
for item1 in iterable1:
    if condition1: 
        for item2 in iterable2:
            if condition2:
                … 
                for itemN in iterableN:
                    if conditionN:
                        s.append(expression) 
```
Some Examples 
```python
nn = [-1, 0, 1, 2, 3, 4, 5] 
ss = [n * n for n in nn] 
ss = [n * n for n in nn if n > 0] 
ns = [n * s for n in nn for s in ss] 
ns = [(n, s) for n in nn for s in ss]
nn = [[0 for i in range(4)] for i in range(5)] 

The del statement can be used to remove an item from a list. 
a = range(10)   # create a list of 10 integers 0,1,...,9
del a[0]        # remove a[0] from list a 
del a[2:4]
del a[:]        # remove all items from a and now a is empty list 
del a           # list a is deleted. 
Tuples and Sequences 
A tuple consists of a number of values separated by commas. 
t = 123, 456, ‘hello’    # t is a tuple with three items. t[0] is 123, and etc.
x, y, z = t              # assignment from a tuple
et = ()                  # et is an empty tuple with len(et) = 0
t1 = 123,                # t1 is one item tuple with len(e1) = 1
```

### Sets 
A set is an unordered collection with no duplicate elements. Basic uses include membership testing. Set objects also support mathematical operations like union, intersection, difference, and symmetric difference. The set comprehensions are also supported. 
```python
s = {‘apple’, ‘peach’, ‘apple’, ‘orange’}   # s is a set of 3 elements
s = set()                # s is an empty set
s = set(‘abcdecde’)      # s is a set with 5 items {‘a’,’b’,’c’,’d’,’e’}
s = {x for x in ‘abcdecde’ if x not in ‘cd’}  # s is a set {‘a’,’b’,’e’} 
```

### Dictionaries 
A dictionary is a set of key: value pairs with the keys are unique within one dictionary. It is an error to extract a value using a non-existent key. 
```python
d = {‘jack’: 40, ‘tom’: 45, ‘david’: 25}  # d has 3 key-value pairs
d[‘jack’]       # item = 40 with key ‘jack’ 
del d[‘tom’]    # delete item ‘tom’:45
ed = {}         # ed is an empty dictionary or ed = dict() 
ks = list(d)    # ks is a list of keys of d 
‘jack’ in d     # return True
```

### Loop Techniques 
```python
for name, age in d.items():
    print(name, ‘age is’, age) 
for i, v in enumerate(iterable): 
    print(‘item’, i, ‘is’, v)
for v1, v2 in zip(s1, s2):    # s1 and s2 are iterable sequences 
    print(v1, ‘--’, v2) 
for i in reversed(range(1,10,2)):  
    print(i)                  # print out 9,7,5,3,1
for v in sorted(s1):          # print out sorted item while s1 unaltered
    print(v)
```

### Conditions 
In addition to while and if, there are other condition operators.  
The operators in and not in check whether a value occurs (does not occur) in a sequence.  
The operators is and is not compare two objects are really the same object.  
Comparisons can be chained. For example, a < b == c tests whether a is less than b and moreover b is equal to c.  
The comparison may be combined with boolean operators and and or, and may be negated with not.  
The assignment inside an expression in Python must be down with walrus operator :=. This is to avoid the problem in C that the = is used when == is intended.  
Sequence objects may be compared to other objects with the same sequence type. The comparison uses lexicographical ordering: first the first two items are compared, and if they diff this determines the outcome of the comparison. If they are equal, the next two items are compared, and so on.  

### Operators 
```
Arithmetic: +, -, *, /, %, **, //  
Assignment: =, +=, -=, *=, /=, %=, //=, **=, 
            &=, |=, ^=, <<=, >>=, >>>= 
Bitwise: &, |, ^ (XOR), <<, >>, ~ (one’s complement)  
Logical: and, or, not 
Relational: <, >, <=, >=, ==, != 
Ternary: ? : 
Identity: is, is not
Membership: in, not in 
```

## Modules and Packages
A module is a file containing Python definitions and statements. The file name is the module name with a suffix ***.py*** appended. Within a module, the module’s name is the string value of a global variable ***`__name__`***. The module name is used to access functions defined in a module with format `mod_name.item_name`. 

There are a few ways to import modules. The imported module names are placed in the importing module’s symbol table. 
```python
import fibo 
import fibo as fib 
# import names from a module directly into importing module’s symbol table
from fibo import *
from fibo import fibo1, fibo2
from fibo import fibo1 as fib1 
```

When you run a module as script, the code in the module is executed. It is like import it but with ***`__name__`*** set to ***`'__main__'`***. 
```
if __name__ == '__main__':
    import sys
    fib(int(sys.argv[1])) 
```

When a module is imported with its name, the interpreter first searches its built-in module with that name. It then searches a file named ***mod_name.py*** in a list of directories given by the variable ***sys.path***, which is initialized with the locations below.  
1. The directory containing the input script.  
2. The **PYTHONPATH** and the installation-dependent default.  
The directory containing the script being run is placed at the beginning of the search path, ahead of the standard library path. This means that the scripts in that directory will be loaded instead of modules of the same name in the library directory.  

To speed up loading modules, Python caches the compiled version of each module in directory `__pycache__` under the name `module.version.pyc`.  
For example, in CPython release 3.3 the compiled version of spam.py would be cached as `__pycache__/spam.cpython-33.pyc`. 

**Standard Modules and Built-in Functions**  
Python comes with a library of standard modules. Some modules are built into the interpreter. 
One particular module ***sys*** is built into every Python interpreter. 
```python
dir()         # list of names defined in current scope or in the given object 
import sys    # import sys module
dir(sys)      # list all names defined in sys module 
len(dir(sys)) # return number of names in sys module
sys.modules   # dictionary of all standard modules
help(‘modules’)   # list of all standard modules 
sys.ps1           # prompt string: >>>
sys.ps2           # prompt string: ... 
import builtins   # import module builtins 
dir(builtins)     # list names of built-in functions and variables 
dir(__builtins__) # same as above without import builtins 
```

### Packages 
Packages are a way of structuring Python’s module namespace by using "dotted module names". Python searches through the directories on ***sys.path*** looking for the package subdirectory.  
The `__init__.py` files are required to make Python treat the directories containing the file as packages. Below is an example of sound package structure. 
```python
sound/                      # top-level sound package 
    __init__.py             # initialize the sound package 
    formats/                # sub-package for file format conversion
        __init__.py
        waveread.py 
        wavewrite.py 
        … 
     effects/               # sub-package for sound effects 
        __init__.py 
        echo.py 
        surround.py
        …
    filters/                # sub-package for filters 
        __init__.py
        equalizer.py 
        vocoder.py
        … 

# Usages with the package**
import sound.effects.echo
sound.effects.echo.echofilter(input, output, delay=0.7, atten=4)
from sound.effects import echo 
echo.echofilter(input, output, delay=0.7, atten=4)
from sound.effects.echo import echofilter 
echofilter(input, output, delay=0.7, atten=4)
```

## Virtual Environment 
Each project should have its own packages separate from other projects.  
The virtual environment is created to have a space where we can install packages specific to a certain project.  
The following commands are used to create a virtual environment, activate it, install packages, and deactivate it.  
The conventional practice is to create venv under your project but do not put project files into the virtual environment directory.
```python
python --version
pip list 
mkdir myproj; cd myproj  # create project folder and enter into it
python -m venv venv      # create virtual env directory venv under my project
source venv/bin/activate
pip list
pip install -r requirements.txt  # install packages specified in text file
pip install Flask
pip list
pip freeze > requirements.txt  # save list of current packages into text file
deactivate
```

A guide to Python’s virtual environments 
<https://towardsdatascience.com/virtual-environments-104c62d48c54>

## Reference
[Python 3 tutorial](https://docs.python.org/3/tutorial/index.html)
