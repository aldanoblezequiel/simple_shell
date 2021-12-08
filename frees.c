#include "main.h"

/**
 * _free - a function that free every argument that is passed
 * @line: line
 * @tokpath: tokpath
 * @tokens: tokens
 * @dupe: str duplicate
 */

void _free(char *line, char **tokpath, char **tokens, char *dupe)
{
	free(line);
	free(tokpath);
	free(tokens);
	free(dupe);
}

/**
 * __exit - a function that exits 
 * Return: 1
 */

int __exit(void)
{
	exit(1);
}

