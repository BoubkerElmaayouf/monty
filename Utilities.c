#include "monty.h"
/**
  * rotl_f - This function rotates the stack to the top
  * @head: The stack head
  * @line_number: The line_number (Unused)
  * Return: Nothing
 */
void rotl_f(stack_t **head,  __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp = *head, *result;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	result = (*head)->next;
	result->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	(*head) = result;
}

/**
  * rotr_f - This function rotates the stack to the bottom
  * @head: The stack head
  * @line_number: The line_number (Unused) 
  * Return: Nothing
 */
void rotr_f(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}

/**
 * swap_f - This function adds the top two elements of the stack.
 * @head: The stack head
 * @counter: The line_number
 * Return: Nothing
*/
void swap_f(stack_t **head, unsigned int line_number)
{
	stack_t *current;
	int length = 0, result;

	current = *head;
	while (current != NULL)
	{
		current = current->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(transporter.file);
		free(transporter.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	result = current->n;
	current->n = current->next->n;
	current->next->n = result;
}
