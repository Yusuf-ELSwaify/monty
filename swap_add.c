#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to pointer to head of stack
 * @line_number: line number being executed from script file
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *p = *stack;
	int tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (p->next)
		p = p->next;
	tmp = p->n;
	p->n = p->prev->n;
	p->prev->n = tmp;
}

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to pointer to head of stack
 * @line_number: line number being executed from script file
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *p = *stack;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (p->next)
		p = p->next;
	p->prev->n += p->n;
	pop(stack, line_number);
}
