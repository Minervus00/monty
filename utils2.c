#include "monty.h"
#include <stdio.h>

/**
 * print_error - print error to stderr
 * @msg: the msg to be printed
 * Return: nothing
 */
void print_error(char *msg)
{
	fprintf(stderr, msg);
	exit(EXIT_FAILURE);
}

/**
 * free_stack - frees a doubly linked list
 * @head: head
 * Return: nothing
 */
void free_stack(stack_t *head)
{
	stack_t *buff = head, *tmp;

	while (buff)
	{
		tmp = buff;
		buff = buff->next;
		free(tmp);
	}
}

/**
 * pint_fct - prints the head of stack
 * @head: the head
 * @line_number: line_num
 * Return: nothing
 */
void pint_fct(stack_t **head, unsigned int line_number)
{
	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

 /**
  * swap_fct - swaps the top two elements of the stack
  * @head: the head
  * @line_number: line_num
  * Return: nothing
  */
void swap_fct(stack_t **head, unsigned int line_number)
{
	int tmp;

	if ((*head) == NULL || (*head)->next == NULL)
	{
		if (*head)
			free(*head);
		fprintf(stderr, \
			"L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->n;
	(*head)->n = ((*head)->next)->n;
	((*head)->next)->n = tmp;
}

/**
 * add_fct - adds the top two elements of the stack
 * @head: the head
 * @line_number: line_num
 * Return: nothing
 */
void add_fct(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	if ((*head) == NULL || (*head)->next == NULL)
	{
		if (*head)
			free(*head);
		fprintf(stderr, \
			"L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	((*head)->next)->n += (*head)->n;
	*head = (*head)->next;
	free(tmp);
}
