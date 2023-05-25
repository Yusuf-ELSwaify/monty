#include "monty.h"

/**
 * mul - multiplies the second top element of the stack with the top element
 * @stack: the stack
 * @line_number: the line number
 */

void mul(stack_t **stack, unsigned int line_number)
{
        stack_t *p = *stack;

        if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
                print_error_line("can't mul, stack too short", line_number);

        while (p->next)
                p = p->next;
        p->prev->n *= p->n;
        pop(stack, line_number);
}

/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @stack: the stack
 * @line_number: the line number
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *p = *stack;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_error_line("can't mod, stack too short", line_number);

	while (p->next)
		p = p->next;
	if (p->n == 0)
		print_error_line("division by zero", line_number);
	p->prev->n %= p->n;
	pop(stack, line_number);
}