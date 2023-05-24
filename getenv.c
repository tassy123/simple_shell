#include "shell.h"

/**
 * get_path - Returns the string of the PATH environ var.
 *
 * Return: Always 0 (success)
 */
char *get_path(void)
{
	return (_getenv("PATH"));
}

