#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to pointer to head of stack
 * @line_number: line number being executed from script file
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *p = *stack;

	if (stack == NULL || *stack == NULL)
		print_error_line("can't pint, stack empty", line_number);
	while (p->next)
		p = p->next;
	printf("%d\n", p->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: pointer to pointer to head of stack
 * @line_number: line number being executed from script file
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *p = *stack;

	if (stack == NULL || *stack == NULL)
		print_error_line("can't pop an empty stack", line_number);

	while (p->next)
		p = p->next;
	if (p->prev)
		p->prev->next = NULL;
	else
		*stack = NULL;
	free(p);
}
