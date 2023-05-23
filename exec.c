#include "shell.h"

/**
 * find_executable_path - finds the path to the executable file for command.
 * @command: a pointer to the command to find the path for
 * @env_vars: a pointer to an array of environment variables
 * Return: 0 on success, -1 on failure
 */

int find_executable_path(char **command, char **env_vars)
{
	char *token = NULL, *path_str = NULL, *abs_path = NULL;
	size_t path_len, arg_len;
	struct stat file_stat;

	if (stat(*command, &file_stat) == 0)
		return (-1);
	path_str = get_path_string(env_vars);
	if (!path_str)
		return (-1);
	token = strtok(path_str, ":");
	arg_len = string_length(*command);
	while (token)
	{
		path_len = string_length(token);
		abs_path = malloc(sizeof(char) * (path_len + arg_len + 2));
		if (!abs_path)
		{
			free(path_str);
			return (-1);
		}

		abs_path = strcpy(abs_path, token);
		string_concat(abs_path, "/");
		string_concat(abs_path, *command);

		if (stat(abs_path, &file_stat) == 0)
		{
			*command = abs_path;
			free(path_str);
			return (0);
		}

		free(abs_path);
		token = strtok(NULL, ":");
	}

	token = '\0';
	free(path_str);
	return (-1);
}

