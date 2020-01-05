#include "monty.h"

/**
 * op_push - pushes an element to the stack
 * @stack: the opcode
 * @lnum: value
 * Return: Void
 */
void op_push(stack_t **stack, unsigned int lnum)
{
	stack_t *NewND = NULL;

	if (!stack)
	{
		fprintf(stderr, "L%d: unknown stack\n", lnum);
		exit(EXIT_FAILURE);
	}

	NewND = malloc(sizeof(stack_t));
	if (!NewND)
	{
		fprintf(stderr, "Error: malloc failed\n"), FrStack(stack, lnum);
		exit(EXIT_FAILURE);
	}

	NewND->n = SharedVar.intvar;

	if (*stack)
	{(*stack)->prev = NewND; }
	NewND->next = *stack;
	NewND->prev = NULL;
	*stack = NewND;
}

/**
 * op_pall - prints all the values on the stack
 * @stack: the opcode
 * @lnum: value
 * Return: void
 */
void op_pall(stack_t **stack, unsigned int lnum)
{
	stack_t *MyPrint;

	if (!stack)
	{
		fprintf(stderr, "L%d: invalid stack\n", lnum);
		exit(EXIT_FAILURE);
	}
	MyPrint = *stack;
	while (MyPrint)
	{printf("%d\n", MyPrint->n), MyPrint = MyPrint->next; }
}
/**
 * op_pint - prints all the values on the stack
 * @stack: the opcode
 * @lnum: value
 * Return: void
 */
void op_pint(stack_t **stack, unsigned int lnum)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", lnum);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}
}

/**
 * op_pop - removes the top element of the stack.
 * @stack: the opcode
 * @lnum: value
 * Return: void
 */
void op_pop(stack_t **stack, unsigned int lnum)
{
	stack_t *Temp = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", lnum);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(Temp);
	if (*stack)
		(*stack)->prev = NULL;
}

/**
 * op_pchar - prints the string starting at the top of the stack.
 * @stack: the opcode
 * @lnum: value
 * Return: void
 */
void op_pchar(stack_t **stack, unsigned int lnum)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", lnum);
		exit(EXIT_FAILURE);
	}
	if (isascii(SharedVar.intvar))
	{printf("%c\n", SharedVar.intvar); }
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", lnum);
		exit(EXIT_FAILURE);
	}
}
