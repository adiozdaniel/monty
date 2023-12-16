#include "monty.h"

/**
 * add - Adds the top two elements of a stack, stores the result in the
 * second top element and removes the top element
 * @stack: The stacks to be added
 * @line_number: The line number where add opcode executed
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_ptr;
	unsigned int len = 0;

	temp_ptr = *stack;

	while (temp_ptr != NULL)
	{
		temp_ptr = temp_ptr->next;
		len++;
	}

	if (len < 2)
		err(9, NULL, *stack, NULL, NULL, line_number);

	(*stack)->next->n = (*stack)->next->n + (*stack)->n;

	pop(stack, line_number);
}

/**
 * nop - Just there anything
 * @stack: The stack
 * @line_number: The line number where nop opcode executed
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - Substructs the top element from the second top element in the stack
 * @stack: The stack
 * @line_number: The line number where the opcode sub exists
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	unsigned int len = 0;

	temp = *stack;

	while (temp != NULL)
	{
		temp = temp->next;
		len++;
	}

	if (len < 2)
		err(10, NULL, *stack, NULL, NULL, line_number);

	(*stack)->next->n = (*stack)->next->n - (*stack)->n;

	pop(stack, line_number);
}

/**
 * divide - Divides the second top element by the first top element
 * @stack: The stack
 * @line_number: Line number where the div opcode interpreted
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	unsigned int len = 0;

	temp = *stack;
	while (temp != NULL)
	{
		temp = temp->next;
		len++;
	}

	if (len < 2)
		err_handle_more(11, NULL, *stack, NULL, NULL, line_number);

	if ((*stack)->n == 0)
		err_handle_more(12, NULL, *stack, NULL, NULL, line_number);

	(*stack)->next->n = (*stack)->next->n / (*stack)->n;

	pop(stack, line_number);
}

/**
 * mul - Multiplies the second top element of the stack with
 * the top element of the stack
 * @stack: The stack
 * @line_number: Line number where the mul opcode is interpreted
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	unsigned int len = 0;

	temp = *stack;
	while (temp != NULL)
	{
		temp = temp->next;
		len++;
	}

	if (len < 2)
		err_handle_more(13, NULL, *stack, NULL, NULL, line_number);

	(*stack)->next->n = (*stack)->next->n * (*stack)->n;

	pop(stack, line_number);
}
