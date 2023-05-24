#include <unistd.h>
#include "shell.h"
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
* get_line - gets the next line of input from standard input
* Return: The string entered by the user.
*/

char *get_line(void)
{
static char buffer[BUFFER_SIZE];
static int buf_pos = 0;
static int buf_size = 0;
char* input_str = NULL;
char current_char;
int input_len = 0;

while (1)
{
if (buf_pos >= buf_size)
{
buf_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
buf_pos = 0;
if (buf_size == 0)
{
free(input_str);
/* Free allocated memory before returning */
return (NULL);
}
else if (buf_size < 0)
{
perror("read");
free(input_str);
/* Free allocated memory before returning */
return (NULL);
}
}

current_char = buffer[buf_pos++];

if (current_char == '\n')
{
char* temp = (char*)realloc(input_str, (input_len + 1) * sizeof(char));
if (temp == NULL)
{
perror("realloc");
free(input_str); // Free allocated memory before returning
return (NULL);
}
input_str = temp;
input_str[input_len] = '\0';
return (input_str);
}
else
{
char* temp = (char*)realloc(input_str, (input_len + 1) * sizeof(char));
if (temp == NULL)
{
perror("realloc");
free(input_str); // Free allocated memory before returning
return (NULL);
}
input_str = temp;
input_str[input_len++] = current_char;
}
}
}
