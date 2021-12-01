#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

char **split(char *line, char *delim);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strstr(char *haystack, char *needle);
