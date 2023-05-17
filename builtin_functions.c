#include "main.c"

/**
 * num_builtins - returns the number of built-in functions.
 * Return: The number.
 */

int num_builtins(void)
{
	char *builtin_commands[] = {"cd", "help", "exit", "^D"};

	return (sizeof(builtin_commands) / sizeof(char *));
}

/**
 *change_directory - changes the current working directory.
 *@args: list of arguments passed to the function.
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
 *display_help - displays the help information.
 *@args: list of arguments passed to the function.
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
 *exit_shell - exits the shell.
 *@args: list of arguments passed to the function.
 *Return: Always returns 200.
 */
int exit_shell(char **args)
{
	(void) args;
	free(args);
	return (200);
}

/**
 *handle_ctrld - exits the shell when ^D is entered.
 *@args: list of arguments passed to the function.
 *Return: Always returns 200.
 */
int handle_ctrld(char **args)
{
	(void) args;
	free(args);
	return (200);
}
