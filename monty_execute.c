#include "monty.h"
/**
* _execute - This function execute the opcode
* @stack: The head linked list of stack
* @counter: The line_counter
* @file: The poiner to monty file
* @content: The line content
* Return: Nothing
*/
int _execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t operators[] = 
	{
			{"push", push_op}, {"pall", op_pall}, {"pint", op_pint},
			{"pop", pop_op},
			{"swap", swap_f},
			{"add", addToStack},
			{"nop", op_nop},
			{"sub", sub_op},
			{"div", div_top_two},
			{"mul", mul_op},
			{"mod", mod_op},
			{"pchar", op_pchar},
			{"pstr", pstr_op},
			{"rotl", rotl_f},
			{"rotr", rotr_f},
			{"queue", queue_op},
			{"stack", stack_f},
			{NULL, NULL}
	};
	char *ops;
	unsigned int index = 0;

	ops = strtok(content, " \n\t");
	if (ops && ops[0] == '#')
		return (0);
	transporter.arg = strtok(NULL, " \n\t");
	while (operators[index].opcode && ops)
	{
		if (strcmp(ops, operators[index].opcode) == 0)
		{	operators[index].f(stack, counter);
			return (0);
		}
		index++;
	}
	if (operators[index].opcode == NULL && ops)
	{ 
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, ops);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}

