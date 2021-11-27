#include "main.h"

char **split(char *line)
{
	int buffsize = 1024, i = 0;
	char *token;
	char **tokens = malloc(buffsize * sizeof(char*));

	if (!tokens)
	{
		fprintf(stderr, "allocation error\n");
		exit(1);
	}

	token = strtok(line, " ");
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;
	return (tokens);
}
