#include "shell.h"

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
 *
 * Return: Always 0.
 */
int main(__attribute__((unused)) int ac, __attribute__((unused))char **av, char **env)
{
	pid_t pid;
	char *buff;
	ssize_t lineptr = 0;
	size_t size = 0;
	int v;
	char *path;
	/*char **dir;*/
	char **tokenize;

	/*path = get_path_value(env);
	  dir = split_path(path); */
	while (1)
	{
		if (isatty(STDIN_FILENO))
			_puts("$ ");
		lineptr = getline(&buff, &size, stdin);
		buff[lineptr - 1] = '\0';
		if (lineptr == EOF)
		{
			if (isatty(0))
				_puts("\n");
			exit(0);
		}
		tokenize = handle(buff);
		if (!tokenize)
			continue;
/*		path = get_command(dir, tokenize[0]);*/
		v = _strcmp(buff, "exit");
		if (!v)
			exit(98);
		v = _strcmp(buff, "env");
		if (!v)
			env_builtin(env);
		pid = fork();
		if (pid == -1)
		{
			perror("error");
			free(buff);
			return(1);
		}
		if (pid == 0)
		{
			path = path_check(tokenize[0], env);
			if (execve(path, tokenize, NULL) == -1)
			{
				perror("Error:");
				free(tokenize);
				free(buff);
				exit(0);;
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
