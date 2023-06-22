#include "monty.h"
/**
  * sub_op- This function sustrat 
  * @head: The stack head
  * @counter: The line_number
  * Return: Nothing
 */
void sub_op(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	int sus, nodes;

	temp = *head;
	nodes = 0;
	while (temp != NULL)
  	{
  		  nodes++;
   		 temp = temp->next;
 	}
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(transporter.file);
		free(transporter.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	sus = temp->next->n - temp->n;
	temp->next->n = sus;
	*head = temp->next;
	free(temp);
}

/**
 * mul_op  - This function multiplies the top two elements of the stack.
 * @head: The stack head
 * @counter: The line_number
 * Return: Nothing
*/
void mul_op(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int length = 0, result;

	temp = *head;
	for (length = 0; temp; length++)
		temp = temp->next;
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(transporter.file);
		free(transporter.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	result = temp->next->n * temp->n;
	temp->next->n = result;
	*head = temp->next;
	free(temp);
}

/**
 * mod_op - This function computes the rest of the division of
 * the second top element of the stack.
 * @head: The stack head
 * @counter: The line_number
 * Return: Nothing
*/
void mod_op(stack_t **head, unsigned int counter)
{
	int length = 0, remainder;
	stack_t *current;

	current = *head;
	for (; current != NULL; current = current->next)
	{
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(transporter.file);
		free(transporter.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(transporter.file);
		free(transporter.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	remainder = current->next->n % current->n;
	current->next->n = remainder;
	*head = current->next;
	free(current);
}

/**
 * div_top_two - This function divides the top two elements of the stack.
 * @head: The stack head
 * @counter: The line_number
 * Return: Nothing
*/
void div_top_two(stack_t **head, unsigned int counter)
{
	stack_t *current_node;
	int length = 0, temp;

	current_node = *head;
	while (current_node)
	{
		current_node = current_node->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(transporter.file);
		free(transporter.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current_node = *head;
	if (current_node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(transporter.file);
		free(transporter.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = current_node->next->n / current_node->n;
	current_node->next->n = temp;
	*head = current_node->next;
	free(current_node);
}
