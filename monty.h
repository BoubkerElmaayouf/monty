#ifndef _MONTY_H
#define _MONTY_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct transport_s - contains arguments, file pointer, line content and flag
 * @arg: The argument value
 * @content: The line content
 * @flag: The flag change stack <-> queue
 * @file: The pointer to monty file
 *
 * Description: carries values through the program
 */
typedef struct transport_s
{
	char *arg;
	char *content;
	int flag;
	FILE *file;
} transport;
extern transport transporter;

/******** prototypes ********/
/*====== monty.c ======*/
void free_stack(stack_t *head);
/*====== add_node.c =======*/
void addToStack(stack_t **head, unsigned int line_number);
void push_node(stack_t **head, int n);
/*====== monty_opers_f.c =======*/
void sub_op(stack_t **head, unsigned int line_number);
void mul_op(stack_t **head, unsigned int counter);
void mod_op(stack_t **head, unsigned int counter);
void div_top_two(stack_t **head, unsigned int counter);
/*====== monty_opers_f2.c =======*/
void op_nop(stack_t **head, unsigned int line_number);
void op_pall(stack_t **head, unsigned int line_number);
void op_pchar(stack_t **head, unsigned int line_number);
void op_pint(stack_t **head, unsigned int line_number);
/*====== monty_opers_f3.c =======*/
void pop_op(stack_t **head, unsigned int line_number);
void pstr_op(stack_t **head, unsigned int line_number);
void push_op(stack_t **head, unsigned int line_number);
/*====== Utilities.c =======*/
void rotl_f(stack_t **head,  __attribute__((unused)) unsigned int line_number);
void rotr_f(stack_t **head, __attribute__((unused)) unsigned int line_number);
void swap_f(stack_t **head, unsigned int line_number);
/*====== queue_nd_stack.c =======*/
void queue_op(stack_t **head, unsigned int line_number);
void add_queue(stack_t **head, int new_value);
void stack_f(stack_t **head, unsigned int line_number);
/*====== monty_execute.c =====*/
int _execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
#endif

