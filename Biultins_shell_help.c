 #include "shell.h"

/**
 * shell_help - display help info for builtin commands
 */
void shell_help(void)
{
         _puts("\nShell Version 1.0.0\n\n");
         _puts("Usage: ./hsh\n\n");
          _puts("Shell built-in commands:\n\n");
          _puts("help\t\tshow this help information\n\n");
          _puts("exit\t\tquit the shell\n\n");
           _puts("unsetenv\tUnset an environment variable\n\n");
           _puts("setenv\t\tSet an environment variable\n\n");
            _puts("env\t\tprint the environment variables\n\n");
            _puts("cd [dir]\tChange the current working directory\n\n");
_puts("strchr\t\tstring chaaracter in a function\n\n");
}
