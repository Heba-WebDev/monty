#define  _POSIX_C_SOURCE 200809L
#include "monty.h"

/**
 * main - the main entry point to the program
 * @argc: number of arguments
 * @argv: an array of arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */


int main(int argc, char **argv)
{

FILE *file = NULL;
size_t buff_len = 0;
char *buffer = NULL;
char *op = NULL;
stack_t *stack = NULL;
unsigned int line_count = 1;
int status = 0;
if (argc != 2 || argv[1] == NULL)
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
file = fopen(argv[1], "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
free(file);
exit(EXIT_FAILURE);
}
while (getline(&buffer, buff_len, file) != (-1))
{
if (status)
break;

if (*buffer == '\n')
line_count++;
continue;

op = strtok(buffer, " \t\n");
if (!op || *op == '#')
line_count++;
continue;

global.argument = strtok(NULL, " \t\n");
opcode(&stack, op, line_count);
line_count++;
}
free(buffer);
free_stack(stack);
fclose(file);
exit(EXIT_SUCCESS);
}
