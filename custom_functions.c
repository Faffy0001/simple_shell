#include "shell.h"

/**
 *my_fork - forks a new process and executes the given command
 *@com: an array of pointers to the arguments for the command
 *@arg: an array of pointers to the environment variables
 *@env: an array of pointers to the environment variables
 *@line: a pointer to the line of input that was read from the user
 *@nmp: the number of parameters in the command
 *@isp: a flag indicating whether the command was entered at the prompt
 *Return: The status of the child process.
 */

int my_fork(char **com, char **arg, char **env, char *line, int nmp, int isp)
{
	pid_t child;
	int status, i = 0;
	char *format = "%s: %d: %s: not found\n";
	char *builtin_commands[] = {"cd", "help", "exit", "^D"};

	int (*builtin_functions[]) (char **) = {&change_directory,
		&display_help, &exit_shell, &handle_ctrld};

	if (com[0] == NULL)
		return (1);

	for (i = 0; i < num_builtins(); i++)
	{
		if (string_compare(com[0], builtin_commands[i]) == 0)
			return (builtin_functions[i](com));
	}

	child = fork();
	if (child == 0)
	{
		if (execve(com[0], com, env) == -1)
		{
			fprintf(stderr, format, arg[0], nump, com[0]);
			if (!is_p)
				free(com[0]);
			free(com);
			free(line);
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
 * whitespace_check - checks if the given string contains only whitespace
 * @str: a pointer to the string to be checked
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
 * get_path_string - returns a pointer to the PATH environment variable.
 * @env: an array of pointers to environment variables
 * Return: a pointer to the PATH environment variable, or NULL
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
 * get_env - prints all environment variables to standard output.
 * @env: an array of pointers to environment variables
 */
void get_env(char **env)
{
	size_t index = 0;

	while (env[index])
	{
		write(STDOUT_FILENO, env[index], string_length(env[index]));
		write(STDOUT_FILENO, "\n", 1);
		index++;
	}
}

/**
 * getline_command - reads a line of input from the user
 * Return:  a pointer to the line of input, or NULL if an error occurred
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
