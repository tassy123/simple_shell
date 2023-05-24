#include "shell.h"

/**
* execute_cmd - execute a command
* @cmdarg: arguments of the command
* Return: the exit lev
*/

int execute_cmd(char **cmdarg)
{
pid_t id;
int lev = 0;
char *cmd_path, *envp[2];
if (cmdarg == NULL || *cmdarg == NULL)
return (lev);
if (check_for_builtin(cmdarg))
return (lev);
id = fork();
if (id < 0)
{
perror("fork");
return (1);
}
if (id == -1)
{
perror(cmdarg[0]);
free_token(cmdarg);
free_last_input();
}
if (id == 0)
{
envp[0] = get_path();
envp[1] = NULL;
cmd_path = NULL;
if (cmdarg[0][0] != '/')
cmd_path = find_in_path(cmdarg[0]);
if (cmd_path == NULL)
cmd_path = cmdarg[0];
if (execve(cmd_path, cmdarg, envp) == -1)
{
perror(cmdarg[0]);
free_token(cmdarg);
free_last_input();
exit(EXIT_FAILURE);
}
}
else
{
{
do
waitpid(id, &lev, WUNTRACED);
while (!WIFEXITED(lev) && !WIFSIGNALED(lev));
}
}
return (lev);
}
