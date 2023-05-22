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
