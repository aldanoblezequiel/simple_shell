#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

int _which(char *lf);
char **split(char *line, char *delim);
char *_getenv(const char *name);
char extern **environ;

typedef struct node
{
	char *str;
	struct node *next;
} node;
