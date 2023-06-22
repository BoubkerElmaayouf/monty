#include "monty.h"
/**
 * queue_op - This function prints the top element
 * @head: stack head
 * @line_number: line_number
 * Return: Nothing
*/
void queue_op(stack_t **head, unsigned int line_number)
{
	(void)line_number;
	(void)head;
	transporter.flag = 1;
}

/**
 * add_queue - This function add node to the tail stack
 * @new_value: The new_value
 * @head: The head of the stack
 * Return: Nothing
*/
void add_queue(stack_t **head, int new_value)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		printf("Error\n");
	}
	new_node->n = new_value;
	new_node->next = NULL;
	if (temp != NULL)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (temp == NULL)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}

/**
 * stack_f - This function prints the top element
 * @head: The stack head
 * @line_number: The line_number
 * Return: Nothing
*/
void stack_f(stack_t **head, unsigned int line_number)
{
	(void)line_number;
	(void)head;
	transporter.flag = 0;
}
