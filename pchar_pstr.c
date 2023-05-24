#include "monty.h"
/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: pointer to pointer to head of stack
 * @line_number: line number being executed from script file
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *p = *stack;

	if (stack == NULL || *stack == NULL)
		print_error_line("can't pchar, stack empty", line_number);
	while (p->next)
		p = p->next;
	if (p->n > 0 && p->n < 128)
		printf("%c\n", p->n);
}
/**
 * pstr - prints the string from the top of the stack, followed by a new line.
 * @stack: pointer to pointer to head of stack
 * @line_number: line number being executed from script file
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *p = *stack;

	(void)line_number;
	if (stack == NULL || *stack == NULL)
		return;
	while (p->next)
		p = p->next;
	while (p && (p->n > 0 && p->n < 128))
	{
		printf("%c", p->n);
		p = p->prev;
	}
	printf("\n");
}
