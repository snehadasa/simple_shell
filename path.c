#include "shell.h"

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
    return (s1[i] - s2[j]);
}

char *get_path_value(char **env)
{
	char *token;
	int i = 0;
	
	while (env[i])
	{
		token = strtok(env[i], "=");
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

	for (i = 0; path[i]; i++)
	{
		if (path[i] == ':')
			words++;
	}

	directories = malloc(sizeof(char*) * (words + 1));

	if (!directories)
		return (NULL);

	token = strtok(path, ":");
	while(token)
	{
		directories[j] = token;
		token = strtok(NULL, ":");
		j++;
	}

	directories[j] = NULL;

	return (directories);
}

