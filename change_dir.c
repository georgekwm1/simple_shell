#include "main.h"

/**
 * change_dir - Handles change of directory
 * @line: name of directory
 *
 * Return: Nothing
 */

void change_dir(char *line)
{
	char *token;
	int tokenCount = 0;

	token = _strtok(line, " ");

	while (1)
	{
		if (token == NULL)
		{
			free(line);
			break;
		}
		if (strcmp(token, "cd") == 0)
		{
			if ((token = _strtok(NULL, " ")) != NULL)
			{
				while (token != NULL)
				{
					tokenCount++;
					if (tokenCount == 2)
					{
						const char *newDirectory = token;
						if (chdir(newDirectory) == 0)
						{

							printf("Sucessfully Changed directory\n");
							break;
						}
						else
						{
							perror("chdir");
						}
						token = _strtok(NULL, " ");
					}
				}
			}
			else
			{
				const char *homeDirectory = _getenv("HOME");
				if (homeDirectory != NULL)
				{
					if (chdir(homeDirectory) == 0)
					{
						printf("Successfully changed to the home directory\n");
					}
					else
					{
						perror("chdir");
					}
				}
				else
				{
					fprintf(stderr, "HOME environment variable not set\n");
				}

				return;
			}
		}
		else
		{
			free(line);
			return;
		}
	}
}
