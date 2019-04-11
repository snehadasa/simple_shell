#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void _puts(char *str);
int _putchar(char c);
int _strcmp(char *s1, char *s2);

#endif /* SHELL_H */
