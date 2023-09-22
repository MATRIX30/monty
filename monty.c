#include "monty.h"
int main(int ac, char **av);
/**
 * main - this is the main monty intepreter program
 * @ac: argument count
 * @av: array of arguments
 * Return: 0 if success 1 otherwise
*/
int main(int ac, char **av)
{
	cmd_line_t *cmd_line;
	char *lineptr = NULL;
	char *lines[200] = {NULL};
	size_t n = 0;
	unsigned int i = 0;

	FILE *file_ptr;

	instruction_t operations[1] = {
		{"push", push}
	};

	/*stack_t *stack_h = NULL;*/

	/*check if no file argument was provided*/
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file_ptr = fopen(av[1], "r");
	cmd_line = malloc(sizeof(cmd_line_t));
	if (cmd_line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		cmd_line->opcode = NULL;
		cmd_line->arg = NULL;
		cmd_line->linenumber = 0;
		cmd_line->stack_head = NULL;
		free(cmd_line);

		return (EXIT_FAILURE);
	}
	while (getline(&lineptr, &n, file_ptr) != -1)
	{
		lines[i] = strdup(lineptr);
		cmd_line->opcode = strtok(lines[i], " ");
		cmd_line->arg = strtok(NULL, " ");
		cmd_line->linenumber = i + 1;
		/*printf("%s--- %s\n",cmd_line->opcode,cmd_line->arg);*/
		/* performing operations*/
		if (strcmp(cmd_line->opcode, "push") == 0)
		{
			if (cmd_line->arg == NULL || is_alphas(cmd_line->arg) == 1)
			{
				fprintf(stderr, "L1: unknown instruction %s", cmd_line->opcode);
				break;
			}
			operations->f(&cmd_line->stack_head, atoi(cmd_line->arg));
		}

		i += 1;
		free(lines[i]);
	}
	lines[i] = NULL;
	fclose(file_ptr);
	free(lineptr);
	free(cmd_line);
	free_cmds(lines);
	return (0);
}
