#include "main.h"
#include <sys/wait.h>


char **printpath(char *env_var)
{
	char **buff;

	buff = split(env_var, ":");
	return (buff);

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
		print_list(head_linked_list(printpath(_getenv(line))));
		free(line);
		freelinked(|:

		
	}
}



