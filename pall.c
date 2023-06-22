#include "monty.h"

/**
 * pall - prints all values stored in nodes
 * @stack: a doubly linked list
 * @line_number: the current working line number
 */


void pall(stack_t **stack, unsigned int line_cnt)
{
if (!stack || !(*stack))
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_cnt);
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}
