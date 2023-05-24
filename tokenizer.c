#include "shell.h"
#include <stdlib.h>
/**
 * split_words - Splits a string into words based on delimiters.
 * @str: The input string.
 * @del: The delimiter string.
 *
 * Return: An array of pointer to the strings, or NULL on failure.
 */
char **split_words(const char *str, char *del)
{
int u, x, e, m, ret = 0;
char **result;
if (str == NULL || str[0] == '\0')
return (NULL);
if (!del)
del = " ";
for (u = 0; str[u] != '\0'; u++)
{
if (!is_delim(str[u], del) && (is_delim(str[u + 1], del) || !str[u + 1]))
ret++;
}
if (ret == 0)
return (NULL);
result = malloc((ret + 1) * sizeof(char *));
if (!result)
return (NULL);
for (u = 0, x = 0; x < ret; x++)
{
while (is_delim(str[u], del))
u++;
e = 0;
while (!is_delim(str[u + e], del) && str[u + e])
e++;
result[x] = malloc((e + 1) * sizeof(char));
if (!result[x])
{
for (e = 0; e < j; e++)
free(result[e]);
free(result);
return (NULL);
}
for (m = 0; m < e; m++)
result[x][m] = str[u++];
result[x][m] = '\0';
}
result[x] = NULL;
return (result);
}

/**
* split_input - splits a user input string
* @str: the user input string
* Return: an array of pointers to the tokens, or NULL if an error occurs
*/
char **split_input(char *str)
{
char **result = NULL;
char *x = NULL;
x = _strdup(str);
if (x == NULL)
{
_puts("Memory allocation error\n");
exit(EXIT_FAILURE);
}
result = result(x, " \t\r\n\a");
free(x);
return (result);
}
