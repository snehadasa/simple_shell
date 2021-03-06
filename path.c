#include "shell.h"
/**
 *get_path_value - get the value of environment.
 *@env: an array of string of environment variable
 *
 *Return: token(success) or NULL(fail).
 */
char *get_path_value(char **env)
{
	char *token;
	int i = 0;
	char *temp;

	while (env[i])
	{
		temp = env[i];
		token = strtok(temp, "=");
		if (_strcmp(token, "PATH") == 0)
		{
			token = strtok(NULL, "=");
			return (token);
		}
		i++;
	}
	return (NULL);
}
/**
 *_strstr -  a function that locates a substring..
 *@haystack: string character value.
 *@needle: substring character value.
 *
 * Return: Returns a pointer to substring, or NULL if it fails.
 */
char *_strstr(char *haystack, char *needle)
{
	int i;
	int  j = 0;

	if (needle[j] == '\0')
		return (haystack);
	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (haystack[i] == needle[0])
		{
			for (j = 0; needle[j] != '\0' && haystack[i + j]
				     && needle[j] == haystack[i + j]; j++)
				;
			if (needle[j] == 0)
				return (haystack + i);
		}
	}
	return (0);
}
/**
 *path_check -tokenize & concatenate path and check if the buffer exists.
 *@token: the string after tokenize the buffer in main file.
 *@env: a array of string of environment variable.
 *
 *Return: the buffer after concatenate.
 */
char *path_check(char *token, char **env)
{
	static char buffer[1024] = {0};
	char *path;
	char *tok;
	struct stat st;
	char *a, *b;

	path = get_path_value(env);
	if (!path)
		path = "";
	a = _strstr(path, "::");
	b = _strstr(path, ":/bin");
	if (path[0] == ':' || (a && (a < b)))
	{
		if (stat(token, &st) == 0)
			return (token);
	}

	tok = strtok(path, ":");
	while (tok)
	{
		_strcat(buffer, tok);
		_strcat(buffer, "/");
		_strcat(buffer, token);
		if (stat(buffer, &st) == 0)
			return (buffer);
		tok = strtok(NULL, ":");
		_memset(buffer, 0, 1024);
	}
	return (token);
}
