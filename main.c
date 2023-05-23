#include "shell.h"

/**
 *main - repeatedly reads, parses, and executes commands from the user.
 *@ac: number of command-line arguments
 *@av: array of pointers to command-line arguments
 *@env: array of pointers to environment variables
 *Return: 0 on success
 */
int main(int ac, char **av, char **env)
{
	int pathValue = 0, status = 0, is_path = 0;
	char *line = NULL, **commands = NULL;
	(void) ac;

	while (1)
	{
		errno = 0;
		line = getline_command();
		if (line == NULL && errno == 0)
			return (0);
		if (line)
		{ pathValue++;
			commands = parse_input(line);
			if (commands == NULL)
			{ free(line);
				continue; }
			else if (!string_compare(commands[0], "env"))
				get_env(env);
			else
			{
				is_path = find_executable_path(&commands[0], env);
				status = my_fork(commands, av, env,
						line, pathValue, is_path);
				if (status == 200)
				{ free(line);
					return (0); }
				if (is_path == 0)
					free(commands[0]);
			}
			free(commands);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(status);
		}
		free(line);
	}
	return (status);
}
