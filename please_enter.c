#include "shell.h"
/**
 *safefree - safe free if the variable is not NULL.
 *@str: string pointer from main function.
 */
void safefree(char *str)
{
	if (str != NULL)
		free(str);
}
/**
 *dfree - safe free if the variable is not NULL.
 *@str: string pointer from main function.
 */
void dfree(char **str)
{
	if (str)
		free(str);

}
/**
 *readtheline - read the buffer input.
 *
 *Return: buffer.
 */
char *readtheline(void)
{
	char *buff = NULL;
	ssize_t lineptr = 0;
	size_t size = 0;


	if (isatty(STDIN_FILENO))
		_puts("$ ");
	lineptr = getline(&buff, &size, stdin);
	if (lineptr == -1)
	{
		free(buff);
		if (isatty(0))
			_puts("\n");
		exit(0);
	}
	if (buff[lineptr - 1] == '\n')
		buff[lineptr - 1] = '\0';
	return (buff);
}
