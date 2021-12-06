#include "main.h"

/**
 * _getline - function to get input from user and store it in a buffer
 * Return: returns string stored in buffer
 */

char *_getline(void)
{
	char *line = NULL;
	size_t buffsize = 0;
	int status;

	status = getline(&line, &buffsize, stdin);
	line[_strlen(line) - 1] = '\0';
	if (status == 1)
	{
		return (NULL);
	}
	
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

	if (_strcmp(token[0], "env") == 0)
	{	
		for (; envar[i] != NULL; i++)
		{
			write(STDOUT_FILENO, envar[i], _strlen(envar[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
	}
	else if (_strcmp(token[0], "exit") == 0)
		exit(130);
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
	char **tokpath;
	int mode = 1;

	tokpath = printpath(_getenv("PATH"));

	while (mode)
	{
		if (isatty(STDIN_FILENO == 1))
			write(STDOUT_FILENO, "$ ", 2);
		else
			mode = 0;
		line = _getline();
		if (line == NULL)
			continue;
		tokens = split(line, " ");
		builtins(envar, tokens);
		execout(tokens, tokpath);
	}
	free(line);
	return (0);
}
