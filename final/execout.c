#include "main.h"
/**
 * execout - a function that reads input arguments and executes commands
 * @tokline: tokenized input by user
 * @tokpath: tokenized path
 * Return: 1 if successful 0 if error
 */

char *execout(char **tokline, char **tokpath)
{
	int status, i, notexe, child;
	char *pathdup;
	struct stat st;

	if ((strncmp(tokline[0], ".", 1)) == 0 || (strncmp(tokline[0], "/", 1) == 0))
	{
		child = fork();
		if (child == 0)
		{
			if (execve(tokline[0], tokline, NULL) == -1)
				perror("Error");
		}
		else
			wait(&status);
	}

	else
	{
		for (i = 0; tokpath[i] != NULL; i++)
		{
			pathdup = strdup(tokpath[i]), pathdup = _strcat(pathdup, "/");
			pathdup = _strcat(pathdup, tokline[0]), notexe = stat(pathdup, &st);
			if (stat(pathdup, &st) == 0)
			{
				child = fork();
				if (child == 0)
				{
					if (execve(pathdup, tokline, NULL) == -1)
						perror("Error");
				}
				else
				{
					wait(&status);
					break;
				}
			}
		}
		if (notexe != 0)
			perror("Error");
	} return (pathdup);
}
