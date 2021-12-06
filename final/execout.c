#include "main.h"
/**
 * execout - a function that reads input arguments and executes commands
 * @tokline: tokenized input by user
 * Return: 1 if successful 0 if error
 */

int execout(char **tokline, char **tokpath)
{
	pid_t child;
	int status;
	char *pathdup;
	struct stat st;
	int i;

	if ((strncmp(tokline[0], ".", 1)) == 0 || (strncmp(tokline[0], "/", 1) == 0))
	{
		child = fork();
		if (child == 0)
		{
			if (execve(tokline[0], tokline, NULL) == -1)
				perror("Error: ");
		}
		else
			wait(&status);
	}

	else
	{
		for (i = 0; tokpath[i] != NULL; i++)
		{
			pathdup = strdup(tokpath[i]);
			pathdup = strcat(pathdup, "/");
			pathdup = strcat(pathdup, tokline[0]);
			if (stat(pathdup, &st) == 0)
			{
				child = fork();
				if (child == 0)
				{
					if (execve(pathdup, tokline, NULL) == -1)
						perror("Error: ");
				}
				else
				{
					wait(&status);
					break;
				}
			}
		}
	}
}
