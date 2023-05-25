#include "monty.h"

/**
 * sub - subtracts the top element of the stack from the second top element
 * @stack: the stack
 * @line_number: the line number
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *p = *stack;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_error_line("can't add, stack too short", line_number);

	while (p->next)
		p = p->next;
	p->prev->n += p->n;
	pop(stack, line_number);
}

/**
 * _div - divides the second top element of the stack by the top element
 * @stack: the stack
 * @line_number: the line number
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *p = *stack;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_error_line("can't div, stack too short", line_number);

	while (p->next)
		p = p->next;
	if (p->n == 0)
		print_error_line("division by zero", line_number);
	p->prev->n /= p->n;
	pop(stack, line_number);
}
