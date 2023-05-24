#include "shell.h"
/**
* find_path - Looks for a command in each directory specified in the PATH
* @cmd: pointer to command string to look for.
* @path: path string
* Return: pointer to string containing the full path (success) if it is found,
*/
char *find_path(char *cmd, char *path)
{
struct stat st;
int s, k;
char buf[PATH_MAX_LENGTH];
char *e;
char **dir;
path = get_path();
if (!path)
return (NULL);
dir = tokenize(path, PATH_SEPARATOR);
if (!dir)
return (NULL);
for (k = 0; dir[k]; k++)
{
_memset(buf, 0, PATH_MAX_LENGTH);
_strcpy(buf, dir[k]);
_strcat(buf, "/");
_strcat(buf, command);
s = stat(buf, &st);
if (s == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
{
free_tokens(dir);
e = malloc(sizeof(char) * (strlen(buf) + 1));
if (!e)
return (NULL);
_strcpy(e, buf);
return (e);
}
}
if (s == -1)
free_tokens(dir);
return (NULL);
}
