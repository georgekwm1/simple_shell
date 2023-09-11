#include "main.h"

/**
 * read_input_line - Reads input from stdin
 * @len: memory allocated to input
 * @read: Returns 0 on success or integer on failure
 *
 * Return: String.
 */

char *read_input_line(size_t *len, ssize_t *read)
{
	char *line = NULL;
	*read = _getline(&line, len, stdin);

	if (*read == -1)
	{
		return NULL;
	}

	line[strcspn(line, "\n")] = '\0';
	return line;
}

