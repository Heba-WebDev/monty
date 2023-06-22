#include "monty.h"


void compile_file(arguments_t *args)
{
	while (fgets(args->buffer, sizeof(char) * 1024, args->source) != NULL)
	{
		if (get_command(args) == 0)
			continue;
		get_opcode(args)(&(args->stack), args->line);
		args->line++;
	}
}

int get_command(arguments_t *args)
{
	char *data;

	args->command = strtok(args->buffer, " \n\t");
	if (args->command == NULL || args->command[0] == '#')
		return (0);

	if (strcmp(args->command, "push") == 0)
	{
		data = strtok(NULL, " \n\t");
		if (check_num(data) == 1)
		{
			push(&(args->stack), atoi(data));
			return (0);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", args->line);
			free(args->buffer);
			fclose(args->source);
			free(args);
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}


int check_num(char *num)
{
	int i = 0;

	if (!num)
		return (0);
	while (num[i] != '\0')
	{
		if ((num[i] < '0' || num[i] > '9') && num[i] != '-')
			return (0);
		i++;
	}
	return (1);
}
