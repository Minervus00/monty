#include "monty.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

char stack_type[6] = "stack";

/**
 * main -  the main function
 * @argc: number of args
 * @argv: array of args in str format
 * Return: EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
	FILE *fp;
	char *file, line[128];
	stack_t *head = NULL;
	unsigned int lnum = 0;

	if (argc != 2)
		print_error("USAGE: monty file");
	file = argv[1];
	fp = fopen(file, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	while ((fgets(line, sizeof(line), fp)) != NULL)
	{
		lnum++;
		strtok(line, "\n");
		/*printf("line = %s and poo\n", line);*/
		execute_line(&head, line, lnum);
		/*printf("L%d: %s\n", lnum, line);*/
	}
	if (lnum == 0)
		printf("Empty!\n");

	fclose(fp);
	free_stack(head);
	exit(EXIT_SUCCESS);
}
