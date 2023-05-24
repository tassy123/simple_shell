#include "shell.h"

/**
* _setenv - Initialize a new environment variable
* @args: Struct containing potential arguments
* Return: Empty
*/
int _setenv(char **args)
{
char *pty, *gkj;
if (args[1] == NULL || args[2] == NULL)
{
_puterror("Usage: setenv VARIABLE VALUE\n");
return (-1);
}
pty = args[1];
gkj = args[2];

if (setenv(name, value, 1) != 0)
{
_puterror("setenv");
return (-1);
}
return (0);
}

/**
* _unsetenv - Remove an environment variable
* @args: Struct containing potential arguments
* Return: Empty
*/
int _unsetenv(char **args)
{
if (args[1] == NULL)
{
_puterror("Usage: unsetenv VARIABLE\n");
return (-1);
}

if (unsetenv(args[1]) != 0)
{
_puterror("unsetenv");
return (-1);
}

return (0);
}

/**
* _getenv - get an environment variable
* @name: name of environment variable to get
* Return: Value of name on success
* or NULL if it doesn't exist
*/
char _getenv(const char *name)
{
char **n;
char *x, *o, *v;
int s;
s = _strlen((char *) name);
for (n = environ; *n; ++n)
{
x = _strdup(*n);
o = strtok(x, "=");
if (o == NULL)
{
free(x);
return (NULL);
}
if (_strlen(o) != s)
{
free(x);
continue;
}
if (_strcmp((char *) name, x) == 0)
{
o = strtok(NULL, "=");
v = _strdup(o);
free(x);
return (v);
}
free(x);
}
return (NULL);
}

/**
* current_env - prints the current environment
* @info: argument
* Return: Always 0
*/
int current_env(info_t *info)
{
print_list_str(info->env);
return (0);
}
