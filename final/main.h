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

typedef struct node
{
	char *str;
	struct node *next;
} node;

char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strstr(char *haystack, char *needle);
int _which(char *lf);
char **split(char *line, char *delim);
char *_getenv(const char *name);
char extern **environ;
node *head_linked_list(char **env);
node *add_node_end(node **head, const char *str);
void print_list(const node *h);

#endif
