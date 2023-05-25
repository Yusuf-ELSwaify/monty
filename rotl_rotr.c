#include "monty.h"
/**
 * rotl - rotates the stack to the top.
 * @stack: pointer to pointer to head of stack
 * @line_number: line number being executed from script file
 */

void rotl(stack_t **stack, UNUSED unsigned int line_number)
{
	stack_t *p = *stack;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	while (p->next)
		p = p->next;

	(*stack)->prev = p;
	p->next = (*stack);
	p->prev->next = NULL;
	p->prev = NULL;
	(*stack) = (*stack)->prev;
}
