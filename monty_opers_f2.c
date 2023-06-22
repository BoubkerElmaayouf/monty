#include "monty.h"
/**
  *op_nop- Does nothing.
  *@head: The stack head
  *@line_number: The line_number
  *Return: Nothting
 */
void op_nop(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
}

/**
 * op_pall - this function prints the stack
 * @head: The stack head
 * @line_number: Usless
 * Return: Nothing
*/
void op_pall(stack_t **head, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *head;
	if (current == NULL)
		return;
	for (; current != NULL; current = current->next)
    {
        printf("%d\n", current->n);
    }
}

/**
 * op_pchar - this function prints the char at the top of
 * the stack,followed by a new line
 * @head: The stack head
 * @counter: the line_number
 * Return: Nothing
*/
void op_pchar(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	current = *head;
	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(transporter.file);
		free(transporter.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (current->n > 127 || current->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(transporter.file);
		free(transporter.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", current->n);
}

/**
 * op_pint - This function prints the top
 * @head: The stack head
 * @line_number: The line_number
 * Return: Nothing
*/
void op_pint(stack_t **head, unsigned int line_number)
{
	if (!*head)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(transporter.file);
		free(transporter.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

