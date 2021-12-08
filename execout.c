#include "main.h"
/**
 * execout - a function that reads input arguments and executes commands
 * @tokline: tokenized input by user
 * @tokpath: tokenized path
 * Return: 1 if successful 0 if error
 */

int execout(char **tokline, char **tokpath)
{
	int i = 0, notexe = 0;
	char *pathdup = NULL;
	struct stat st;

	if ((strncmp(tokline[0], ".", 1)) == 0 || (strncmp(tokline[0], "/", 1) == 0))
	{
		execc(tokline[0], tokline);
		return (0);
	}

	else
	{
		for (i = 0; tokpath[i] != NULL; i++)
		{
			pathdup = _strdup(tokpath[i]), pathdup = _strcat(pathdup, "/");
			pathdup = _strcat(pathdup, tokline[0]), notexe = stat(pathdup, &st);
			if (stat(pathdup, &st) == 0)
			{
				execc(pathdup, tokline);
				free(pathdup);
				break;
			}
		}
		if (notexe != 0)
			perror("Error");
	}
	return (0);
}

/**
 * execc - function that executes
 * @pathdup: duplicate of path
 * @tokline: tokenized line
 * Return: (0)
 */

int execc(char *pathdup, char **tokline)
{
	int child1 = fork();
	int status;

	if (child1 == 0)
	{
		if (execve(pathdup, tokline, NULL) == -1)
			perror(tokline[0]);
	}
	else
	{
		wait(&status);
	}
	return (0);
}
