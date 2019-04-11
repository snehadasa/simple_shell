#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

void _puts(char *str);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
char *get_path_value(char **env);
char **split_path(char *path);

#endif /* SHELL_H */
