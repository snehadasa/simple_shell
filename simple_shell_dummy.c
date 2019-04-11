#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t pid;
	char *argv[] = {"", NULL};
	char *buff;
	ssize_t lineptr = 0;
	size_t size = 0;
	int v;

	while (1)
	{
		printf("$ ");
		lineptr = getline(&buff, &size, stdin);
		buff[lineptr - 1] = '\0';

		if (lineptr == EOF)
		{
			return (-1);
		}

		pid = fork();
		
		if (pid < 0)
		{
			perror("error");
			free(buff);
			return(1);
		}

		if (pid == 0)
		{
			v = strcmp(buff, "exit");
                	if (!v)
                	{
				exit(98);
			}

			if (execve(buff, argv, NULL) == -1)
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
