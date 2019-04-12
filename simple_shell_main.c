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
		tokenize = handle(buff);
<<<<<<< HEAD
		if(!tokenize)
			continue;

		printf("-------------------------token %s------------------\n", tokenize[0]);
		pid = fork();
		
		v = _strcmp(tokenize[0], "exit");
               	if (!v)
               	{
			printf("Exit %s\n", buff);
			free(dir);
			free(path);
			free(buff);
			exit(98);
		}

		v = _strcmp(tokenize[0], "env");
		if (!v)
		{
			env_builtin();
			continue;
		}
		if(tokenize[0][0] == '\n')
		{
			continue;
		}

		path = get_command(dir, tokenize[0]);
		if (path == NULL)
		{
			_puts("Command not found");
			continue;
		}
		
		if (pid < 0)
=======
		if (!tokenize)
			continue;
		path = get_command(dir, tokenize[0]);
		v = _strcmp(buff, "exit");
		if (!v)
			exit(98);
		v = _strcmp(buff, "env");
		if (!v)
		env_builtin();
		pid = fork();
		if (pid == -1)
>>>>>>> van
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
				free(tokenize);
				free(buff);
				exit(0);;
			}
		}
		else
			wait(NULL);
<<<<<<< HEAD
		}
		
		free(buff);
		free(path);
		free(tokenize);
=======
>>>>>>> van
	}
	free(path);
	free(tokenize);
	free(buff);
	return (0);
}
