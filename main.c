#include "monty.h"

/**
 * main - main one
 * @ac: count argument
 * @av: value argument
 * Return: integer
 */
int main(int ac, char **av)
{
	char *temp, *buffer = NULL;
	size_t lnum = 1, i = 0;
	stack_t *stack = NULL;
	FILE *fp;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	for (lnum = 1; getline(&buffer, &i, fp) != -1; lnum++)
	{
		if (*buffer)
		{
			temp = strtok(buffer, "\n");
			TokenFun(temp, &stack, lnum);
		}
	}
	fclose(fp), free(buffer);
	if (stack)
	{FrStack(&stack, lnum); }
	return (EXIT_SUCCESS);
}

/**
 * TokenFun - Tokenize strings on the terminal
 * @temp: count argument
 * @stack: value argument
 * @lnum: the one to be tokenized
 * Return: void
 */
void TokenFun(char *temp, stack_t **stack, unsigned int lnum)
{
	char *tkn, *TempTkn;

	tkn = strtok(temp, " ");
	if ((*tkn) == ' ' || (*tkn) == '\n' || tkn == NULL || (*tkn) == '#')
	{return; }
	if (strcmp(tkn, "push") == 0)
	{
		TempTkn = tkn;
		tkn = strtok(NULL, "");
		if (!NumberCheck(tkn))
		{
			fprintf(stderr, "L%u: usage: push integer\n", lnum);
			FrStack(stack, lnum);
			exit(EXIT_FAILURE);
		}
		SharedVar.intvar = atoi(tkn), get_opcode(TempTkn, stack, lnum);
	}
	else
	{get_opcode(tkn, stack, lnum); }
}

/**
 * NumberCheck - main one
 * @tkn: token
 * Return: int
 */
int NumberCheck(char *tkn)
{
	if (!tkn)
	{return (0); }
	if (*tkn == '-')
	{tkn++; }
	for (; *tkn != '\0'; tkn++)
	{
		if (!isdigit(*tkn))
		{return (0); }
	}
	tkn++;
	return (1);
}
