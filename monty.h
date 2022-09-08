#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

extern char stack_type[6]; /*stack by default, or queue*/

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int execute_line(stack_t **head, char *line, int lnum);
int checkop(stack_t **head, char *line, instruction_t *ops, int lnum);

void print_error(char *msg);
void pall_fct(stack_t **h, unsigned int line_number);
void push_fct(stack_t **head, unsigned int argint);
void pint_fct(stack_t **head, unsigned int line_number);
void pop_fct(stack_t **head, unsigned int line_number);
void swap_fct(stack_t **head, unsigned int line_number);
void add_fct(stack_t **head, unsigned int line_number);
void nop_fct(stack_t **head, unsigned int line_number);
void sub_fct(stack_t **head, unsigned int line_number);
void div_fct(stack_t **head, unsigned int line_number);
void mul_fct(stack_t **head, unsigned int line_number);
void mod_fct(stack_t **head, unsigned int line_number);
void pchar_fct(stack_t **head, unsigned int line_number);
void pstr_fct(stack_t **head, unsigned int line_number);
void free_stack(stack_t *head);

#endif /* MONTY_H */