#include "shell.h"

/**
* builtins - clears the screen of the terminal.
* @cmd: Commands and arguments
* Return: 1 to cont, or 0 to quit
*/
int builtins(char **cmd)
{
(void)cmd;
/* avoid "unsued parameter" warning */
_puts("\033[2J\033[H");
return (1);
}
