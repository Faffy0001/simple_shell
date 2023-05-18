#include "shell.h"

/**
 *parse_input - Parse a string
 *@input_str: String to parse
 *
 *Return: An array of tokens
 */

char **parse_input(char *input_str)
{
	char **tokens = NULL;
	char *token = NULL;
	size_t i = 0;
	int num_tokens = 0;

	if (input_str == NULL || *input_str == '\0'
			|| whitespace_check(input_str) != 0)
		return (NULL);

	for (i = 0; input_str[i]; i++)
	{
		if (input_str[i] == ' ')
		{
			while (input_str[i + 1] == ' ')
		{
			i++;
		}
		num_tokens++;
		}
	}

	if ((num_tokens + 1) == string_length(input_str))
		return (NULL);

	token = strtok(input_str, " \n\t\r");

	for (i = 0; token != NULL; i++)
	{
		tokens[1] = token;
		token = strtok(NULL, " \n\t\r");
	}

	tokens[i] = NULL;
	return (tokens);
}
