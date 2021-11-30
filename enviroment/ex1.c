#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av, char **env)
{
	extern char **environ;

	printf("%p\n", &environ);
	printf("%p\n", &env);
}
