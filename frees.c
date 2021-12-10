#include "main.h"

/**
 * _free - a function that free every argument that is passed
 * @line: line
 * @tokpath: tokpath
 * @tokens: tokens
 */

void _free(char *line, char **tokpath, char **tokens)
{
	free(line);
	free(tokpath);
	free(tokens);
}

/**
 * __exit - a function that exits
 * Return: 1
 */

int __exit(void)
{
	exit(1);
}

