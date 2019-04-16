#include "shell.h"
/**
 *built_in - create built-in command for shell.
 *@tokenize: the value after tokenizing the buffer in main file.
 *@env: array of string of environment values.
 */
void built_in(char *tokenize, char **env)
{
	if (_strcmp(tokenize, "exit") == 0)
		exit(0);
	if (_strcmp(tokenize, "env") == 0)
		env_builtin(env);
}
