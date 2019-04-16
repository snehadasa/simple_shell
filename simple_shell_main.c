#include "shell.h"
/**
 * env_builtin - enviroment built-in.
 * @env: array of string of environment values.
 */
void env_builtin(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		_puts(env[i]);
		_puts("\n");
	}
}
/**
 * main - entry point to run simple shell.
 * @ac: argument count.
 * @av: argument variable.
 * @env: array of string of environment values.
 *
 * Return: Always 0.
 */
int main(int ac, __attribute__((unused))char **av, char **env)
{
	(void)ac;
	pid_t pid;
	char *buff = NULL;
	char *path;
	char **tokenize;

	while (1)
	{
		buff = readline();
		tokenize = handle(buff);
		if (!tokenize)
			continue;
		built_in(tokenize[0], env);
		pid = fork();
		if (pid == -1)
		{
			perror("error");
			free(buff);
			return (1);
		}
		if (pid == 0)
		{
			path = path_check(tokenize[0], env);
			if (execve(path, tokenize, NULL) == -1)
			{
				perror("Error:");
				free(tokenize);
				free(buff);
				exit(0);
			}
		}
		else
			wait(NULL);
	}
	free(path);
	free(tokenize);
	free(buff);
	return (0);
}
