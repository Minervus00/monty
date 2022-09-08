#include "monty.h"
#include <stdio.h>

/**
 * nop_fct - doesn't do anything
 * @head: the head
 * @line_number: line_num
 * Return: nothing
 */
void nop_fct(__attribute__((unused)) stack_t **head, unsigned int line_number)
{
	(void) line_number;
}

/**
 * sub_fct - subtracts the top element of the stack from the second top
 * @head: the head
 * @line_number: line_num
 * Return: nothing
 */
void sub_fct(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	int lnu = line_number;

	if ((*head) == NULL || (*head)->next == NULL)
	{
		if (*head)
			free(*head);
		fprintf(stderr, "L%d: can't sub, stack too short\n", lnu);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	((*head)->next)->n -= (*head)->n;
	*head = (*head)->next;
	free(tmp);
}

/**
 * div_fct - divides the second top element of the stack by the top element
 * @head: the head
 * @line_number: line_num
 * Return: nothing
 */
void div_fct(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	int lnu = line_number;

	if ((*head) == NULL || (*head)->next == NULL)
	{
		if (*head)
			free(*head);
		fprintf(stderr, "L%d: can't div, stack too short\n", lnu);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		free_stack(*head);
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *head;
	((*head)->next)->n /= (*head)->n;
	*head = (*head)->next;
	free(tmp);
}

/**
 * mul_fct - multiplies the second top element of the stack with the top one
 * @head: the head
 * @line_number: line_num
 * Return: nothing
 */
void mul_fct(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	int lnu = line_number;

	if ((*head) == NULL || (*head)->next == NULL)
	{
		if (*head)
			free(*head);
		fprintf(stderr, "L%d: can't mul, stack too short\n", lnu);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	((*head)->next)->n *= (*head)->n;
	*head = (*head)->next;
	free(tmp);
}

/**
 * mod_fct - second top element % (mod) the top one
 * @head: the head
 * @line_number: line_num
 * Return: nothing
 */
void mod_fct(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	int lnu = line_number;

	if ((*head) == NULL || (*head)->next == NULL)
	{
		if (*head)
			free(*head);
		fprintf(stderr, "L%d: can't mod, stack too short\n", lnu);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		free_stack(*head);
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *head;
	((*head)->next)->n %= (*head)->n;
	*head = (*head)->next;
	free(tmp);
}
