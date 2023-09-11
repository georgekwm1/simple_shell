#include "main.h"

/**
 * main - Main
 *
 * Return: 0
 */

int main(void)
{
	char *line = NULL;
	char *args[MAX_ARGS + 1];
	size_t len = 0;
	ssize_t read;
	bool piped_input = !isatty(STDIN_FILENO);

	while (1)
	{

		line = read_input_line(&len, &read);
		_exit_status(line);
		if (line == NULL || strcmp(line, "exit") == 0)
		{
			free(line);
			break;
		}
		if (piped_input)
		{
			char *batch = line;
			char *batch_line = _strtok(batch, "\n");
			while (batch_line != NULL)
			{
				parse_input(batch_line, args);
				execute_command(args);
				batch_line = _strtok(NULL, "\n");
			}
		}
		else if (strcmp(args[0], "cd") == 0)
		{

			change_dir(line);
		}
		else
		{
			parse_input(line, args);
			execute_command(args);
		}
		free(line);

		if (piped_input)
		{
			break;
		}
	}

	return (0);
}
