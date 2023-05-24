#include "shell.h"

/**
* print_puts - prints an input string
* @str: the string to be printed
* Return: void
*/

void print_puts(const char *str)
{
if (str == NULL)
return;
int s = 0;
while (str[s] != '\0')
{
_eputchar(str[s]);
s++;
}
}

/**
* print_error - Prints an error message to the std stream
* @estr: string containing specified error type
* Return: empty
*/

void print_error(const char *estr)
{
size_t len = _strlen(err);
ssize_t num_written = write(STDERR_FILENO, estr, len);
if (num_written == -1)
{
perror("write");
}
}
