#include "main.h"
#include <sys/stat.h>
#include <limits.h>

int _which(char *lf)
{
	char cwd[PATH_MAX];
	struct stat st;

	getcwd(cwd, sizeof(cwd));
	if (stat(lf, &st) == 0)
	{
		printf(" FOUND\n");
	}
	else
	{
		printf(" NOT FOUND\n");
	}
	return (0);
}





