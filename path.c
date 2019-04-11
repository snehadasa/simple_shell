#include "shell.h"

int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return i;
}

char *append_command(char *dir, char *command)
{
	char *result;
	int i = 0, j = 0, k = 0;

	result = malloc(_strlen(dir) + _strlen(command) + 2);
	while (dir[i])
	{
		result[j] = dir[i];
		i++;
		j++;
	}

	result[j] = '/';
	j++;

	while(command[k])
	{
		result[j] = command[k];
		j++;
		k++;
	}
	result[j] = '\0';

	return (result);
}

int _strcmp(char *s1, char *s2)
{
    int i = 0, j = 0;
    int k = 0;
    while (s1[i] != '\0' || s2[j] != '\0')
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else if (s1[i] != s2[j])
        {
            k = s1[i] - s2[j];
            break;
        }
    }
    return (k);
}

char *get_path_value(char **env)
{
	char *token;
	int i = 0;
	char *temp;
	
	while (env[i])
	{
		temp = env[i];
		token = strtok(temp, "=");
		if (_strcmp(token, "PATH") == 0)
		{
			token = strtok(NULL, "=");
			return (token); 
		}
		i++;
	}
	return (NULL);
}

char **split_path(char *path)
{
	int words = 1;
	int i = 0, j = 0;
	char *token;
	char **directories;
	char *temp;

	for (i = 0; path[i]; i++)
	{
		if (path[i] == ':')
			words++;
	}

	directories = malloc(sizeof(char*) * (words + 1));

	if (!directories)
		return (NULL);

	temp = path;
	token = strtok(temp, ":");
	while(token)
	{
		directories[j] = token;
		token = strtok(NULL, ":");
		j++;
	}

	directories[j] = NULL;

	return (directories);
}


char *get_command(char **directories, char *command)
{
	struct stat st;
	char *temp;
	int i = 0;

	if (stat(command, &st) == 0)
		return (command);
	while (directories[i])
	{
		temp = append_command(directories[i], command);
		i++;
		printf("[%s]\n", temp);
		if (stat(temp, &st) == 0)
			return (temp);
		free(temp);
	}
	return (NULL);
}
