#include "monty.h"
#include <stdio.h>

/**
 * pchar_fct - prints the char at the head of stack
 * @head: the head
 * @line_number: line_num
 * Return: nothing
 */
void pchar_fct(stack_t **head, unsigned int line_number)
{
	int num;

	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = (*head)->n;
	if ( num < 32 || num > 127) /*if check problm just check num > 127*/
	{
		free_stack(*head);
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", num);
}

/**
 * pstr_fct - prints the string starting at the top of the stack
 * @head: the head
 * @line_number: line_num
 * Return: nothing
 */
void pstr_fct(stack_t **head, unsigned int line_number)
{
	stack_t *buff = *head;
	int num;
	(void) line_number;

	while(buff)
	{
		num = buff->n;
		if (num == 0 || num > 127)
			break;
		printf("%c", num);
		buff = buff->next;
	}
	printf("\n");
}