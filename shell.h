#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <limits.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

/* string handlers */
int _strlen(const char *str);
char *_strcpy(char *descpy, char *srcpy);
char *_strcat(char *dest, char *src);
char *_strdup(const char *str);
int _strncmp(char *str1, char *str2);
char *start_haystack(const char *haystack, const char *needle);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strchr(char *str, char cr);
int _putchar(char c);
unsigned int _strspn(char *str, char *subs);

/* Sigint.c */
void sigstp_handler(int sig_num);
void handle_sigint(int sig_num);
void handle_sigquit(int sig_num);

/* Free.c */
void free_path(void);
void free_error(char **arp, char *arch);
void free_token(char **mem);

/* Free_last.c */
char *get_input(void);
void free_input(void);

/* Prompt_user.c */
void prompt(void);

/* Tokenizer.c */
char **split_words(const char *str, char *del);
char **split_input(char *str);

/* Getenv.c */
char *get_path(void);

/* Biultins_shell_help.c */
void shell_help(void);

/* Built-in exit.c */
void _myexit(char **args);

/* execute.c */
int execute_cmd(char **cmdarg);

/* built-in_exit.c */
int shell_exit(info_t *info);

/* Builtin_shell_clear.c */
int builtins(char **cmd);

/* Error.c */
void print_puts(const char *str);
void print_error(const char *estr);

/* Env built-in.c */
int _unsetenv(char **args);
int _setenv(char **args);
char _getenv(const char *name);
int current_env(info_t *info);

/* Check_builtin.c */
int check_for_builtin(info_t *info, char **args);

/* Builtin_shell_cd.c */
void builtin_shell(char **args);

/* _getline.c */
char *get_line(void);

/* atoi.c */
int _atoi(const char *r);
void *_realloc(void *ptr, size_t old_size, size_t new_size);
void *_memset(void *s, int c, size_t n);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);


#endif
