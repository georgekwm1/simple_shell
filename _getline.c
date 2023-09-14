#include "main.h"

/**
 * getline - Gets input from stream
 * @lineptr: pointer to stdin
 * @size_t: pointer to memory
 * @stream: stream
 *
 * Return: Signed Integer.
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t pos = 0;
	int c;
	char *new_ptr;

	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		{
			return -1;
		}
	}

	while ((c = fgetc(stream)) != EOF)
	{
		if (pos >= *n - 1)
		{
			*n *= 2;
			new_ptr = (char *)realloc(*lineptr, *n);
			if (new_ptr == NULL)
			{
				return -1;
			}
			*lineptr = new_ptr;
		}

		(*lineptr)[pos++] = c;

		if (c == '\n')
		{
			break;
		}
	}
	(*lineptr)[pos] = '\0';
	return pos;
}

