#include "main.h"

/**
 * parse_input - parses input
 * @args: argurments
 * @line: input from stdin
 *
 * Return: Nothing.
 */

void parse_input(char *line, char *args[])
{
	int i = 0;
	char *token = _strtok(line, " ");

	while (token != NULL && i < MAX_ARGS)
	{
		args[i++] = token;
		token = _strtok(NULL, " ");
	}
	args[i] = NULL;
}
