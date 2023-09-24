#ifndef MONTY_HEAD
#define MONTY_HEAD
/* Libraries*/
#define  _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*Macros*/
#define READ_SIZE 1024
#define BUFFER_SIZE 10000


/* Data Structures*/
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

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to hanlde the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct cmd_line_s
{
	char *opcode;
	char *arg;
	unsigned int linenumber;
	stack_t *stack_head;
} cmd_line_t;

/*Global Variables*/
extern cmd_line_t *cmd_line;


/*Functions*/
void push(stack_t **stack, unsigned int n);
void pall(stack_t **stack, unsigned int n);
void pint(stack_t **stack, unsigned int n);
int main(int ac, char **av);
void printerr_msg(int line_number, char *msg);
int is_spaces(char *s);
int is_numbers(const char *s);
int is_alphas(const char *s);
void free_cmds(char **lines);
void free_stack( stack_t **stack_head);
void executor(void);
#endif
