#include "shell.h"

/**
 * prompt - Print shell prompt
 * Return: nothing
 */
void prompt(void)
{
	_puts(PROMPT);
	fflush(stdout);
}
