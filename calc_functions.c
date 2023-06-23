#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode
 *
 * Description: If the stack contains less than two elements, prints an error
 * message and exits with EXIT_FAILURE. The result is stored in the second top
 * element of the stack, and the top element is removed.
 */
void add(stack_t **stack, unsigned int line_number)
{
	int a;
	int b;
	int result;

	if (stack_length(stack) < 2)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	b = (*stack)->next->n;

	result = a + b;

	pop(stack, line_number);

	(*stack)->n = result;
}

/**
 * sub - Subtracts the top element of the stack from the second top element
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number being executed from the Monty file
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int a;
	int b;
	int result;

	if (stack_length(stack) < 2)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	b = (*stack)->next->n;

	result = b - a;

	pop(stack, line_number);

	(*stack)->n = result;
}

/**
 * div_op - Divides the second top element of the stack by the top element
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number being executed from the Monty file
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	int a;
	int b;
	int result;

	if (stack_length(stack) < 2)
	{
		printf("L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	b = (*stack)->next->n;
	if (a == 0)
	{
		printf("L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = b / a;

	pop(stack, line_number);

	(*stack)->n = result;
}

/**
 * mul_op - Multiplies the second top element of the stack with the top element
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number being executed from the Monty file
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
	int a;
	int b;
	int result;

	if (stack_length(stack) < 2)
	{
		printf("L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	b = (*stack)->next->n;

	result = a * b;

	pop(stack, line_number);

	(*stack)->n = result;
}

/**
 * mod_op - Computes the rest of the division of the second top element by the top element
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number being executed from the Monty file
 */
void mod_op(stack_t **stack, unsigned int line_number)
{
	int a;
	int b;
	int result;

	if (stack_length(stack) < 2)
	{
		printf("L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	b = (*stack)->next->n;
	if (a == 0)
	{
		printf("L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = b % a;

	pop(stack, line_number);

	(*stack)->n = result;
}
