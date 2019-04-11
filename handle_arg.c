#include "shell.h"
/**
 *
 */
char **handle(char *buffer)
{
	char *token;
	int i;
	int word = 1;
	int flag = 0, j = 0;
	char **arr;

	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] != ' ')
			flag = 1;
		if (buffer[i] == ' ')
			flag = 0;
		if (flag == 0 && buffer[i] == ' ' && buffer[i + 1] != ' ')
			word++;
	}
	arr = malloc(sizeof(char*) * (word + 1));
	if (!arr)
		return (NULL);
	token = strtok(buffer, " ");
	while (token)
	{
		arr[j] = token;
		token = strtok(NULL, " ");
		j++;
	}
	arr[j] = NULL;
	return (arr);
}
