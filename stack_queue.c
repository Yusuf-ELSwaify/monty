#include "monty.h"
/**
 * turn_queue - turn the global variable is_stack to 0
 *			to make list act like queue
 * @stack: pointer to pointer to head of stack
 * @line_number: line number being executed from script file
 */
void turn_queue(UNUSED stack_t **stack, UNUSED unsigned int line_number)
{
	global.is_stack = 0;
}
/**
 * turn_stack - turn the global variable is_stack to 1
 *			to make list act like stack
 * @stack: pointer to pointer to head of stack
 * @line_number: line number being executed from script file
 */
void turn_stack(UNUSED stack_t **stack, UNUSED unsigned int line_number)
{
	global.is_stack = 1;
}
