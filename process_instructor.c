#include "monty.h"

/**
 * get_op_f - Selects the correct function that performs an operation
 * @opcode: operation code to be performed
 *
 * Return: pointer to the function corresponding to the opcode
 */
void (*get_op_f(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t opcodes[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};

	i = 0;

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
			return (opcodes[i].f);
		i++;
	}

	return (NULL);
}
