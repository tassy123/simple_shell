#include "shell.h"
/**
* _strlen - return the length of a string
* @str: string passed
*
* Return: integer length of string passed
*/
int _strlen(const char *str)
{
	int c = 0;

	while (*str != '\0')
	{
		c++;
		str++;
	}
	return (c);
}

/**
 * _strcpy - copy a string to another
 *
 * @descpy: destination copy
 * @srcpy: Source for copy
 *
 * Return: pointer to dest
 */
char *_strcpy(char *descpy, char *srcpy)
{
	int d = 0;

	for (d = 0; srcpy[d] != '\0'; d++)
		descpy[d] = srcpy[d];

	descpy[d] = '\0';

	return (descpy);
}

/**
 * _strcat - concatenate two strings
 * @dest: string conc
 * @src: the source of the string
 *
 * Return: a string conc
 */
char *_strcat(char *dest, char *src)
{
	char *d = dest;

	while (*dest)
		dest++;
	while (*src)
	*dest++ = *src++;
	*dest = *src;
	return (d);
}
/**
* _strdup - duplicates a string
* @str: string to be duplicated
* Return: duplicated string
*/
char *_strdup(const char *str)
{
char *tip;
int o, n;
if (str == NULL)
return (NULL);
n = _strlen(str);
tip = malloc(sizeof(char) * (n + 1));
if (!tip)
return (NULL);
for (o = 0; str[o] != '\0'; o++)
tip[o] = str[o];
tip[o] = '\0';
return (tip);
}

/**
* _strcmp - Compare two strings
* @str1: first string 1
* @s2: second string 2
* Return: Integer
 */
int _strcmp(char *str1, char *str2)
{
int w;
for (w = 0; str1[w] != '\0'; w++)
{
if (str1[w] != str2[w])
return (str1[w] - str2[w]);
}
return (0);
}
