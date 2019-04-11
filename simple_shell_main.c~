#include "shell.h"

void env_builtin()
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		print_string(environ[i]);
		print_string("\n");
	}
}

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main()
{
	pid_t pid;
	char *buff;
	ssize_t lineptr = 0;
	size_t size = 0;
	int v;
	char *av[] = {"", NULL};
	char **tokenize;

	while (1)
	{
		print_string(" $");
		lineptr = getline(&buff, &size, stdin);
		buff[lineptr - 1] = '\0';

		if (lineptr == EOF)
		{
			return (-1);
		}

		tokenize = str_tokenize(buff);
		printf("%s\n", tokenize[1]);	
		get_command(tokenize[0], environ);
		printf("%s\n", tokenize[0]);	

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
			if (execve(tokenize[0], av, NULL) == -1)
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
