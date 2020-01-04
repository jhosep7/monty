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
	{NULL, NULL}
	};

	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(tkn, ops[i].opcode) == 0)
		{
			ops[i].f(stack, lnum);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", lnum, tkn);
	FrStack(stack, lnum);
	exit(EXIT_FAILURE);
}
