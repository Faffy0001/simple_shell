#include "shell.h"

/**
 *my_fork - creates a child process and executes the command.
 *@arg: list of arguments passed to the function.
 *@av: list of arguments passed to the program.
 *@env: list of environment variables.
 *@lineptr: pointer to the input buffer.
 *@np: line number in the script file.
 *@c: flag to indicate whether the command is executed in the main process.
 *Return: The status of the child process.
 */

int my_fork(char **arg, char **av, char **env, char *lineptr, int np, int c)
{
	pid_t child;
	int status, i = 0;
	char *format = "%s: %d: %s: not found\n";
	char *builtin_commands[] = {"cd", "help", "exit", "^D"};

	int (*builtin_functions[]) (char **) = {&change_directory,
		&display_help, &exit_shell, &handle_ctrld};

	if (arg[0] == NULL)
		return (1);

	for (i = 0; i < num_builtins(); i++)
	{
		if (string_compare(arg[0], builtin_commands[i]) == 0)
			return (builtin_functions[i](arg));
	}

	child = fork();
	if (child == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, format, av[0], np, arg[0]);
			if (!c)
				free(arg[0]);
			free(arg);
			free(lineptr);
			exit(errno);
		}
	} else
	{
		wait(&status);
		return (status);
	}

	return (0);
}

/**
 * whitespace_check - checks if the string contains only whitespace
 * @str: pointer to a string
 * Return: -1 if it has whitespace, 0 if not
 */
int whitespace_check(const char *str)
{
	while (*str != '\0')
	{
		if (*str != ' ' && *str != '\t' && *str != '\n' && *str != '\r')
		{
			return (0);
		}
		str++;
	}
	return (-1);
}

/**
 * get_path_string - find the PATH env
 * @env: array of strings
 * Return: returns the path for execve() or NULL on failure
 */

char *get_path_string(char **env)
{
	size_t index = 0, var = 0, count = 5;
	char *path = NULL;

	for (index = 0; string_compare_n(env[index], "PATH=", 5); index++)
		;

	if (env[index] == NULL)
		return (NULL);

	for (count = 5; env[index][var]; var ++, count++)
		;

	path = malloc(sizeof(char) * (count + 1));

	if (path == NULL)
		return (NULL);

	for (var = 5, count = 0; env[index][var]; var ++, count++)
		path[count] = env[index][var];

	path[count] = '\0';
	return (path);
}

/**
 * get_env - prints all environment variables
 * @env: string of arrays
 */
void get_env(char **env)
{
	size_t index = 0;

	while (env[index])
	{
		write(STDOUT_FILENO, env[index], string_length(env[index]))
		write(STDOUT_FILENO, "\n", 1);
		index++;
	}
}

/**
 * getline_command - captures user input
 * Return: pointer to the input
 */

char *getline_command(void)
{
	char *lineptr = NULL;
	size_t charter_user = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&lineptr, &charter_user, stdin) == -1)
	{
		free(lineptr);
		return (NULL);
	}

	return (lineptr);
}
