#include "shell.h"

/**
* builtin_shell - changes the working directory of the shell
* @args: array of arguments
*/
void builtin_shell(char **args)
{
char *dir = args[1];
int o;
/* If no argument is provided, change to HOME directory */
if (dir == NULL)
{
dir = _getenv("HOME");
if (dir == NULL)
{
_puts("cd: No HOME directory found\n");
return;
}
}
o = chdir(dir);
if (o == -1)
{
perror("cd");
}
}
