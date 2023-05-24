#include "shell.h"
/**
* sigstp_handler - Signal handler for SIGTSTP (Ctrl+Z)
* @sig_num: the signal number
* Return: void
*/
void sigstp_handler(int sig_num)
{
(void) sig_num;
_puts("\n");
prompt();
}
/**
* sigint_handler - Signal handler for SIGINT (Ctrl+C)
* @sig_num: the signal number
* Return: void
*/
void sigint_handler(int sig_num)
{
(void) sig_num;
_putchar('\n');
prompt();
}
/**
* sigquit_handler - Signal handler for SIGQUIT (Ctrl+\)
* @sig_num: the signal number
* Return: empty
*/
void sigquit_handler(int sig_num)
{
(void) sig_num;
_puterror("Quit (core dumped)\n");
exit(EXIT_SUCCESS);
}
