#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
	char **buff;
	int a = 0;
	size_t aux = 0;
	char *txt = NULL;

	getline (&txt, &aux, stdin);
	txt[strlen(txt) - 1] = '\0';
	buff = split(txt, "=");
	for (a = 0; *(buff + a); a++)
		if (*buff[a] != '\0')
			printf("token is: %s\n", *(buff + a));
	free(buff);
	free(txt);
	return (0);
}
