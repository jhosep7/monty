#include "monty.h"

/**
 * op_swap - swaps the top two elements of the stack
 * @stack: the opcode
 * @lnum: value
 * Return: Void
 */
void op_swap(stack_t **stack, unsigned int lnum)
{
	stack_t *Temp;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", lnum);
		exit(EXIT_FAILURE);
	}

	Temp = (*stack)->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = Temp->next;
	Temp->prev = NULL;
	(*stack)->prev = Temp;

	if (Temp->next)
		Temp->next->prev = *stack;

	Temp->next = *stack;
	(*stack) = (*stack)->prev;
}

/**
 * op_add - adds the top two elements of the stack
 * @stack: the opcode
 * @lnum: value
 * Return: Void
 */
void op_add(stack_t **stack, unsigned int lnum)
{
	int Temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", lnum);
		exit(EXIT_FAILURE);
	}

	Temp = (*stack)->n;
	op_pop(stack, lnum);
	(*stack)->n += Temp;
}

/**
 * op_nop - doesnt do anything
 * @stack: the opcode
 * @lnum: value
 * Return: Void
 */
void op_nop(stack_t **stack, unsigned int lnum)
{
	UNUSED(stack);
	UNUSED(lnum);
}

/**
 * op_sub - subtracts the top element of the stack
 * from the second top element of the stack
 * @stack: the opcode
 * @lnum: value
 * Return: Void
 */
void op_sub(stack_t **stack, unsigned int lnum)
{
	int Temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", lnum);
		exit(EXIT_FAILURE);
	}

	Temp = (*stack)->n;
	op_pop(stack, lnum);
	(*stack)->n -= Temp;
}

/**
 * op_mul - multiplies the second top element of the
 * stack with the top element of the stack
 * @stack: the opcode
 * @lnum: value
 * Return: Void
 */
void op_mul(stack_t **stack, unsigned int lnum)
{
	int Temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", lnum);
		exit(EXIT_FAILURE);
	}

	Temp = (*stack)->n;
	op_pop(stack, lnum);
	(*stack)->n *= Temp;
}

