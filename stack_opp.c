#include "monty.h"

/**
 * mul_nodes - Function that adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lin_number: interger represent the line number of the opcode.
 */
void mul_nodes(stack_t **stack, unsigned int lin_number)
{
	int summ;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		mor_err(8, lin_number, "mul");

	(*stack) = (*stack)->next;
	summ = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = summ;

	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lin_number: Interger representing the line number of of the opcode.
 */
void mod_nodes(stack_t **stack, unsigned int lin_number)
{
	int summ;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		mor_err(8, lin_number, "mod");
	if ((*stack)->n == 0)
		mor_err(9, lin_number);
	(*stack) = (*stack)->next;
	summ = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = summ;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
