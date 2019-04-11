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
int main(int ac, char **argv, char **env)
{
	pid_t pid;
	char *buff;
	ssize_t lineptr = 0;
	size_t size = 0;
	int v;
	char *av[] = {"", NULL};
	char *path;
	char **dir;
//	char **tokenize;

	path = get_path_value(env);
	dir = split_path(path);

	while (1)
	{
		_puts("$ ");
		lineptr = getline(&buff, &size, stdin);
		buff[lineptr - 1] = '\0';

		if (lineptr == EOF)
		{
			return (-1);
		}

//		tokenize = str_tokenize(buff);
//		printf("%s\n", tokenize[1]);	
//		printf("%s\n", tokenize[0]);	

		path = get_command(dir, buff);
		pid = fork();
		
		v = _strcmp(buff, "exit");
               	if (!v)
               	{
			exit(98);
		}
		
		if (pid < 0)
		{
			perror("error");
			free(buff);
			return(1);
		}

		if (pid == 0)
		{
			
			if (execve(path, av, NULL) == -1)
			{
				perror("Error:");
				free(buff);
				return(-1);
			}
		}
		else
		{
			wait(NULL);
			continue;
		}
		return (0);
	}
}
