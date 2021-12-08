#include "main.h"

/**
 * _getenv - return path as array
 * Return: value of path
 */
char *_getenv(void)
{
	int i = 0;
	char *buff;
	int str_val;

	for (i = 0; environ[i]; i++)
	{
		str_val = strncmp(environ[i], "PATH", 4);
		if (str_val == 0)
		{
			buff = environ[i];
			break;
		}
	}
	buff += 5;
	return (buff);
}

/**
 * printpath - converts string path to array
 * @path: string of path value
 * Return: array of path value
 */

char **printpath(char *path)
{
	char **buff;

	buff = split(path, ":");
	return (buff);
}
