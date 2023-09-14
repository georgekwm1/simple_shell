#include "main.h"
/**
 * strtok - Tokenizes a string
 * @str: String to tokenize
 * @del: Delimeter
 *
 * Return: String.
 */

char *_strtok(char *str, const char *del)
{
	static char *next_token;
	if (str)
	{
		next_token = str;
	}
	if (!next_token)
	{
		return NULL;
	}
	str = next_token;
	while (*next_token)
	{
		if (strchr(del, *next_token))
		{
			*next_token++ = '\0';
			break;
		}
		next_token++;
	}
	return *str ? str : NULL;
}

