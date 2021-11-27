#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(void)
{
	int ac[] = {1, 2, 3, 4, 5};
	char **av[] = (char **)malloc(3 * sizeof(char *));
	int i = 0;

	for (i = 0; i < 3; i++)
	{
		av[i] = (char *)malloc(50 * sizeof(char));
	}
	sprintf(av[0], "hsh");
	sprintf(av[1], "ls");
	sprintf(av[2], "-l");

	for (i = 0; i < 3; i++)
		printf("%s", av[i]);
	for (i = 0; i < 3; i++)
		free(av[i]);
	free(av);
	return (0);
}
