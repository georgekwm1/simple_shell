#include "main.h"

/**
 * executor_2 - Gets enviroment variables
 * @envir_paths: argurments
 *
 * Return: String.
 */

char **executor_2(char **envir_paths)
{
	int i;
	int env_count = 0;
	char **env;
	char **envp = envir_paths;

	while (envp[env_count] != NULL)
	{
		env_count++;
	}

	env = (char **)malloc((env_count + 1) * sizeof(char *));

	for (i = 0; i < env_count; i++)
	{
		env[i] = _getenv(envp[i]);
	}
	env[env_count] = NULL;

	return (env);
}
