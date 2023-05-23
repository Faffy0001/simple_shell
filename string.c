#include "shell.h"

/**
 *string_copy - Copies a string from source to destination.
 *@dest: a pointer to destination string.
 *@src: a pointer to source string.
 *Return: a pointer to the new string, or NULL if an error occurred.
 */

char *string_copy(char *dest, char *src)
{
	int i = 0;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	dest[i + 1] = 0;
	return (dest);
}

/**
 *string_concat - concatenates the given strings.
 *@dest: Pointer to destination string.
 *@src: Pointer to source string.
 *Return: Pointer to concatenated string.
 */

char *string_concat(char *dest, char *src)
{
	int i, j = 0;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 *string_compare - compares two strings.
 *@s1: A pointer to first string.
 *@s2: A pointer to second string.
 *Return: an integer less than, equal to, or greater than zero
 */

int string_compare(char *s1, char *s2)
{
	int i = 0;
	int j;

	while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i])
		i++;
	j = s1[i] - s2[i];
	return (j);
}

/**
 * string_length - Gets the length of a string.
 *@s: a pointer to string.
 *Return: Length of string.
 */
int string_length(char *s)
{
	int i;

	for (i = 0; s[i] != 0; i++)
		;

	return (i);
}

/**
 *string_compare_n - compares the given strings up to the first n characters
 *@s1: a pointer to the first string.
 *@s2: a pointer to the second string.
 *@n: the number of characters to compare.
 *Return: 0 if successful
 */
size_t string_compare_n(char *s1, char *s2, size_t n)
{
	size_t i, j;

	for (j = 0; s1[j] != '\0' && j < n; j++)
	{
		i = s1[j] - s2[j];

		if (i != 0)
		{
			return (i);
		}
	}

	return (0);
}
