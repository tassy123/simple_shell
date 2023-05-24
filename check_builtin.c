#include "shell.h"

/**
* check_for_builtin - checks if the command is a builtin
* @info: General information about the shell
* @args: the arguments array
* Return: 1 if command is a builtin, 0 otherwise
*/
int check_for_builtin(general_t *info, char **args)
{
int new, size;
builtin_t builtins[] = {
{"exit", bin_exit},
{"env", bin_env}
};
size = sizeof(builtins) / sizeof(builtins[0]);
for (new = 0; new < size; new++)
{
if (_strcmp(info->command, builtins[new].command) == 0)
{
builtins[new].func(info, args);
return (_TRUE);
}
}
return (_FALSE);
}
