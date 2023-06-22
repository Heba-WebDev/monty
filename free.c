#include "monty.h"

/**
 * free_stack - free a doubly linked list.
 *
 * @head: A double pointer to the head of the doubly linked list.
 */
void free_stack(stack_t *head)
{
	stack_t *current;

	if (!head)
		return;

	current = head->next;
	while (head)
	{
		free(head);
		head = current;
		if (current)
			current = current->next;
	}
}
