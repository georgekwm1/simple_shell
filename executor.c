#include "main.h"

/**
 * execute_command - executes command
 * @args: argurments
 *
 * Return: Nothing
 */

void execute_command(char *args[])
{
	char *environ[] = {"PATH", "HOME", "LANG", NULL};
	pid_t pid;
	int status, i;

	pid = fork();

	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		char **env = executor_2(environ);

		if (strcmp(args[0], "/") == 0)
		{
			if (execve(args[0], args, env) == -1)
			{
				perror("execve");
				exit(1);
			}
		}
		else
		{
			if (execvp(args[0], args) == -1)
			{
				perror("execvp");
				exit(1);
			}
		}
		for (i = 0; env[i] != NULL; i++)
		{
			free(env[i]);
		}
		free(env);
	}
	else
	{
		wait(&status);
	}
}

