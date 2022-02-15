
# Table of Content 
1. [Overview](#overview)
2. [Special Variables](#special-variables)
3. [Function](#function)
4. [Builtin Commands](#builtin-commands)
5. [Reference](#reference)

## Overview
The default shell in linux `/bin/sh` is called bash (Bourne-Again Shell), is a link to the program `/bin/bash`.  
The first line of shell scrip is `#!/bin/sh` or `#!/usr/bin/env bash`
```
#! /usr/bin/env bash
set -euo pipefail       # set for quick debug information
IFS=$’\n\t’             # use newline or tab as Internal Field Separator
...
```

## Special Variables
```
$HOME, $PATH, $PS1, $PS2,                                                     
number 0,1,2 represents stdin,stdout,stderr stream respectively               
$0    name of the shell script.                                               
$1, $2, ... ${10} are 1st, 2nd, ... 10th argument                             
$#    number of arguments                                                     
$*    all arguments, in a single variable, seperated by the first character in $IFS
$@    all arguments, a subtle variation on $*, without using IFS, Input Field Separator.
$$    process ID of the shell script.                                         
$?    exit status of the last command. 0 indicates success w/o error, non-0 indicates error.
```
Examples
```
true
echo $?     # print 0
false    
echo $?     # print non-0, usually print 1
```

## Flow Control
### if/then/elif/else/fi                                                          
```             
if expression                     if expression; then                           
then                                  statements                                
    statements                    elif expression; then                         
elif expression                       statements                                
then                              else                                          
    statements                        statements                                
else                              fi                                            
fi
```

### for/do/done, while/do/done, util/do/done, break/continue
```
for variable in values       while condition          until conidtion           
do                           do                       do                        
    statements                   statements               statements            
done                             break                done                      
                                 continue                                       
                             done

for x in 1 2 3 4 5
do
    echo "value of x is $x"
done
    
for i in /etc/rc.*; do
    echo $i
done
cat file.txt | while read line; do
    echo $line
done

case $foo in                                                                    
a)                                                                              
    echo "foo is A"                                                             
    ;;                                                                          
b)                                                                              
    echo "foo is B"                                                             
    ;;                                                                          
cd | d)                                                                         
    echo "foo is c or d"                                                        
    ;;                                                                          
*)                                                                              
    echo "foo is $foo"                                                          
    ;;                                                                          
esac
```

## Function
- A function must always be defined before you can invoke it.                   
- The positional parameters $*, $@, , $1, $2, and so on are replaced by the     
  parameters to the function.                                                   
- Declare the local variables within shell functions by using the local keyword.
Example:                                                                      
```                                                                           
function_name () {                                                              
    statements                                                                  
}
```

## Builtin Commands
- let, ls, cat, cd, echo, pwd, chmod, chown, mkdir, mv, rm, exit                
- break, continue, : (a null command), . command, echo, eval, exec,             
- exit n, export, expr, printf, return, set, shift, trap, unset.                
- Two external commands: find and grep                                          
- find syntax: find [path] [options] [tests] [actions]                          
- grep syntax: grep [options] PATTERN [files] 

## Reference 
[Google shell style](https://google.github.io/styleguide/shell.xml)
[Shell Programming](http://matt.might.net/articles/bash-by-example/)
