#include "monty.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

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
	tok = strtok_r(rest, " ", &rest);
	if ((tok) && strcmp(tok, "\n"))
	{
		if ((int) tok[0] == 35) /* (int) '#' -> 35 | to skip comments*/
			return (0);
		for (j = 0; (buff = ops[j].opcode); j++)
		{
			/*printf("tok = %s : opc = %s\n", tok, buff);*/
			if (!strcmp(tok, buff))
			{
				/*printf("found !\n");*/
				/*j == 0 <=> tok is push th*/
				if (j == 0)
				{
					tok = strtok_r(rest, " ", &rest);
					if (isdigit(tok[0]))
						n = atoi(tok);
					ops[j].f(head, n);
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
		{NULL, NULL}
	};

	return (checkop(head, line, ops, lnum));
}
