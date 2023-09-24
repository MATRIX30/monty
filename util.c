#include "monty.h"
/**
 * is_spaces - function to verify if a string is made up of spaces only
 * @s: string to verfiy
 * Return: 1 if true 0 otherwise
*/
int is_spaces(char *s)
{
	if (s == NULL)
		return (0);
	while (*s)
	{
		if (!isspace(*s))
		{
			return (0);
		}
		s++;
	}
	return (1);
}

/**
 * is_numbers - function to check if string contains numbers
 * @s: string to check
 * Return: 1 if true and 0 otherwise
*/
int is_numbers(const char *s)
{
	if (s == NULL)
		return (0);
	while (*s)
	{
		if (!isdigit(*s))
		{
		return (0);
		}
		s++;
	}
	return (1);
}
/**
 * is_alphas - function to check if string contains alphabets
 * @s: string to check
 * Return: 1 if true and 0 otherwise
*/

int is_alphas(const char *s)
{
	if (s == NULL)
	{
		return (0);
	}
	while (*s)
	{
		if (!isalpha(*s))
		{
		return (0);
		}
		s++;
	}
	return (1);
}

/**
 * free_cmds - function to free global variable
 * @lines: lines to free
*/
void free_cmds(char **lines)
{
	int i = 0;

	while (lines[i] == NULL)
	{
		free(lines[i]);
		i += 1;
	}
}
/**
 * free_stack - a function to free the stack
 * @stack_head: the head of the pionter
*/
void free_stack(stack_t **stack_head)
{
	stack_t *tmp = NULL;

	if (stack_head == NULL || *stack_head == NULL)
	{
		return;
	}
	while (*stack_head)
	{
		tmp = *stack_head;
		*stack_head = (*stack_head)->next;
		free(tmp);
	}
}
