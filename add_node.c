#include "monty.h"

void free_stack(stack_t *head);
/**
 * addToStack - this function adds the top two elements
 * of the stack.
 * @head: The stack head
 * @line_number: The line_number
 * Return: Nothing 
*/
void addToStack(stack_t **head, unsigned int line_number)
{
	stack_t *current_node;
	int length = 0, sum;

	current_node = *head;
	while (current_node)
	{
		current_node = current_node->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(transporter.file);
		free(transporter.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current_node = *head;
	sum = current_node->n + current_node->next->n;
	current_node->next->n = sum;
	*head = current_node->next;
	free(current_node);
}

/**
 * push_node - This function adds node to the head stack
 * @head: The head of the stack
 * @n: The new_value
 * Return: Nothing
*/
void push_node(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ 
		printf("Error\n");
		exit(0);
	}
	if (temp)
		temp->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

