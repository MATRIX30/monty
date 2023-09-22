#include "monty.h"
/**
 * main - this is the main monty intepreter program
 * @ac: argument count
 * @av: array of arguments
 * Return: 0 if success 1 otherwise
*/
int main(int ac, char **av);
int main(int ac, char **av)
{
	
	int fd;
	char *lineptr = NULL;
	char *lines[200] = {NULL};
	char *args[2] = {NULL, NULL};
	size_t n = 0;
	int i = 0;

	cmd_line_t *cmd_line = NULL;
	FILE *file_ptr;

	/*check if no file argument was provided*/
	if (ac != 2)
	{
		fprintf(stderr,"USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file_ptr = fopen(av[1], "r");
	while (getline(&lineptr, &n, file_ptr) != -1)
	{
		
		lines[i] = strdup(lineptr);
		args[0] = strtok(lines[i], " ");
		args[1] = strtok(NULL, " ");
		printf("%s--- %s\n",args[0],args[1]);
		i += 1;
	}
	lines[i] = NULL;

	/* opening of file */
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		/* print error message and exit if cant open file*/
		fprintf(stderr,"Error: Can't open file %s\n" ,av[1]);
		return (EXIT_FAILURE);
	}

	cmd_line = malloc(sizeof(cmd_line_t));
	if (cmd_line == NULL)
	{
		fprintf(stderr,"Error: malloc failed\n");
		cmd_line->file_ptr = NULL;
		free(cmd_line);
		return (EXIT_FAILURE);
	}
	cmd_line->file_ptr = fopen(av[1], "r");
	if (cmd_line->file_ptr == NULL)
	{
		close(fd);
		/* print error message and exit if cant open file*/
		fprintf(stderr,"Error: Can't open file %s\n" ,av[1]);
		return (EXIT_FAILURE);
	}
	cmd_line->line = NULL;

	
	return (0);
}