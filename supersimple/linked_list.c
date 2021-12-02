#include "main.h"

node *head_linked_list(char **env)
{
	node *head;
	int i = 0;

	head = NULL;
	head = malloc(sizeof(node));

	while (env[i] != NULL)
	{
		add_node_end(&head, env[i]);
		i++;
	}
	return (head);
}

node *add_node_end(node **head, const char *str)
{
	node *end_head;
	node *temp;

	end_head = malloc(sizeof(node));
	if (end_head == NULL)
		return (NULL);

	end_head->str = strdup(str);
	if (end_head->str == NULL)
	{
		free(end_head);
		return (NULL);
	}
	end_head->next = NULL;
	if (*head == NULL)
	{
		*head = end_head;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = end_head;
	}
	return (*head);
}

void print_list(const node *h)
{
	if (!h)
		exit(-1);
	if (h->str == NULL)
		printf("(nil)\n");
	else
		printf("%s\n", h->str);
	if (h->next)
		print_list(h->next);
}
