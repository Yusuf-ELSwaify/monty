#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to pointer to head of stack
 * @line_number: line number being executed from script file
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node, *p = *stack;
	char *arg = strtok(NULL, " \n\t");

	if (arg == NULL || isdigit(*arg) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(arg);
	new_node->next = NULL;
	if (p)
	{
		while (p->next)
		p = p->next;
		new_node->prev = p;
		p->next = new_node;
	}
	else
	{
		new_node->prev = NULL;
		*stack = new_node;
	}
}

/**
 * pall - prints all the values on the stack
 * @stack: pointer to pointer to head of stack
 * @line_number: line number being executed from script file
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *p = *stack;

	(void)line_number;
	if (stack == NULL || *stack == NULL)
		return;
	while (p->next)
		p = p->next;
	while (p)
	{
		printf("%d\n", p->n);
		p = p->prev;
	}
}
