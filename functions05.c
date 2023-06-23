#include "monty.h"

/**
 * op_stack - Sets the format of the data to a stack (LIFO)
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number in the Monty file
 *
 * Description: This opcode sets the format of the data to a stack (LIFO).
 *              This is the default behavior of the program.
 */
void op_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
* op_queue - Sets the format of the data to a queue (FIFO)
* @stack: ...
* @line_number: ...
*
* Description: This opcode sets the format of the data to a queue (FIFO)
*              The top of the stack becomes the front of the queue, and
*              the front of the queue becomes the top of the stack.
*/
void op_queue(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	if (temp == NULL || temp->next == NULL)
	{
		return;
	}
	while (temp->next != NULL)
	temp = temp->next;
	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	*stack = temp;
}

/**
 * op_rotr - Rotates the stack to the bottom
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number in the Monty file
 *
 * Description: The last element of the stack becomes the top element.
 *              `rotr` never fails.
 */
void op_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	if (temp == NULL || temp->next == NULL)
		return;
	while (temp->next != NULL)
	temp = temp->next;
	temp->next = *stack;
	temp->prev->next = NULL;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}
/**
* op_rotl - Rotates the stack to the top
* @stack: ...
* @line_number: ...
*
* Description:
*              second top element of the stack becomes the first one.
*              `rotl` never fails.
*/
void op_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	if (temp == NULL || temp->next == NULL)
		return;
	while (temp->next != NULL)
	temp = temp->next;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
