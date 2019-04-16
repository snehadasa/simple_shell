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

void _puts(char *str);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
int _strncmp(const char * s1, const char * s2, size_t n);
char *get_path_value(char **env);
char **handle(char *buffer);
char *_strcat(char *dest, char *src);
int _strlen(char *str);
char *_memset(char *s, char b, unsigned int n);
char *path_check(char *token, char **env);
void env_builtin(char **env);
void built_in(char *tokenize, char **env);
char *readline(void);

#endif /* SHELL_H */
