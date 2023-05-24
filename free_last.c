#include "shell.h"

/**
* get_input - Read a line of input from the user.
* Return: input read.
*/
char *get_input(void)
{
char *i = NULL;
char *last_input;
size_t iz = 0;
ssize_t nread;
do {
/* Print the shell prompt */
prompt();
/* Get a line of input from the user */
nread = getline(&i, &iz, stdin);
/* Check for EOF/error */
if (nread == -1)
{
free(i);
_puts("\n");
return (NULL);
}
/* Remove trailing newline character */
i[nread - 1] = '\0';
} while (i[0] == '\0' || isspace((unsigned char)i[0]));
/* Update last_input to point to the new input */
last_input = i;
return (i);
}

/**
 * free_input - Frees input 
 *  Return: nothing
 */
void free_input(void)
{
	free(last_input);
	last_input = NULL;
}
