#include "monty.h"

/**
* free_stack - This function frees a doubly linked list
* @head: The head of the stack
* Return: Nothing
*/
void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
* main - representing the monty code interpreter
* @argc: The number of arguments
* @argv: The monty file location
* Return: On success return 0
*/
int main(int argc, char *argv[])
{
	transport transporter = {NULL, NULL, NULL, 0};
	FILE *monty_file;
	size_t content_size  = 0;
	ssize_t num_chars_read  = 1;
	stack_t *stack = NULL;
	char *content;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");
	transporter.file = monty_file;
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (num_chars_read  > 0)
	{
		content = NULL;
		num_chars_read  = getline(&content, &content_size, monty_file);
		transporter.content = content;
		count++;
		if (num_chars_read  > 0)
		{
			execute(content, &stack, count, monty_file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(monty_file);
	return (0);
}

