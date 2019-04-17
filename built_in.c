#include "shell.h"
/**
 *built_in - create built-in command for shell.
 *@tokenize: the value after tokenizing the buffer in main file.
 *@env: array of string of environment values.
 *@buff: buffer input from main.
 */
void built_in(char **tokenize, char **env, char **buff)
{
	int i;
	(void)buff;

	if (_strcmp(tokenize[0], "exit") == 0)
	{
		for (i = 0; tokenize[i]; i++)
			free(tokenize[i]);
		free(*buff);
		free(tokenize);
		exit(0);
	}
	if (_strcmp(tokenize[0], "env") == 0)
	{
		env_builtin(env);
	}
}
