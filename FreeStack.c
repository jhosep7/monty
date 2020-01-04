#include "monty.h"

/**
 * FreeStack - Frees Stack when necessary
 * @stack: stack
 * @lnum: line-number
 * Return: void
 */
void FrStack(stack_t **stack, unsigned int lnum)
{
	if (!stack)
	{return; }
	while (*stack)
	{op_pop(stack, lnum); }
}
