#ifndef _MONTY_H_
#define _MONTY_H_

#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct MyVar - opcode and its function
 * @keeper: saves the status of a variable
 * @test: checks status when needed int - char
 * Description: Reusable Variable
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct MyVar
{
int keeper;
char test;
} MyVar_t;

extern MyVar_t GlobalV;
MyVar_t GlobalV;

/*get_opcode.c*/
void get_opcode(char *tkn, stack_t **stack, int lnum);

/*main.c*/
void TokenFun(char *Temp, stack_t **stack, unsigned int lnum);
int NumberCheck(char *tkn);

/*opcodes_funct.c*/
void op_push(stack_t **stack, unsigned int num);
void op_pall(stack_t **stack, unsigned int num);
void op_pint(stack_t **stack, unsigned int lnum);
void op_pop(stack_t **stack, unsigned int num);

void FrStack(stack_t **stack, unsigned int lnum);

#endif
