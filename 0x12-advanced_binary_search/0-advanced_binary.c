#include "search_algos.h"

/**
 * binary_search - recursive binary search algorithm
 * @a: pointer to array to search
 * @target: target to find
 * @l: left boundary index
 * @r: right boundary index
 *
 * Return: index where target found or -1 if target not found
 */
int binary_search(int *a, int target, int l, int r)
{
	int i;

	if (l == r)
		return (l);
	printf("Searching in array: ");
	for (i = l; i <= r; ++i)
		printf("%d%s", a[i], i < r ? ", " : "");
	printf("\n");
	i = (l + r) / 2;
	if (a[i] < target)
		l = i + 1;
	else
		r = i;
	l = binary_search(a, target, l, r);
	return (a[l] == target ? l : -1);
}

/**
 * advanced_binary - find leftmost value in array using binary search
 * @array: pointer to array to search
 * @size: size of array
 * @value: value to search for
 *
 * Return: index where value is located
 * -1 if array is NULL or value not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (binary_search(array, value, 0, size - 1));
}
