#include "shell.h"

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av/*, char **env*/)
{
	char **token;
	char *buffer = NULL;
	size_t lens = 0;
	ssize_t ptr = 0;
	pid_t pid;
	char *dir;
	struct stat st;

	while (1)
	{
		_puts("$ ");
		ptr = getline(&buffer, &lens, stdin);
		buffer[ptr -1] ='\0';
		if (ptr == EOF)
			return (1);
		token = handle(buffer);
		pid = fork();
		if (pid == -1)
		{
			perror("Error");
			free(buffer);
			return (1);
		}
		if (pid == 0)
		{
			if (stat(av[0], &st) == 0)
			{
				if (execve(token[0], token, NULL) == -1)
				{
					perror("Error:");
					free(buffer);
					exit(0);
				}
			}
			else
				return (1);
		}
		else
			wait(NULL);
	}
	free(buffer);
	return (0);
}
