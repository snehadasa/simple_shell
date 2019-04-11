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
 * main - fork example
 *
 * Return: Always 0.
 */
int main(__attribute__((unused)) int ac, __attribute__((unused)) char **argv, char **env)
{
	pid_t pid;
	char *buff;
	ssize_t lineptr = 0;
	size_t size = 0;
	int v;
	char *path;
	char **dir;
	char **tokenize;

	path = get_path_value(env);
	printf("path %s\n", path);
	dir = split_path(path);
	printf("dir %s\n", dir[0]);

	while (1)
	{
		_puts("$ ");
		lineptr = getline(&buff, &size, stdin);
		buff[lineptr - 1] = '\0';

		if (lineptr == EOF)
		{
			return (1);
		}


		tokenize = handle(buff);

		path = get_command(dir, tokenize[0]);
		printf("-------------------------token %s------------------\n", tokenize[0]);
		printf("%s\n", path);
		pid = fork();
		
		v = _strcmp(buff, "exit");
               	if (!v)
               	{
			exit(98);
		}

		v = _strcmp(buff, "env");
		if (!v)
		{
			env_builtin();
		}
		
		if (pid < 0)
		{
			perror("error");
			free(buff);
			return(1);
		}

		if (pid == 0)
		{
			
			if (execve(path, tokenize, NULL) == -1)
			{
				perror("Error:");
				free(buff);
				exit(0);;
			}
		}
		else
		{
			wait(NULL);
		}
		
		free(buff);
	}
	return (0);
}
