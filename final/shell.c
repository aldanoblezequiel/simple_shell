#include "main.h"

/**
 * _getline - function to get input from user and store it in a buffer
 * Return: returns string stored in buffer
 */

char *_getline(void)
{
	char *line = NULL;
	size_t buffsize = 0;

	getline(&line, &buffsize, stdin);
	line[strlen(line) - 1] = '\0';

	return line;

}

/**
 * builtins - function that executes builtins
 * @token: first token (holds first input command)
 * @envar: enviroment variables
 * Return: void
 */

void builtins(char **envar, char **token)
{	
	int i = 0;

	if (token[0] == "env")
	{	
		for (i; envar[i] != NULL; i++)
		{
			write(STDOUT_FILENO, envar[i], _strlen(envar[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
	}
}
/**
 * shell - runs user prompt and executes repeatedly
 * @envar: enviroment variables
 * Return: 0 on success
 */

int shell(char **envar)
{
	char *line;
	char **tokens;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		line = _getline();
		tokens = split(line, " ");
		builtins(envar, tokens);
		free(line);
	}
}
