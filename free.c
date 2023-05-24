#include "shell.h"
/**
 * free_path - Frees the variable containing the PATH environ
 *variable value
 * Return: empty
 */

void free_path(void)
{
if (environ != NULL)
{
size_t b = 0;
char* path_var = getenv("PATH");
if (path_var != NULL)
{
char** env_ptr = environ;
while (*env_ptr != NULL)
{
if (*env_ptr == path_var)
{
free(*env_ptr);
*env_ptr = NULL;
break;
}
env_ptr++;
}
}
}
}

/**
 * free_error - frees alloc the pointers if system error
 * @arp: array of pointers
 * @arch: array of characters
 * Return: void.
 */
void free_error(char **arp, char *arch)
{
int a;
for (a = 0; arp[a]; a++)
free(arp[a]);
free(arp);
free(arch);
exit(EXIT_FAILURE);
}
/**
* free_token - frees memory allocated
* @mem: pointer to allocated memory
* Return: void
*/
void free_token(char **mem)
{
int z;
for (z = 0; mem[z]; z++)
free((mem[z]));
free(mem);
}
