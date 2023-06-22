#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int i;

	current = *stack;
	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	i = current->n;
	current->n = current->next->n;
	current->next->n = i;
}


void add(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int i;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	i = 0;
	current = *stack;
	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	i = current->n;
	pop(stack, line_number);
	(*stack)->n = (*stack)->n + i;
}


void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int i;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	i = 0;
	current = *stack;
	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	i = current->n;
	pop(stack, line_number);
	(*stack)->n = (*stack)->n - i;
}


void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int i;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	i = 0;
	current = *stack;
	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	i = current->n;
	pop(stack, line_number);
	(*stack)->n = (*stack)->n / i;
}

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int i;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	i = 0;
	current = *stack;
	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	i = current->n;
	pop(stack, line_number);
	(*stack)->n = (*stack)->n * i;
}
