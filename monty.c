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
	char *lineptr = NULL;
	/*char *lines[20000] = {NULL};*/
	size_t n = 0;
	unsigned int i = 0;

	FILE *file_ptr;

	/*stack_t *stack_h = NULL;*/

	/*check if no file argument was provided*/
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file_ptr = fopen(av[1], "r");
	if (file_ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	cmd_line = malloc(sizeof(cmd_line_t));
	if (cmd_line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}
	cmd_line->opcode = NULL;
	cmd_line->arg = NULL;
	cmd_line->linenumber = 0;
	cmd_line->stack_head = NULL;

	while (getline(&lineptr, &n, file_ptr) != -1)
	{

		cmd_line->opcode = strtok(lineptr, " \n");
		cmd_line->arg = strtok(NULL, " \n");
		cmd_line->linenumber = i + 1;
		/*printf("%s--- %s\n",cmd_line->opcode,cmd_line->arg);*/

		/* performing operations*/

		executor();

		i += 1;
		free(lineptr);
		lineptr = NULL;
		n = 0;
	}


	fclose(file_ptr);
	free(cmd_line);
	free_stack(&(cmd_line->stack_head));
	return (0);
}
