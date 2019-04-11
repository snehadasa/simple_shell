#include "shell.h"
#include <stdio.h>

int main(int ac, char **av, char **env)
{
	char *command;
	char *result;

	command = "ls";
	result = get_command(command, env);
	printf("%s\n", result);
}
