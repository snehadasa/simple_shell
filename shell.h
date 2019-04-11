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
char **handle(char *buffer);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_getenv(const char *name);

#endif /* SHELL_H */
