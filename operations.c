#include "monty.h"
cmd_line_t *cmd_line;
int j = 0,  op_count = 2;

instruction_t operations[2] = {
		{"push", push},
		{"pall", pall}
	};

/**
 * push - pushes an element to the stack
 * @stack_h: head to the main stack
 * @n: integer element to push to stack
 * Return EXIT_FAILURE else otherwise
*/
void push(stack_t **stack_h, unsigned int n);
void push(stack_t **stack_h, unsigned int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (*stack_h == NULL)
	{
		*stack_h = new_node;
		new_node->prev = *stack_h;
	}
	else
	{
		new_node->next = *stack_h;
		(*stack_h)->prev = new_node;
		new_node->prev = *stack_h;
		*stack_h = new_node;
	}

}

/**
 * pall - prints all the values onm the top of the stack
 * @stack: head of the stack
 * Return: exit with status code
*/
void pall(stack_t **stack, unsigned int n)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s", n, cmd_line->opcode);
		exit(EXIT_FAILURE);
	}
	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
	exit(EXIT_SUCCESS);
}
/**
 * executor - functiont to execute code
*/
void executor(void)
{
	while (j < op_count)
	{
		if (strcmp(cmd_line->opcode, "push") == 0)
		{
			if (cmd_line->arg == NULL || is_alphas(cmd_line->arg) == 1)
			{
				fprintf(stderr, "L1: unknown instruction %s", cmd_line->opcode);
				break;
			}
			operations->f(&cmd_line->stack_head, atoi(cmd_line->arg));
		}
		j += 1;
	}
}
