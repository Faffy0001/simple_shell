#include "shell.h"

/**
 * num_builtins - returns the number of built-in functions.
 * Return: the number of builtin commands
 */

int num_builtins(void)
{
	char *builtin_commands[] = {"cd", "help", "exit", "^D"};

	return (sizeof(builtin_commands) / sizeof(char *));
}

/**
 *change_directory - changes the current working directory
 *@args:  an array of pointers to strings
 *Return: Always returns 1.
 */
int change_directory(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "hsh: expected argument to \"cd\"\n");
	} else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh");
		}
	}
	return (1);
}

/**
 *display_help - prints a list of builtin commands to standard output.
 *@args: an array of pointers to strings, where the first string is
 *Return: Always returns 1.
 */
int display_help(char **args)
{
	int i;
	char *builtin_commands[] = {"cd", "help", "exit", "^D"};

	printf("man");
	printf("If help call, man\n");
	(void) args;

	for (i = 0; i < num_builtins(); i++)
	{
		printf("  %s\n", builtin_commands[i]);
	}

	return (1);
}

/**
 *exit_shell - exits the shell program.
 *@args: an array of pointers to strings, which is ignored
 *Return: 200.
 */
int exit_shell(char **args)
{
	(void) args;
	free(args);
	return (200);
}

/**
 *handle_ctrld - exits the shell when user types ^D
 *@args:an array of pointers to strings, which is ignored
 *Return: 200.
 */
int handle_ctrld(char **args)
{
	(void) args;
	free(args);
	return (200);
}
