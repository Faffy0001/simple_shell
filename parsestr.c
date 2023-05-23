#include "shell.h"

/**
 *parse_input - parses the given input string into an array of tokens.
 *@input_str: the input string to parse
 *Return: An array of tokens
 */

char **parse_input(char *input_str)
{
	char *token, **tokens = NULL;
	size_t i = 0;
	int num_tokens = 0;

	if (input_str == NULL || *input_str == '\0' ||
			whitespace_check(input_str) != 0)
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
	tokens = malloc(sizeof(char *) * (num_tokens + 2));
	if (tokens == NULL)
		return (NULL);

	token = strtok(input_str, " \n\t\r");

	for (i = 0; token != NULL; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, " \n\t\r");
	}

	tokens[i] = NULL;
	return (tokens);
}
