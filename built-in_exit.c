#include "shell.h"

/**
* shell_exit - exits the shell
* @args: Struct arguments.
* Return: exits with a given exit status
*/
int shell_exit(info_t *args)
{
int stat = 0;
if (args->argv[1])
/* If there is an exit argument */
{
stat = _erratoi(args->argv[1]);
if (stat == -1)
{
args->status = 2;
print_error(args, "Illegal number: ");
_eputs(args->argv[1]);
_eputchar('\n');
return (1);
}
args->err_num = stat;
return (-2);
}
args->err_num = -1;
return (-2);
}
