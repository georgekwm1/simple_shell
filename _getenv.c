#include "main.h"

/**
 * getenv - Searches for enviroment variables
 * @name: Name of env variable to search for
 *
 * Return: String.
 */

extern char **environ;

char *_getenv(const char *name)
{
	char **env = environ;

	while (*env != NULL)
	{
		char *current_env_var = *env;
		int i = 0;

		while (current_env_var[i] && current_env_var[i] != '=')
		{
			i++;
		}

		if (current_env_var[i] == '=')
		{

			if (strncmp(current_env_var, name, i) == 0)
			{

				return current_env_var + i + 1;
			}
		}

		env++;
	}

	return NULL;
}

