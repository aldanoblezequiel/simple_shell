#include "main.h"

/**
 * split - a function that tokenizes a string
 * @line: input from user
 * @delim: delimiter for strtok
 * Return: tokenized string in form of array
 */

char **split(char *line, char *delim)
{
	int buffsize = 1024, i = 0;
	char *token;

	char **tokens = malloc(buffsize * sizeof(char *));

	*tokens = NULL;
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
