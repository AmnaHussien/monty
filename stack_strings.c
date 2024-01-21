#include "monty.h"

/**
 * print_char - function that Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lin_number: interger representing the lin number of the opcode.
 */
void print_char(stack_t **stack, unsigned int lin_number)
{
	int ASCII;

	if (stack == NULL || *stack == NULL)
		string_err(11, lin_number);
	ASCII = (*stack)->n;
	if (ASCII < 0 || ASCII > 127)
		string_err(10, lin_number);
	printf("%c\n", ASCII);
}

/**
 * print_str - Function that Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of the opcode
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ASCII;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	tmp = *stack;
	while (tmp != NULL)
	{
		ASCII = tmp->n;
		if (ASCII <= 0 || ASCII > 127)
			break;
		printf("%c", ASCII);
		tmp = tmp->next;
	}

	printf("\n");
}

/**
 * rotl - Function that Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of the opcode
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Function that Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack
 * @ln: Interger representing the line number of the opcode
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
