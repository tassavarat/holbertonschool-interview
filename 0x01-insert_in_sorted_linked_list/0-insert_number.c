#include "lists.h"

/**
 * createnode - creates new linked list node
 * @id: car id
 *
 * Return: created linked list node
 */
listint_t *createnode(int number)
{
	listint_t *new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->n = number;
	new->next = NULL;
	return (new);
}

/**
 * insertsort - inserts linked list in a sorted order
 * @head: pointer to pointer of head node
 * @new: pointer to new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t **cur, *new;

	cur = head;
	new = createnode(number);
	if (!new)
		return (NULL);
	while (*cur && new->n > (*cur)->n)
		cur = &(*cur)->next;
	new->next = *cur;
	*cur = new;
	return (*head);
}
