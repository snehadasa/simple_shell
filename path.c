#include "shell.h"
/**
 *get_path_value - get the value of environment.
 *@env: a array of string of environment variable
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
 *path_check -tokenize & concatenate path and check if the buffer exists.
 *@token: the string after tokenize the buffer in main file.
 *@env: a array of string of environment variable.
 *
 *Return: the buffer after concatenate.
 */

char *path_check(char *token, char **env)
{
	static char buffer[1024] = {0};
	int i;
	char *path;
	char *tok;
	struct stat st;

	path = get_path_value(env);
	if (!path)
		path = "";
	for (i = 0; path[i]; i++)
	{
		if ((path[0] == ':') || ((path[i] == ':') && (path[i + 1] == ':')))
		{
			if (_strncmp(&path[i + 2], "/bin:", 5) == 0)
				if (stat(token, &st) == 0)
					return (token);
		}
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
