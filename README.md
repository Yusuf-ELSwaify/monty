# Monty Interpreter

A scripting language interpreter built in the C language written as part of the [low-level programming](https://github.com/Yusuf-ELSwaify/alx-higher_level_programming) in Software Engineering track at ALX.

## 0x19. C - Stacks, Queues - LIFO, FIFO

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

``` monty
 push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
```

# Usage

Compile all C files using:

``` bash
 gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

To run the program:

``` bash
 ./monty bytecode_file
```

# Examples

### Some examples of using monty and its console output.

|                        Example #1                      |                    Example #2                   |                      Example #3                           |
|:-------------------------------------------------------|:------------------------------------------------|:----------------------------------------------------------|
| ~/monty$ `cat -e bytecodes/00.m` <br> push 1$ <br> push 2$ <br> push 3$ <br> pall$ <br> ~/monty$ `./monty bytecodes/00.m` <br> 3 <br> 2 <br> 1  | ~/monty$ `cat bytecodes/07.m`  <br> push 1 <br> push 2 <br> push 3 <br> pall <br> pop <br> pall <br> pop <br> pall <br> pop <br> pall <br>  ~/monty$ `./monty bytecodes/07.m`  <br> 3 <br> 2 <br> 1 <br> 2 <br> 1 <br> 1 | ~/monty$ `cat bytecodes/09.m` <br> push 1 <br> push 2 <br> push 3 <br> pall <br> swap <br> pall <br> ~/monty$ `./monty bytecodes/09.m` <br> 3 <br> 2 <br> 1 <br> 2 <br> 3 <br> 1 |

# Available Operations:

| Opcode | Description                                                                                                                                                                                        |
| ------ | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| push   | Pushes an element to the stack. Usage: push &lt;int&gt;|
| pall   | Prints all the values on the stack, starting from the to of the stack.|
| pint   | Prints the value at the top of the stack.|
| pop    | Removes the to element of the stack.|
| swap   | Swaps the top to elements of the stack.|
| nop    | This opcode does not do anything.|
| add    | Adds the top two elements of the stack. The result is then stored in the second node, and the first node is removed.|
| sub    | Subtracts the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.|
| div    | Divides the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.|
| mul    | Multiplies the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.|
| mod    | Computes the remainder of the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.|
| pchar  | Prints the integer stored in the top of the stack as its ascii value representation.|
| pstr   | Prints the integers stored in the stack as their ascii value representation. It stops printing when the value is 0, when the stack is over and when the value of the element is a non-ascii value.|
| rotl   | Rotates the top of the stack to the bottom of the stack.|
| rotr   | Rotates the bottom of the stack to the top of the stack.|
| queue  | Sets the format of the data into a queue (FIFO).|
| stack  | This is the default behavior. Sets the format of the data into a stack (LIFO).|
| #      | When the first non-space of a line is a # the line will be trated as a comment.


## Authors

* Yusuf EL-Swaify <[Yusuf-ELSwaify](https://github.com/Yusuf-ELSwaify)>
* Haidy Yasser <[Haidyasser](https://github.com/Haidyasser)>
