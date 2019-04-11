#include "shell.h"
/*
 *
 */
char *_getenv(const char *name)
{
	extern char **environ;
	int i, j;
	char *token;
	char *result;

	for (i = 0; environ[i]; i++)
	{
		token = strtok(environ[i], "=");
		if (strcmp(token, name) == 0)
			result = strtok(NULL, "=");
	}
	return (result);
}
#include "shell.h"
/*
 *
 *
 */
char *cpath(char **buffer)
{
	char *str;
	char *token;
	char *array;
	int word = 1;
	char *name = "PATH";
	struct stat st;

	str = _getenv(name);
	array = malloc(sizeof(char) * (_strlen(str) + 1));
	token = strtok(str, ":");
	while (token)
	{
		_strcpy(array, token);
		token = strtok(token, ":");
		if (!token)
			break;
		 _strcat(array, "/");
		 _strcat(array, buffer[0]);
		 if (stat(array, &st) == 0)
		 {
			 if (execve(array, buffer, NULL) == -1)
			 {
				 perror("Error:");
				 free(array);
				 exit(0);
			 }
		 }
	}
	return (NULL);
}
