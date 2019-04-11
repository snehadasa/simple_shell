#include "shell.h"
/**
 * _strcmp - a function that compare the string.
 * @s1: character value
 * @s2: character value
 *
 *Return: 0.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, j = 0, k = 0;

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
#include "shell.h"
/**
 * _strlen - returns the length of a string.
 * @s: character value.
 *
 *Return: i value
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != 0; i++)
		;
	return (i);
}
#include "shell.h"
/**
 * _strcpy -  a function that copies the string.
 * @dest : character value
 * @src  : character value
 *
 *Return: return the pointer to desk.
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
#include "shell.h"
/**
 * _strcat - concentrate two string.
 *@dest: character value.
 *@src: character value.
 *
 * Return: dest value.
 */
char *_strcat(char *dest, char *src)
{
	int a, b;

	for (a = 0; dest[a] != '\0'; a++)
		;
	b = 0;
	while (src[b] != '\0')
	{
		dest[a] = src[b];
		b++;
		a++;
	}
	dest[a] = '\0';
	return (dest);
}
