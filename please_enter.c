#include "shell.h"
/**
 *readline - read the buffer input.
 *
 *Return: buffer.
 */
char *readline(void)
{
	char *buff = NULL;
	ssize_t lineptr = 0;
	size_t size = 0;


	if (isatty(STDIN_FILENO))
		_puts("$ ");
	lineptr = getline(&buff, &size, stdin);
	if (buff[lineptr - 1] == '\n')
		buff[lineptr - 1] = '\0';
	if (lineptr == EOF)
	{
		if (isatty(0))
			_puts("\n");
		exit(0);
	}
	return (buff);
}
