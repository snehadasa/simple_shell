#include "shell.h"
/**
 *built_in - create built-in command for shell.
 *@tokenize: the value after tokenizing the buffer in main file.
 *@env: the array of string of environment values.
 *@buff: buffer input from main.
 *@status: exit value.
 */
void built_in(char **tokenize, char **env, char **buff, int status)
{
	int i;
	(void)buff;

	if (_strcmp(tokenize[0], "exit") == 0)
	{
		for (i = 0; tokenize[i]; i++)
			free(tokenize[i]);
		free(*buff);
		free(tokenize);
		exit(status);
	}
	if (_strcmp(tokenize[0], "env") == 0)
	{
		if (!tokenize[1])
			env_builtin(env);
	}
}
