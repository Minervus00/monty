#include "monty.h"
#include <ctype.h>

/**
 * stack_fct - sets the format of data to stack (LIFO)
 * @head: the head
 * @line_number: line_num
 * Return: nothing
 */
void stack_fct(stack_t **head, unsigned int line_number)
{
	(void) line_number;
	*head = *head;
	stack_type = "stack";
}

/**
 * push_error - prints error when bad usage
 * @head: head
 * @lnum: line_num
 * Return: nothing
 */
void push_error(stack_t **head, int lnum)
{
	free_stack(*head);
	fprintf(stderr, "L%d: usage: push integer\n", lnum);
	exit(EXIT_FAILURE);
}

/**
 * isnumber - check if string arg is a valid number
 * @str: a string
 * Return: 1 if a valid integer, 0 otherwise
 */
int isnumber(char *str)
{
	char c;
	int h = 0;

	if (str == NULL)
		return (0);
	while (str[h])
	{
		c = str[h];
		if (c < '0' || c > '9')
		{
			if (h == 0 && (c == '-' || c == '+'))
			{
				h++;
				continue;
			}
			break;
		}
		h++;
		if (str[h] == '\0')
			return (1);
	}
	return (0);
}

/**
 * checkop - search and execute opcode in lines
 * @head: the head
 * @line: the current line
 * @ops: an array of opcodes
 * @lnum: line_num
 * Return: int
 */
int checkop(stack_t **head, char *line, instruction_t *ops, int lnum)
{
	char *tok, *buff, *rest = line;
	unsigned int j, n;

	/* Check if line is not empty */
	tok = strtok(rest, " ");
	if ((tok) && strcmp(tok, "\n"))
	{
		if (tok[0] == '#') /*to skip comments*/
			return (0);
		for (j = 0; (buff = ops[j].opcode); j++)
		{
			/*printf("tok = %s : opc = %s\n", tok, buff);*/
			if (!strcmp(tok, buff))
			{
				/*j == 0 <=> tok is push*/
				if (j == 0)
				{
					tok = strtok(NULL, " ");
					/*printf("tok = %s\n", tok);*/
					if (isnumber(tok))
					{
						n = atoi(tok);
						ops[j].f(head, n);
						return (0);
					}
					push_error(head, lnum);
					return (0);
				}
				ops[j].f(head, lnum);
				return (0);
			}
		}
		free_stack(*head);
		fprintf(stderr, "L%d: unknown instruction %s\n", lnum, tok);
		exit(EXIT_FAILURE);
	}
	/* blank or empty line */
	return (0);
}

/**
 * execute_line - process each line
 * @head: head
 * @line: current line in file
 * @lnum: line number in file
 * Return: int
 */
int execute_line(stack_t **head, char *line, int lnum)
{
	instruction_t ops[] = {
		{"push", push_fct},
		{"pall", pall_fct},
		{"pint", pint_fct},
		{"pop", pop_fct},
		{"swap", swap_fct},
		{"add", add_fct},
		{"nop", nop_fct},
		{"sub", sub_fct},
		{"div", div_fct},
		{"mul", mul_fct},
		{"mod", mod_fct},
		{"pchar", pchar_fct},
		{"pstr", pstr_fct},
		{"rotl", rotl_fct},
		{"rotr", rotr_fct},
		{"stack", stack_fct},
		{"queue", queue_fct},
		{NULL, NULL}
	};

	return (checkop(head, line, ops, lnum));
}
