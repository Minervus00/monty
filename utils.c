#include "monty.h"
#include <string.h>
#include <stdio.h>

/**
 * pall_fct - prints all the elements of a stack or queue
 * @head: list head
 * @line_number: unsigned int
 * Return: nothing
 */
void pall_fct(stack_t **head, unsigned int line_number)
{
	stack_t *buff = NULL;
	(void) line_number;

	if (*head == NULL)
		return;
	printf("%d\n", (*head)->n);
	buff = (*head)->next;
	while (buff)
	{
		printf("%d\n", buff->n);
		buff = buff->next;
	}
}

/**
 * add_dnodeint - adds a new node at the top of stack
 * @head: head
 * @n: int
 * Return: int
 */
int add_dnodeint(stack_t **head, unsigned int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free_stack(*head);
		print_error("Error: malloc failed");
	}
	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
	return (0);
}

/**
 * add_dnodeint_end - adds a new node at the end of the queue.
 * @head: head
 * @n: int
 * Return: int
 */
int add_dnodeint_end(stack_t **head, unsigned int n)
{
	stack_t *new, *buff;

	buff = *head;
	while (buff)
	{
		if (buff->next == NULL)
			break;
		buff = buff->next;
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free_stack(*head);
		print_error("Error: malloc failed");
	}
	new->n = n;
	new->prev = buff;
	new->next = NULL;
	if (buff != NULL)
		buff->next = new;
	else
		*head = new;
	return (0);
}

/**
 * push_fct - prints all the elements of a stack or queue
 * @head: list head
 * @argint: unsigned int
 * Return: nothing
 */
void push_fct(stack_t **head, unsigned int argint)
{
	/*printf("type = %s\n", stack_type);*/
	if (!strcmp(stack_type, "stack"))
	{
		add_dnodeint(head, argint);
		return;
	}
	add_dnodeint_end(head, argint);
}

/**
 * pop_fct - deletes the head (both stack or queue mode)
 * @head: head
 * @line_number: line_number
 * Return: nothing
 */
void pop_fct(stack_t **head, unsigned int line_number)
{
	stack_t *buff = *head;

	if (*head != NULL)
	{
		*head = buff->next;
		free(buff);
		return;
	}
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
}
