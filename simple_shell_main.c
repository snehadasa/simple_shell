#include "shell.h"

void env_builtin()
{
	int i;

	for (i = 0; __environ[i]; i++)
	{
		_puts(__environ[i]);
		_puts("\n");
	}
}


/** 
 * free_var - Frees used variables.
 * 
 * @dir - directories
 * @tokenize - toknize
 * @buff - buffer
 * @path - Path
 */
void free_var(char **dir, char **tokenize, char *buff, char *path)
{
	free(dir);
	free(tokenize);
	free(buff);
	free(path);
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
	char *trimmed_buff;
	ssize_t lineptr = 0;
	size_t size = 0;
	int v;
	char *path;
	char **dir;
	char **tokenize;

	path = get_path_value(env);
	dir = split_path(path);
	while (1)
	{
		_puts("$ ");
		lineptr = getline(&buff, &size, stdin);
		buff[lineptr - 1] = '\0';
		if (lineptr == EOF)
			return (1);
		trimmed_buff = trim_spaces(buff);
		tokenize = handle(trimmed_buff);
		
		if (!tokenize)
		{
			free(buff);
			continue;
		}
		v = _strcmp(trimmed_buff, "exit");
		if (!v)
		{
			free(dir);
			free(buff);
			free(tokenize);
			exit(98);
		}
		v = _strcmp(trimmed_buff, "env");
		if (!v)
		{
			env_builtin();
			free(buff);
			continue;
		}
		
		path = get_command(dir, tokenize[0]);
		pid = fork();
		if (pid == -1)
		{
			perror("error");
			free_var(dir, tokenize, buff, path);
			return(1);
		}
		if (pid == 0)
		{
			if (execve(path, tokenize, NULL) == -1)
			{
				perror("Error:");
				free_var(dir, tokenize, buff, path);
				exit(0);;
			}
		}
		else
			wait(NULL);
	}
	free_var(dir, tokenize, buff, path);
	return (0);
}
