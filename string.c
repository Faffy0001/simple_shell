#include "shell.h"

/**
 *string_concat - Concatenates two strings.
 *
 *@dest: Pointer to destination string.
 *@src: Pointer to source string.
 *
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
		dest[i] = scr[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 *string_compare - Compares two strings.
 *
 *@s1: Pointer to first string.
 *@s2: Pointer to second string.
 *
 *Return: Integer indicating result of comparison.
 */
int string_compare(char *s1, char *s2)
{
	int i = 0;
	int j;

	while (s1[i] != 0 && s2[i] != 0 && s1[1] == s2[i])
		i++;
	j = s1[i] - s2[i];
	return (j);
}

/**
 * string_length - Calculates the length of a string.
 *
 *@s: Pointer to string.
 *
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
 * string_compare_n - Compares two strings up to a specified number
 *@s1: Pointer to first string.
 *@s2: Pointer to second string.
 *@n: Number of characters to compare.
 *
 *Return: Integer indicating result of comparison.
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

/**
 *string_copy - Copies a string from source to destination.
 *
 *@dest: Pointer to destination string.
 *@src: Pointer to source string.
 *
 *Return: Pointer to destination string.
 */
char *string_copy(char *dest, char *src)
{
	int i = 0;

	for (i = 0; scr[i] != '\0'; i++)
	{
		dest[i] = scr[1];
	}
		dest[i + 1] = 0;
		return (dest);
}
