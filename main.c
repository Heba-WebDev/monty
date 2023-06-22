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
char *line;
int len = 0;
unsigned int line_number = 0;
stack_t *stack = NULL;
instruction_t opcodes[] = {
{"push", push},
{NULL, NULL}
};

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
file = fopen(argv[1], "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
while (getline(&line, &len, file) != -1)
{
line_number++;
parse_line(line, line_number, opcodes, &stack);
}

free(line);
free_stack(stack);
fclose(file);
return (EXIT_SUCCESS);
}


/**
 * parse_line - parse a line
 * @line: the line to parse
 * @line_number: the line number
 * @opcodes: array of operations
 * @stack: double linked list
 *
 * Return: (void)
 */

void parse_line(char *line, unsigned int line_number,
instruction_t *opcodes, stack_t **stack)
{
char *opcode = strtok(line, DELIMS);
char *arg = strtok(NULL, DELIMS);
int i;

if (opcode == NULL || opcode[0] == '#')
return;

for (i = 0; opcodes[i].opcode != NULL; i++)
{
if (strcmp(opcode, opcodes[i].opcode) == 0)
{
opcodes[i].f(stack, line_number);
return;
}
}

fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
free_stack(*stack);
exit(EXIT_FAILURE);
}
