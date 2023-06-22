#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./monty.h"

/**
 * opcode - function in charge of running builtins
 * @stack: stack given by main
 * @str: string to compare
 * @line_cnt: amount of lines
 *
 * Return: nothing
 */
void opcode(stack_t **stack, char *str, unsigned int line_cnt)
{
int i = 0;
instruction_t ops[] = {
{"push", push},
{"pall", pall},
{NULL, NULL}
};

if (!strcmp(str, "stack"))
{
global.data_struct = 1;
return;
}
if (!strcmp(str, "queue"))
{
global.data_struct = 0;
return;
}

while (ops[i].opcode)
{
if (strcmp(ops[i].opcode, str) == 0)
{
ops[i].f(stack, line_cnt);
return;
}
i++;
}
fprintf(stderr, "L%d: unknown instruction %s\n", line_cnt, str);
exit(EXIT_FAILURE);
}
