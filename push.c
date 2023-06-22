#include "monty.h"

/**
 * push - pushes a new node to a stack
 * @stack: the stack to push the new node to
 * @line_number: the line number
 *
 * Return: (void)
 */


void push(stack_t **stack, unsigned int line_cnt)
{
char *n = global.argument;

if ((is_digit(n)) == 0)
{
fprintf(stderr, "L%d: usage: push integer\n", line_cnt);
exit(EXIT_FAILURE);
}

if (global.data_struct == 1)
{
if (!add_node(stack, atoi(global.argument)))
{
exit(EXIT_FAILURE);
}
}
else
{
if (!queue_node(stack, atoi(global.argument)))
{
exit(EXIT_FAILURE);
}
}
}


/**
 * queue_node - adds a node to a stack_t stack in queue_node
 * @stack: stack head
 * @n: number of the node
 *
 * Return: newly created node, if memory allocation fails, the function will
 * return NULL.
 */

stack_t *queue_node(stack_t **stack, const int n)
{
stack_t *new = malloc(sizeof(stack_t));
stack_t *current = *stack;

if (!new)
{
free(new);
return (NULL);
}
new->n = n;

if (!*stack)
{
new->next = NULL;
new->prev = NULL;
*stack = new;
return (new);
}

while (current)
{
if (!current->next)
{
new->next = NULL;
new->prev = current;
current->next = new;
break;
}
current = current->next;
}

return (new);
}

/**
 * add_node - adds a node to the start of a stack_t stack
 * @stack: stack head
 * @n: number for the new node
 *
 * Return: newly created node, if creation fails, the
 * function will return NULL.
 */
stack_t *add_node(stack_t **stack, const int n)
{
stack_t *new = malloc(sizeof(stack_t));

if (!new)
{
fprintf(stderr, "Error: malloc failed\n");
free(new);
return (NULL);
}
new->n = n;

new->next = *stack;
new->prev = NULL;
if (*stack)
(*stack)->prev = new;

*stack = new;

return (new);
}
