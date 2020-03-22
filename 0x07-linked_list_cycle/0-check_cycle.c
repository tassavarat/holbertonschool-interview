#include "lists.h"

/**
 * check_cycle - Checks if singly linked list is cyclical
 * @list: pointer to head of linked list node
 *
 * Return: 1 if cycle found, otherwise 0
 */
int check_cycle(listint_t *list)
{
	listint_t *fast;

	for (fast = list->next; fast && fast->next; fast = fast->next->next)
	{
		if (fast == list)
			return (1);
		list = list->next;
	}
	return (0);
}
