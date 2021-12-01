#include "main.h"

char *_getenv(const char *name)
{
	int i = 0;
	char **buff;
	char **aux;

	while (environ[i])
	{
		if (strstr(environ[i], name) != 0)
		{
			buff = split(environ[i], "=");
			aux = buff;
			free(buff);
			return (aux[1]);
		}
		i++;
	}
	exit (1);
}
