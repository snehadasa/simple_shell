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
	char *temp;

	for (i = 0; buffer[i] && buffer[i + 1]; i++)
	{
		if (buffer[i] != ' ')
			flag = 1;
		if (buffer[i] == ' ')
			flag = 0;
		printf ("i %d" , i);
		if (flag == 0 && buffer[i] == ' ' && buffer[i + 1] != ' ')
			word++;
	}
	printf("count is %d\n", word);
	arr = malloc(sizeof(char*) * (word + 1));
	if (!arr)
		return (NULL);

	temp = buffer;
	token = strtok(temp, " ");
	if (!token)
		return (NULL);
	while (token)
	{
		arr[j] = token;
		token = strtok(NULL, " ");
		j++;
	}
	arr[j] = NULL;
	return (arr);
}
