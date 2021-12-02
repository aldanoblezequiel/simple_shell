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
int shell(char **envar);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strstr(char *haystack, char *needle);
int _which(char *lf);
char **split(char *line, char *delim);
char *_getenv(const char *name);
node *head_linked_list(char **env);
node *add_node_end(node **head, const char *str);
void print_list(const node *h);

#endif
