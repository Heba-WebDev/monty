#include "monty.h"


void (*get_opcode(arguments_t *args))(stack_t **, unsigned int)
{
	int i;

	instruction_t ops[] = {
		{"pall", pall},
		{"div", _div},
		{"mul", mul},
		{"nop", nop},
		{"sub", sub},
		{"add", add},
		{"swap", swap},
		{"pop", pop},
		{"pint", pint},
		{NULL, NULL}};
	i = 0;
	while (ops[i].opcode)
	{
		if (strcmp(args->command, ops[i].opcode) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", args->line, args->command);
	free_stack(args->stack);
	exit(EXIT_FAILURE);
}
