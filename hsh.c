#include "shell.h"

/**
* hsh - main shell loop
* @info: the parameter & return info struct
* @argv: the argument vector
* Return: 0 on success or 1 on error
*/
int hsh(info_t *info, char **argv)
{
ssize_t s = 0;
int ret = 0;

while (s != -1 && ret != -2)
{
clear_info(info);
if (interactive(info))
_puts("$ ");
_eputchar(BUF_FLUSH);
s = get_input(info);
if (s != -1)
{
set_info(info, argv);
ret = find_builtin(info);
if (ret == -1)
find_cmd(info);
}
else if (interactive(info))
_putchar('\n');
free_info(info, 0);
}
write_history(info);
free_info(info, 1);
if (!interactive(info) && info->status)
exit(info->status);
if (ret == -2)
{
if (info->err_num == -1)
exit(info->status);
exit(info->err_num);
}
return (ret);
}
