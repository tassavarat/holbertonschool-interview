#include "sort.h"

/**
 * csort_radix - counting sort to be called by radix_sort
 * @array: array to sort
 * @size: size of array
 * @place: current digit place to sort
 * @sorted: array to store sorted values in
 */
void csort_radix(int *array, size_t size, int place, int *sorted)
{
	int count[BASE] = {0};
	size_t i;
	ssize_t j;

	for (i = 0; i < size; ++i)
		++count[array[i] / place % 10];
	for (i = 1; i < BASE; ++i)
		count[i] += count[i - 1];
	for (j = size - 1; j >= 0; --j)
	{
		sorted[count[array[j] / place % 10] - 1] = array[j];
		--count[array[j] / place % 10];
	}
	memcpy(array, sorted, size * sizeof(*sorted));
}

/**
 * find_max - find maximum value in array
 * @array: array to search
 * @size: size of array
 *
 * Return: maximum value
 */
int find_max(int *array, size_t size)
{
	size_t i;
	int max;

	for (i = 1, max = *array; i < size; ++i)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * radix_sort - sort int array in ascending order using radix sort
 * @array: array of integers to sort
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int max, place, *sorted;

	if (!array || size < 2)
		return;
	sorted = calloc(size, sizeof(*sorted));
	if (!sorted)
		return;
	max = find_max(array, size);
	for (place = 1; max / place > 0; place *= BASE)
	{
		csort_radix(array, size, place, sorted);
		print_array(array, size);
	}
	free(sorted);
}
