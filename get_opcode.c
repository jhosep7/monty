#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
* **get_opcode - contain the function that selects the correct function
* @s: string
* @num: value
* Return: 
*/

void *get_opcode(char *s, int num)
{
	instruction_t ops[] = {
	{"push", op_push},
	{"pall", op_pall},
	{"pint", op_pint},
	{"pop", op_pop},
	{"swap", op_swap},
	{"add", op_add},
	{"nop", op_nop},
	{NULL, NULL}
	};

	int i = 0;

	while (i <= 7)
	{
		if (ops[i].opcode[0] == *s)
		{
			return (ops[i].f);
		}
		i++;
	}

}
