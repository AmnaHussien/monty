#include "monty.h"
/**
 * add_to_stack - Function that Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger represent the line number of the opcode
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (*new_node == NULL || new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * print_stack - Function that Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lin_number: line number of  the opcode
 */
void print_stack(stack_t **stack, unsigned int lin_number)
{
	stack_t *tmp;

	(void) lin_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_top - Function that Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lin_number: Interger representing the line number of the opcode.
 */
void pop_top(stack_t **stack, unsigned int lin_number)
{
	stack_t *tmp;

	if (*stack == NULL || stack == NULL)
		mor_err(7, lin_number);
	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * print_top - function that Prints the top node of the stack
 * @stack: Pointer to a pointer pointing to top node of the stack
 * @lin_number: Interger representing the line number of the opcode
 */
void print_top(stack_t **stack, unsigned int lin_number)
{
	if (*stack == NULL || stack == NULL)
		mor_err(6, lin_number);
	printf("%d\n", (*stack)->n);
}
