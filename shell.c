#include "main.h"

/**
 * _getline - function gets input form user and store it in a buffer
 * @tokens: strings
 * @linebuff: buffer contains the line
 * @tokpath: tokens path
 * Return: returns string stored in buffer
 */

char *_getline(char *linebuff, char **tokpath, char **tokens)
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
	/* handles ctrl D */
	if (status == -1)
	{
		_free(linebuff, tokpath, tokens);
		__exit();
	}
	return (line);

}

/**
 * builtins - function that executes builtins
 * @token: first token (holds first input command)
 * @envar: enviroment variables
 * Return: void
 */

int builtins(char **envar, char **token)
{
	int i = 0;

	if (_strcmp(token[0], "env") == 0)
	{
		for (; envar[i] != NULL; i++)
		{
			write(STDOUT_FILENO, envar[i], _strlen(envar[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		return (1);
	}
	else
		return (0);
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
	int ifbuilt;

	tokpath = printpath(_getenv());

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		line = _getline(line, tokpath, tokens);
		if (line == NULL)
			continue;
		tokens = split(line, " ");

		ifbuilt = builtins(envar, tokens);
		if (_strcmp(tokens[0], "exit") == 0)
		{
			break;
		}
		if (ifbuilt != 1)
			execout(tokens, tokpath);
	}
	_free(line, tokpath, tokens);
	__exit();
	return (0);
}
