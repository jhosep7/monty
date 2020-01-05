#include "monty.h"

/**
* **get_opcode - contain the function that selects the correct function
* @stack: char
* @lnum: int
* @tkn: token
* Return: void
*/

void get_opcode(char *tkn, stack_t **stack, int lnum)
{
	int i;

	instruction_t ops[] = {
	{"push", op_push},
	{"pall", op_pall},
	{"pint", op_pint},
	{"pop", op_pop},
	{"swap", op_swap},
	{"add", op_add},
	{"nop", op_nop},
	{"sub", op_sub},
	{"mul", op_mul},
	{"div", op_div},
	{"mod", op_mod},
	{NULL, NULL}
	};

	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(tkn, ops[i].opcode) == 0)
			ops[i].f(stack, lnum);
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", lnum, tkn);
	FrStack(stack, lnum);
	exit(EXIT_FAILURE);
}
