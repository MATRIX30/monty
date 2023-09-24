#include "monty.h"
cmd_line_t *cmd_line = NULL;

instruction_t operations[1] = {
		{"push", push},
	};
instruction_t *ptr = operations;
/**
 * executor - functiont to execute code
*/

void executor(void)
{
	int x = cmd_line->linenumber;
	/*
	instruction_t operations[4] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};
	 while (ptr->opcode)
	{
		printf("%s ",ptr->opcode);
		if (strcmp(cmd_line->opcode, ptr->opcode) == 0)
		{
			if (cmd_line->stack_head == NULL)
			{
				fprintf(stderr, "L%u: can't pint, stack empty \n", x);
				free(cmd_line->opcode);
				free(cmd_line->arg);
				exit(EXIT_FAILURE);
			}
			ptr->f(&cmd_line->stack_head,cmd_line->linenumber);
		}
		ptr += 1;
	}
		fprintf(stderr, "L%u:unknown instruction %s\n", x, cmd_line->opcode);
		free(cmd_line->opcode);
		free(cmd_line->arg);
		exit(EXIT_FAILURE);
	*/
	if (strcmp(cmd_line->opcode, "push") == 0)
	{
		if (cmd_line->arg == NULL || is_alphas(cmd_line->arg) == 1)
		{
			fprintf(stderr, "L%u: unknown instruction %s", x, cmd_line->opcode);
			exit(EXIT_FAILURE);
		}
		operations->f(&cmd_line->stack_head, atoi(cmd_line->arg));
	}
	else if (strcmp(cmd_line->opcode, "pall") == 0)
	{
		pall(&cmd_line->stack_head, cmd_line->linenumber);
	}
	else if (strcmp(cmd_line->opcode, "pint") == 0)
	{
		if (cmd_line->stack_head == NULL)
		{
			fprintf(stderr, "L%u: can't pint, stack empty \n", x);
			exit(EXIT_FAILURE);
		}
		pint(&cmd_line->stack_head, cmd_line->linenumber);
	}
	else
	{
		fprintf(stderr, "L%u:unknown instruction %s\n", x, cmd_line->opcode);
		free(cmd_line->opcode);
		free(cmd_line->arg);
		exit(EXIT_FAILURE);
	}
}
