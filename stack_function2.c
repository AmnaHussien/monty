#include "monty.h"

/**
 * nop - Does nothing
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lin_number: Interger representing the line number of the opcode
 */
void nop(stack_t **stack, unsigned int lin_number)
{
	(void)stack;
	(void)lin_number;
}


/**
 * swap_nodes - function that Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack
 * @lin_number: Interger representing the line number of the opcode
 */
void swap_nodes(stack_t **stack, unsigned int lin_number)
{
	stack_t *tmp;

	if (*stack == NULL || stack == NULL || (*stack)->next == NULL)
		mor_err(8, lin_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_nodes - Function that Adds the top two elements of the stack
 * @stack: Pointer to a pointer pointing to top node of the stack
 * @lin_number: Interger representing the line number of the opcode
 */
void add_nodes(stack_t **stack, unsigned int lin_number)
{
	int summ;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		mor_err(8, lin_number, "add");

	(*stack) = (*stack)->next;
	summ = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = summ;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_nodes - Function that Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lin_number: Interger representing the line number of the opcode.
 */
void sub_nodes(stack_t **stack, unsigned int lin_number)
{
	int summ;

	if (*stack == NULL || stack == NULL || (*stack)->next == NULL)
	{
		mor_err(8, lin_number, "sub");
	}
	(*stack) = (*stack)->next;
	summ = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = summ;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lin_number: Interger representing the line number of of the opcode.
 */
void div_nodes(stack_t **stack, unsigned int lin_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		mor_err(8, lin_number, "div");

	if ((*stack)->n == 0)
		mor_err(9, lin_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
