#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to pointer to head of stack
 * @line_number: line number being executed from script file
 */

void push(stack_t **stack, unsigned int line_number)
{
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