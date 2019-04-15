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
char *get_path_value(char **env);
char **split_path(char *path);
char *get_command(char **directories, char *command);
char *get_command_path(char **env, char *command);
char **handle(char *buffer);
char *_strcat(char *dest, char *src);
int _strlen(char *str);
char *_memset(char *s, char b, unsigned int n);
char *path_check(char *token, char **env);

#endif /* SHELL_H */
