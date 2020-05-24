#include "search.h"

/**
 * linear_skip - search for value in skip list of integers
 * @list: pointer to head of skip list to search
 * @value: value to search for
 *
 * Return: pointer to first node where value is located, otherwise NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *stop = NULL;
	char lin = 0;

	while (list && list != (!stop ? NULL : stop->next))
	{
		printf("Value checked at index[%lu] = [%i]\n",
				!lin ? list->express->index : list->index,
				!lin ? list->express->n : list->n);
		if (!lin && list->express->n >= value)
		{
			stop = list->express;
			goto cont;
		}
		if (list->n == value)
			return (list);
		list = !lin ? list->express : list->next;
		if (!lin && !list->express)
		{
			for (stop = list; stop->next; stop = stop->next)
				;
cont:
			lin = 1;
			printf("Value found between indexes [%lu] and [%lu]\n",
					list->index, stop->index);
			continue;
		}
	}
	return (NULL);
}
