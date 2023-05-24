#include "shell.h"

/**
* main - implements a simple shell
* Return: EXIT_SUCCESS.
*/

int main(void)

{
int lev;
char **args;
char *input;
/*  Register signal handlers  */
signal(SIGINT, sigint_handler);
signal(SIGQUIT, sigquit_handler);
signal(SIGSTP, sigstp_handler);

do {
input = get_input();
if (!input || !*input)
{
/* EOF detected, exit the loop */
break;
}

args = tokenize_input(input);
if (!args || !*args)
{
free(input);
free_tokens(args);
continue;
}
lev = execute(args);
free(input);
free_tokens(args);

/*  Set lev to 1 to continue the loop  */
lev = 1;
} while (lev);

return (EXIT_SUCCESS);
}
