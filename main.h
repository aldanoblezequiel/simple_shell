#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;
/**
 * struct node - singly string linked list
 * @str: string value (malloc'ed)
 * @next: pointer to next node
 *
 * Description: singly linked list node structure to hold tokenized values
 */

typedef struct node
{
	char *str;
	struct node *next;
} node;
char *_strdup(char *str);
void _free(char *line, char **tokpath, char **tokens, char *dupe);
int __exit(void);
char *execout(char **tokline, char **tokpath);
int shell(char **envar);
char **printpath(char *path);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strstr(char *haystack, char *needle);
int _which(char *lf);
char **split(char *line, char *delim);
char *_getenv(void);
int _strcmp(char *s1, char *s2);

#endif
