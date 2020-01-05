# 0x19. C - Stacks, Queues - LIFO, FIFO
## Monty
___

## General Learning Objetives
- What do LIFO and FIFO mean
- What is a stack, and when to use it
- What is a queue, and when to use it
- What are the common implementations of stacks and queues
- What are the most common use cases of stacks and queues
- What is the proper way to use global variables

## Intro
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

Monty byte code files
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

## Usage

1. Compile the program
`gcc -Wall -Werror -Wextra -pedantic *.c -o monty`

2. Run the program as follows:
-  `monty <file.m>`
-  `./monty ./bytecodes/file.m`

## Example
```
HolbyPeer-Lenovo$ cat bytecodes/19.m
push 1
push 2
push 10
push 3
sub
pall
HolbyPeer-Lenovo$ ./monty bytecodes/19.m 
7
2
1
HolbyPeer-Lenovo$
---
```
### Authors
* **Andrea Mendez** - [andreammgcol](https://github.com/andreammgcol)
* **Jose Diaz** - [jhosep7](https://github.com/jhosep7)

