#include "monty.h"

/**
 * opcode_struct - checks for opcode's associated function and executes it
 * @opcode: opcode from user input
 * @stack: pointer to stack
 * @line_number: line number of opcode from user input
 * Return: 0 on success, 1 on failure
 */
int opcode_struct(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t opcodes[] = {
		{"pall", pall},
		{"pint", pint},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"pop", pop},
		{"swap", swap},
		{"nop", op_nop},
		{"add", add},
		{"sub", sub},
		{"mul", mul_op},
		{"div", div_op},
		{"mod", mod_op},
		{"stack", op_stack},
		{"rotl", op_rotl},
		{"rotr", op_rotr},
		{"queue", op_queue},
		{NULL, NULL}
	};

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			(opcodes[i].f)(stack, line_number);
			return (EXIT_SUCCESS);
		}
	}
	printf("L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
