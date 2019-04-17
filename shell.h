#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

extern char **environ;
/* create puts and putchar */
void _puts(char *str);
int _putchar(char c);

/* handle_arg.c */
char *_strdup(char *str);
char **handle(char *buffer);

/* path.c*/
char *get_path_value(char **env);
char *path_check(char *token, char **env);
char *_strstr(char *haystack, char *needle);

/*strhelp.c*/
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcat(char *dest, char *src);
int _strlen(char *str);
char *_memset(char *s, char b, unsigned int n);

/*built_in.c*/
void built_in(char **tokenize, char **env, char **buff);

/*please_enter.c*/
char *readtheline(void);
void safefree(char *str);
void dfree(char **str);

/*simple_shell_main.c*/
void env_builtin(char **env);
void free2(char **tokenize, char *buff);
void free3(char **tokenize, char *buff);

#endif /* SHELL_H */
