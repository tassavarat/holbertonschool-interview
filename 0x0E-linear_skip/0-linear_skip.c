#include "search.h"

/**
 * check_lin - check for value in list linearly
 * @list: pointer to list being searched
 * @value: value to search for
 * @stop: pointer to node to stop searching at
 *
 * Return: pointer to first node where value is located, otherwise NULL
 */
skiplist_t *check_lin(skiplist_t *list, int value, skiplist_t *stop)
{
	printf("Value found between indexes [%lu] and [%lu]\n",
			list->index, stop->index);
	while (list != stop->next)
	{
		printf("Value checked at index [%lu] = [%i]\n",
				list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}
	return (NULL);
}

/**
 * linear_skip - search for value in skip list of integers
 * @list: pointer to head of skip list to search
 * @value: value to search for
 *
 * Return: pointer to first node where value is located, otherwise NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *stop;

	while (list)
	{
		printf("Value checked at index [%lu] = [%i]\n",
				list->express->index, list->express->n);
		if (list->express->n >= value)
			return (check_lin(list, value, list->express));
		list = list->express;
		if (!list->express)
		{
			for (stop = list; stop->next; stop = stop->next)
				;
			return (check_lin(list, value, stop));
		}
	}
	return (NULL);
}
