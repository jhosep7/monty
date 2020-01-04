#include "monty.h"

/**
 * op_swap - swaps the top two elements of the stack
 * @stack: the opcode
 * @num: value
 * Return: Void
 */

void op_swap(stack_t **stack, unsigned int num)
{
	stack_t *Temp;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", num);
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
 * @num: value
 * Return: Void
 */

void op_add(stack_t **stack, unsigned int num)
{
	int Temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", num);
		exit(EXIT_FAILURE);
	}

	Temp = (*stack)->n;
	op_pop(stack, num);
	(*stack)->n += Temp;
}

