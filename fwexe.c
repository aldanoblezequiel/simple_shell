#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t child;
	char *argv[] ={"/bin/ls", "-l", "/tmp/", NULL};
	int status;
	int i;

	for (i = 0; i < 5; i++)
	{
		child = fork();
		if (child == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error: ");
		}
		else 
		{
			wait(&status);
			write(1, "//////////", 10);
		}
	}
	return (0);
}
