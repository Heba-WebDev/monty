#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct instruction_s - opcode and its function
 * @command: the opcode
 * @stack: stack
 * @line: line number
 * @data: data to add
 * @ac: main args
 * @av: main args av
 *
 * Description: variables structure
 */
typedef struct arguments_s
{
        char *buffer;
        stack_t *stack;
	int line;
	int data;
	char *command;
	FILE *source;
	int ac;
	char **av;
} arguments_t;


arguments_t *init_args(arguments_t *args, int ac, char **av);
int precheck_args(arguments_t *args);
void compile_file(arguments_t *args);
int check_num(char *num);
int get_command(arguments_t *args);
void compile_file(arguments_t *args);
stack_t *push(stack_t **head, const int n);
void pall(stack_t **h, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **head, unsigned int index);
void (*get_opcode(arguments_t *args))(stack_t **, unsigned int);
void free_stack(stack_t *head);
void nop(stack_t **stack, unsigned int n);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);


#endif