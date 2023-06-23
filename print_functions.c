#include "monty.h"

/**
 * op_pchar - Prints the char at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number in the Monty file
 *
 * Description: The integer stored at the top of the stack is treated as the
 *              ASCII value of the character to be printed. If the value is not
 *              in the ASCII table, it prints an error message and exits with
 *              EXIT_FAILURE. If the stack is empty, it also prints an error
 *              message and exits with EXIT_FAILURE.
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	int c;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	c = (*stack)->n; /* head node's data */
	if (c < 0 || c > 127)
	{
		printf("L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar(c);
	putchar('\n');
}

/**
 * op_pstr - Prints the string starting at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number in the Monty file
 *
 * Description: The integer stored in each element of the stack is treated as
 *              the ASCII value of the character to be printed. The string
 *              stops when either the stack is over, the value of the element
 *              is 0, or the value of the element is not in the ASCII table.
 *              If the stack is empty, it only prints a new line.
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	int c;
	stack_t *current;
	(void)line_number;

	current = *stack;
	while (current != NULL)
	{
		c = current->n; /* current node's data */
		if (c > 0 && c <= 127)
		{
			current = current->next;
			putchar(c);
		}
		else
			break;
	}
	putchar('\n');
}

/**
 * pint - Prints the value at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode being executed
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		frees(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecodes file.
 */
void pall(stack_t **stack, unsigned int __attribute__((unused))line_number)
{
	stack_t *current = *stack;

	if (stack == NULL || *stack == NULL)
		return;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
