#include "monty.h"

/**
 * op_div - divides the second top element of the stack
 * by the top element of the stack
 * @stack: the opcode
 * @lnum: value
 * Return: Void
 */

void op_div(stack_t **stack, unsigned int lnum)
{
	int Temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", lnum);
		exit(EXIT_FAILURE);
	}
	Temp = (*stack)->n;

	if (Temp == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", lnum);
		exit(EXIT_FAILURE);
	}
	op_pop(stack, lnum);
	(*stack)->n /= Temp;
}

/**
 * op_mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @stack: the opcode
 * @lnum: value
 * Return: Void
 */

void op_mod(stack_t **stack, unsigned int lnum)
{
	int Temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", lnum);
		exit(EXIT_FAILURE);
	}
	Temp = (*stack)->n;

	if (Temp == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", lnum);
		exit(EXIT_FAILURE);
	}
	op_pop(stack, lnum);
	(*stack)->n %= Temp;
}

/**
 * op_pstr - prints the string starting at the top of the stack.
 * @stack: the opcode
 * @lnum: value
 * Return: void
 */
void op_pstr(stack_t **stack, unsigned int lnum)
{
	stack_t *Temp;

	UNUSED(lnum);
	if (!(*stack) || SharedVar.intvar == 0 || !stack)
	{
		printf("\n");
		return;
	}
	Temp = *stack;
	while (Temp && isascii(Temp->n) && Temp->n)
	{
		printf("%c", Temp->n);
		Temp = Temp->next;
	}
	printf("\n");
}
