#include "list.h"

/**
 * create_node - create linked list node
 * @str: string to initialise list data to
 *
 * Return: created node
 */
List *create_node(char *str)
{
	List *new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->str = strdup(str);
	if (!new->str)
		return (NULL);
	return (new);
}

/**
 * add_node_begin - insert new node to beginning of double circular linked list
 * @list: linked list being inserted to
 * @str: string to initialise list data to
 *
 * Return: pointer to new node, NULL on error
 */
List *add_node_begin(List **list, char *str)
{
	List *new;

	new = create_node(str);
	if (!new)
		return (NULL);
	if (!*list)
	{
		*list = new, (*list)->next = (*list)->prev = new;
	}
	else
	{
		new->prev = (*list)->prev, new->next = *list;
		(*list)->prev = (*list)->prev->next = new;
	}
	*list = new;
	return (new);
}

/**
 * add_node_end - insert new node to end of double circular linked list
 * @list: linked list being inserted to
 * @str: string to initialise list data to
 *
 * Return: pointer to new node, NULL on error
 */
List *add_node_end(List **list, char *str)
{
	List *new;

	new = create_node(str);
	if (!new)
		return (NULL);
	if (!*list)
	{
		*list = new, (*list)->next = (*list)->prev = new;
	}
	else
	{
		new->prev = (*list)->prev, new->next = *list;
		(*list)->prev = (*list)->prev->next = new;
	}
	return (new);
}
