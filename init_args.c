#include "monty.h"

arguments_t *init_args(arguments_t *args, int ac, char **av)
{
	args->buffer = malloc(sizeof(char) * 1024);
	if (!(args->buffer))
	{
		free(args->buffer);
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	args->stack = NULL;
	args->line = 1;
	args->data = 0;
	args->command = NULL;
	args->ac = ac;
	args->av = av;
	args->source = NULL;
	return (args);
}


int precheck_args(arguments_t *args)
{
	if (args->ac != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		free(args->buffer);
		free(args);
		exit(EXIT_FAILURE);
	}
	args->source = fopen(args->av[1], "r");
	if (args->source == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", args->av[0]);
		free(args->buffer);
		free(args);
		exit(EXIT_FAILURE);
	}
	return (1);
}
