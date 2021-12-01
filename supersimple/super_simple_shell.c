#include "main.h"
#include <sys/wait.h>


void printpath(void)
{
	int i = 0, j;
	char **buff;
	char *strings;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strstr(environ[i], "PATH") != 0)
		{
			buff = split(environ[i], "=");
		}
	}
	strings = buff[1];
	buff = split(strings, ":");
	for (j = 0; buff[j] != NULL; j++)
		printf("%s\n", buff[j]);
	free(buff);
}

char *_getline(void)
{
	char *line = NULL;
	size_t buffsize = 0;
	int i;

	getline(&line, &buffsize, stdin);
	line[strlen(line) - 1] = '\0';

	return line;

}

int _execout(char *line)
{
	pid_t child;
	int status;
	char *argv[] ={line, NULL};

	child = fork();
	if (child == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
			perror("Error: ");
	}
	else
		wait(&status);
}

int main(int argc, char *argv[], char **env)
{
	char *line;
	char *env1;


	while (1)
	{
		printf("$ ");
		line = _getline();
		printpath();
		free(line);

		
	}
}



