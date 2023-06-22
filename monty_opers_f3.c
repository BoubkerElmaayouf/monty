#include "monty.h"
/**
 * pop_op - this function prints the top element
 * @head: The stack head
 * @line_number: The line_number
 * Return: Nothing
*/
void pop_op(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(transporter.file);
		free(transporter.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	*head = current->next;
	free(current);
}

/**
 * pstr_op - This function prints the string starting at the top of the stack,
 * followed by a new
 * @head: The stack head
 * @line_number: The line_number
 * Return: Nothing
*/
void pstr_op(stack_t **head, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *head;
	while (current)
	{
		if (current->n > 127 || current->n <= 0)
		{
			break;
		}
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}

/**
 * push_op - this function adds node to the stack
 * @head: The stack head
 * @line_number: The line_number
 * Return: Nothing
*/
void push_op(stack_t **head, unsigned int line_number)
{
	int index = 0, n;
	int flag = 0;

	if (transporter.arg)
	{
		if (transporter.arg[0] == '-')
			index++;
		for (; transporter.arg[index] != '\0'; index++)
		{
			if (transporter.arg[index] > 57 || transporter.arg[index] < 48)
				flag = 1; 
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(transporter.file);
			free(transporter.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{ 
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(transporter.file);
		free(transporter.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(transporter.arg);
	if (transporter.flag == 0)
		push_node(head, n);
	else
		add_queue(head, n);
}
