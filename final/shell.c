#include "main.h"

/**
 * _getline - function gets input form user and store it in a buffer
 * @tokens: strings
 * @linebuff: buffer contains the line
 * @tokpath: tokens path
 * @dupe: char dupe
 * Return: returns string stored in buffer
 */

char *_getline(char *linebuff, char **tokpath, char **tokens, char *dupe)
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
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		_free(linebuff, tokpath, tokens, dupe);
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
	char *line, *dupe;
	char **tokens;
	char **tokpath;
	int mode = 1, ifbuilt;

	tokpath = printpath(_getenv("PATH"));

	while (mode)
	{
		if (isatty(STDIN_FILENO == 1))
			write(STDOUT_FILENO, "$ ", 2);
		else
			mode = 0;
		line = _getline(line, tokpath, tokens, dupe);
		if (line == NULL)
			continue;
		tokens = split(line, " ");

		ifbuilt = builtins(envar, tokens);
		if (_strcmp(tokens[0], "exit") == 0)
		{
			break;
		}
		if (ifbuilt != 1)
			dupe = execout(tokens, tokpath);
	}
	_free(line, tokpath, tokens, dupe);
	__exit();
	return (0);
}
