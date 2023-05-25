#ifndef MONTY__H
#define MONTY__H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define ESCAPES " \n\t\r\f\v"
#define SPACES " \t\r\f\v"

#define MONTY_FILE_ERR "USAGE: monty file"
#define MONTY_FILE_NOT_OPEN "Error: Can't open file"

#define UNUSED __attribute__((unused))

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - global struct to hold my global values
 * @file: monty file
 * @line_ptr: line we interpret
 * @line_num: the current line to read
 * @list: the list we build
 * @is_stack: 1 if stack 0 if queue
 */
typedef struct global_s
{
	FILE *file;
	char *line_ptr;
	unsigned int line_num;
	stack_t *list;
	int is_stack;
} global_t;

extern global_t global;

void free_all(void);
void print_error(char *err);
void print_error_file(char *err, char *file_name);
void print_error_line(char *err, unsigned int line_num);
void print_error_opcode(char *err, char *opcode, unsigned int line_num);

void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void add(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void sub(stack_t **, unsigned int);
void _div(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);
void pchar(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);
void turn_queue(stack_t **, unsigned int);
void turn_stack(stack_t **, unsigned int);

#endif /* MONTY__H */
