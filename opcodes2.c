#include "monty.h"


/**
 * _add - adds the top two elements of the stack.
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _add(stack_t **top, unsigned int line_number)
{
	int value = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	value = (*top)->n;
	_pop(&datax.top, datax.line_num);
	(*top)->n += value;
}

/**
 * _nop - doesn’t do anything.
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _nop(stack_t **top, unsigned int line_number)
{
	(void)top;
	(void)line_number;
}

/**
 * _sub - subtracts the top element of the stack
 *  from the second top element of the stack.
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _sub(stack_t **top, unsigned int line_number)
{
	int value = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	value = (*top)->n;
	_pop(&datax.top, datax.line_num);
	(*top)->n -= value;
}

/**
 * _div - divides the second top element of
 * the stack by the top element of the stack.
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _div(stack_t **top, unsigned int line_number)
{
	int value = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	value = (*top)->n;
	_pop(&datax.top, datax.line_num);
	(*top)->n /= value;
}

/**
 * _mul - multiplies the second top element
 * of the stack with the top element of the stack.
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _mul(stack_t **top, unsigned int line_number)
{
	int value = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	value = (*top)->n;
	_pop(&datax.top, datax.line_num);
	(*top)->n *= value;
}
