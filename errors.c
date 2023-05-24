#include "monty.h"
/**
 * free_all - free program variable before exit
*/
void free_all(void)
{
	stack_t *temp, *curr = global.list;

	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	free(global.line_ptr);
	fclose(global.file);
}
/**
 * print_error - print only the given error then free all and exit
 * @err: the error syntax
 */
void print_error(char *err)
{
	fprintf(stderr, "%s\n", err);
	free_all();
	exit(EXIT_FAILURE);
}
/**
 * print_error_file - print the given error and the file cause it then exit
 * @file_name: the file caused error
 * @err: the error syntax
 */
void print_error_file(char *err, char *file_name)
{
	fprintf(stderr, "%s %s\n", err, file_name);
	exit(EXIT_FAILURE);
}
/**
 * print_error_line - print the given error and the line cause it
 *			then free all and exit
 * @err: the error syntax
 * @line_num: the line caused error
 */
void print_error_line(char *err, unsigned int line_num)
{
	fprintf(stderr, "L%u: %s\n", line_num, err);
	free_all();
	exit(EXIT_FAILURE);
}
/**
 * print_error_opcode - print the given error and the opcode cause it
 *			then free all and exit
 * @err: the error syntax
 * @opcode: the opcode caused error
 * @line_num: the line caused error
 */
void print_error_opcode(char *err, char *opcode, unsigned int line_num)
{
	fprintf(stderr, "L%u: %s %s\n", line_num, err, opcode);
	free_all();
	exit(EXIT_FAILURE);
}
