#include "monty.h"

/**
 * op_push - pushes an element to the stack
 * @stack: the opcode
 * @lnum: value
 * Return: Void
 */
void op_push(stack_t **stack, unsigned int lnum)
{
	stack_t *NewND;

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
	NewND->n = GlobalV.keeper;
	NewND->next = *stack;
	NewND->prev = NULL;

	if ((*stack))
	{(*stack)->prev = NewND; }
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
	if (!(*stack) || !stack)
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
	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", lnum);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next)
	{
		*stack = (*stack)->next, GlobalV.keeper = (*stack)->n;
		free((*stack)->prev), (*stack)->prev = NULL;
	}
	else
	{free(*stack), *stack = NULL; }
}
