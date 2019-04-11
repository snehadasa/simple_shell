#include "shell.h"
#include <stdio.h>

int main(int ac, char **av, char **env)
{
	char *command;
	char *result;
	char **directories;
	int i = 0;

	command = "ls";
	result = get_path_value( env);
	printf("%s\n", result);

	directories = split_path(result);

	while (directories[i])
	{
		printf("%s\n", directories[i]);
		i++;
	}
}
