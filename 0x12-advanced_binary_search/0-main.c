#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

int advanced_binary_iterative(int *array, size_t size, int value)
{
	int l = 0, r = size - 1, i;

	while (array && l != r)
	{
		printf("Searching in array: ");
		for (i = l; i <= r; ++i)
			printf("%d%s", array[i], i < r ? ", " : "");
		printf("\n");
		i = (l + r) / 2;
		if (array[i] < value)
			l = i + 1;
		else
			r = i;
	}
	return (array[l] == value ? l : -1);
}

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
	int array[] = {
		0, 1, 2, 5, 5, 6, 6, 7, 8, 9
	};
	size_t size = sizeof(array) / sizeof(array[0]);

	printf("Found %d at index: %d\n\n", 8, advanced_binary(array, size, 8));
	/* printf("Found %d at index: %d\n\n", 8, advanced_binary_iterative(array, size, 8)); */
	printf("Found %d at index: %d\n\n", 5, advanced_binary(array, size, 5));
	/* printf("Found %d at index: %d\n\n", 5, advanced_binary_iterative(array, size, 5)); */
	printf("Found %d at index: %d\n\n", 999, advanced_binary(array, size, 999));
	/* printf("Found %d at index: %d\n\n", 999, advanced_binary_iterative(array, size, 999)); */
	printf("Found %d at index: %d\n", 3, advanced_binary(array + size -1, 1, 3));
	/* printf("Found %d at index: %d\n", 3, advanced_binary_iterative(array + size -1, 1, 3)); */
	return (EXIT_SUCCESS);
}
