#include "monty.h"

int main(int ac, char **av)
{
	arguments_t *args = malloc(sizeof(arguments_t));

	if (!args)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	init_args(args, ac, av);
	precheck_args(args);
	compile_file(args);
	free_stack(args->stack);
	free(args->buffer);
	fclose(args->source);
	free(args);
	return (EXIT_SUCCESS);
}
