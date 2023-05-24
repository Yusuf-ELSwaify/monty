#include "monty.h"

global_t global;

void exec_op(char *opcode);
void run(void);
/**
 * main - entry point
 * @argc: arguments count
 * @argv: the arguments
 * Return: EXIT_SUCCESS on success
 */
int main(int argc, char **argv)
{
		global.line_num = 1;
	if (argc != 2)
		print_error(MONTY_FILE_ERR);
	global.file = fopen(argv[1], "r");

	if (global.file == NULL)
		print_error_file(MONTY_FILE_NOT_OPEN, argv[1]);

	run();
	free_all();
	return (EXIT_SUCCESS);
}
/**
 * run - the program run
 */
void run(void)
{
	size_t len = 0;
	int read;
	char *opcode, *data;

	while (getline(&global.line_ptr, &len, global.file) != -1)
	{
		opcode = strtok(global.line_ptr, SPACES);
		if (*opcode != '#' && *opcode != '\n')
			exec_op(opcode);

		global.line_num++;
	}
}
/**
 * exec_op - get the choosed operation and execute it
 * @opcode: the operation code
 */
void exec_op(char *opcode)
{
	int i;

	instruction_t op_funcs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}};
	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
		{
			op_funcs[i].f(&global.list, global.line_num);
			return;
		}
	}
	print_error_line("usage: push integer", global.line_num);
}