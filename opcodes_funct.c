#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * op_push - pushes an element to the stack
 * @stack: the opcode
 * @num: value 
 * return: 
 */
void op_push(stack_t **stack, unsigned int num)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		{
			free(new);
			fprintf(stderr,"Error: malloc failed");
			exit (EXIT_FAILURE);
		}
		new->next = NULL;
		new->prev = NULL;
		new->n = num;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer", num);
		exit (EXIT_FAILURE);
	}
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
}

/**
 * op_pall - prints all the values on the stack
 * @stack: the opcode
 * @num: value 
 * return: 
 */
void op_pall(stack_t **stack, unsigned int num)
{
	stack_t *new;

	UNUSED(num);
	new = *stack;

	while (new != NULL)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
}

/**
 * op_pint - prints the value at the top of the stack
 * @stack: the opcode
 * @num: value 
 * return: 
 */
void op_pint(stack_t **stack, unsigned int num)
{
	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", num);
		exit (EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * op_pop - removes the top element of the stack.
 * @stack: the opcode
 * @num: value 
 * return: 
 */
void op_pop(stack_t **stack, unsigned int num)
{
	stack_t *new;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", num);
		exit (EXIT_FAILURE);
	}
	new = *stack;
	(*stack) = (*stack)->next;
	free(new);
}
/**
 * op_swap - swaps the top two elements of the stack
 * @stack: the opcode
 * @num: value 
 * return: 
 */
void op_swap(stack_t **stack, unsigned int num)
{
	stack_t *temp;
	int len;

	for (len = 0; *stack; len++)
	{
		*stack = (*stack)->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", num);
		exit (EXIT_FAILURE);
	}
	
	temp = *stack;
	*stack = temp->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}
/**
 * op_add - adds the top two elements of the stack
 * @stack: the opcode
 * @num: value 
 * return: 
 */
void op_add(stack_t **stack, unsigned int num)
{
	
}

void op_nop(stack_t **stack, unsigned int num)
{
	
}