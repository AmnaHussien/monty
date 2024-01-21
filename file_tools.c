#include "monty.h"

/**
 * open_file - function that opens a file
 * @file_name: the file namepath
 * Return: nothing
 */
void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		err(2, file_name);
	read_file(fd);
	fclose(fd);
}


/**
 * read_file - function that reads a file
 * @fd: pointer to file descriptor
 * Return: nothing
 */

void read_file(FILE *fd)
{
	int lin_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (lin_number = 1; getline(&buffer, &len, fd) != -1; lin_number++)
	{
		format = parse_line(buffer, lin_number, format);
	}
	free(buffer);
}


/**
 * parse_line - Function that Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @lin_number: line number
 * @format:  storage format
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack or 1 if queue.
 */
int parse_line(char *buffer, int lin_number, int format)
{
	char *opcode, *valu;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	valu = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	find_func(opcode, valu, lin_number, format);
	return (format);
}

/**
 * find_func - find the appropriate function for the opcode
 * @opcode: opcode
 * @valu: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: nothing
 */
void find_func(char *opcode, char *valu, int ln, int format)
{
	int i;
	int flagg;

	instruction_t func_list[] = {
		{"push", add_to_stack},	{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flagg = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, valu, ln, format);
			flagg = 0;
		}
	}
	if (flagg == 1)
		err(3, ln, opcode);
}

/**
 * call_fun - function that calls the required function.
 * @func: Pointer to the function that to be called.
 * @op: string representing the opcode
 * @val: string representing a numeric valu
 * @ln: lin numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flagg;
	int i;

	flagg = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flagg = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * flagg);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
