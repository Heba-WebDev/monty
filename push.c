#include "monty.h"

/**
 * push - pushes a new node to a stack
 * @stack: the stack to push the new node to
 * @line_number: the line number
 *
 * Return: (void)
 */


void push(stack_t **stack, unsigned int line_number)
{
char *arg = strtok(NULL, DELIMS);
stack_t *tmp, *new;
int i;
new = malloc(sizeof(stack_t));
if (new == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
if (arg == NULL)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
for (i = 0; arg[i]; i++)
{
if (arg[i] == '-' && i == 0)
continue;
if (arg[i] < '0' || arg[i] > '9')
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
}
new->n = atoi(arg);
if (*stack == NULL)
{
new->prev = NULL;
new->next = *stack;
*stack = new;
}
else
{
tmp = *stack;
while (tmp->next)
tmp = tmp->next;
new->prev = tmp;
new->next = NULL;
tmp->next = new;
}
}
