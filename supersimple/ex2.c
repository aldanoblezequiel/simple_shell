#include "main.h"

char **split(char *line, char *delim)
{
	int buffsize = 1024, i = 0;
	char *token;
	char **tokens = malloc(buffsize * sizeof(char*));

	if (!tokens)
	{
		fprintf(stderr, "allocation error\n");
		exit(1);
	}

	token = strtok(line, delim);
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;
	return (tokens);
}
