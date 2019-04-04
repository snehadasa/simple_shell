#include <stdio.h>

int main ()
{
	char *buffer;
	size_t size = 0;
	ssize_t lineptr = 0;

	while (lineptr != EOF)
	{
		printf("$ ");
		lineptr = getline(&buffer, &size, stdin);

		printf("%s", buffer);
	}
	return (0);
}
