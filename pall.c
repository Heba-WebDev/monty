#include "monty.h"

/**
 * pall - prints all values stored in nodes
 * @stack: a doubly linked list
 * @line_number: the current working line number
 */


void pall(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = (*stack)->next;

while (tmp)
{
printf("%d\n", tmp->n);
tmp = tmp->next;
}
(void)line_number;
}
