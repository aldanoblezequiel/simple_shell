#include "main.h"

char *_getenv(const char *name)
{
	int i = 0;
	char **buff;
	char *aux;

	while (environ[i])
	{
		if (strstr(environ[i], name) != 0)
		{
			buff = split(environ[i], "=");
			aux = buff[1];
			free(buff);
			return (aux);
		}
		i++;
	}
}
