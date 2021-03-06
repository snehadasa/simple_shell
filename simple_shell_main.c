#include "shell.h"
/**
 * env_builtin - enviroment built-in.
 * @env: the array of string of environment values.
 */
void env_builtin(char **env)
{
	int i;

	if (env)
	{
		for (i = 0; env[i]; i++)
		{
			_puts(env[i]);
			_putchar('\n');
		}
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
	char *buff = NULL, *path;
	char **tokenize;
	int status = 0, number = 0;
	pid_t pid;
	(void)ac;

	while (1)
	{
		buff = readtheline();
		tokenize = NULL;
		tokenize = handle(buff);
		if (!tokenize)
			continue;
		built_in(tokenize, env, &buff, number);
		pid = fork();
		if (pid == -1)
		{
			perror("Error:");
			free3(tokenize, buff);
			return (1);
		}
		if (pid == 0)
		{
			path = path_check(tokenize[0], env);
			if (execve(path, tokenize, NULL) == -1)
			{
				perror(tokenize[0]);
				free2(tokenize, buff);
				exit(127);
			}
		}
		else
		{
			free2(tokenize, buff);
			wait(&status);
			number = exit1(status);
		}
	}
	free3(tokenize, buff);
	return (0);
}
/**
 *free2 - free variable for main.
 *@tokenize: the array of strings from main.
 *@buff: buffer input from main function.
 */
void free2(char **tokenize, char *buff)
{
	int i;

	for (i = 0; tokenize[i]; i++)
		free(tokenize[i]);
	dfree(tokenize);
	safefree(buff);
}
/**
 *free3 - free variable for main.
 *@tokenize: the array of strings from main.
 *@buff: buffer input from main function.
 */
void free3(char **tokenize, char *buff)
{
	dfree(tokenize);
	safefree(buff);
}
/**
 *exit1 - return exit form child process
 *@status:  exit value.
 *
 *Return: return exit value.
 */
int exit1(int status)
{
	int number;

	if (WIFEXITED(status))
		number = WEXITSTATUS(status);
	return (number);
}
