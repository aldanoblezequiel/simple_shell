#include "main.h"

/**
 * _getenv - return path as array
 * Return: value of path
 */
char *_getenv(char *name)
{
	int i = 0;
	char **buff;
	char *aux;
	
	while (environ[i] && _strstr(environ[i], name) == 0)
	{
		i++;
	}
	if (environ[i])
	{
		buff = split(environ[i], "=");
		i = 0;
	}
	aux = buff[1];
	return (aux);
}

/**
 * pat_to_arr - converts string path to array
 * @path: string of path value
 * Return: array of path value
 */

char **printpath(char *path)
{
	char **buff;

	buff = split(path, ":");
	return (buff);
}

