#include "sort.h"
#include <string.h>

void merge(int *merge_arr, int *arr, size_t beg, size_t mid, size_t end)
{
	size_t i, l, r;

	printf("Merging...\n[left]: ");
	print_array(merge_arr + beg, mid - beg);
	printf("[right]: ");
	print_array(merge_arr + mid, end - mid);
	for (i = l = beg, r = mid; i < end; ++i)
	{
		if (l < mid && (r >= end || merge_arr[l] <= merge_arr[r]))
			arr[i] = merge_arr[l++];
		else
			arr[i] = merge_arr[r++];
	}
	printf("[Done]: ");
	print_array(arr + beg, end - beg);
}

void splitmerge(int *arr, int *merge_arr, size_t beg, size_t end)
{
	size_t mid;

	if (end - beg <= 1)
		return;
	mid = (beg + end) / 2;
	splitmerge(merge_arr, arr, beg, mid);
	splitmerge(merge_arr, arr, mid, end);
	merge(merge_arr, arr, beg, mid, end);
}

/**
 * copyarray - copy src to dest array
 */
void copyarray(int *src, int *dest, size_t size)
{
	size_t i;

	for (i = 0; i < size; ++i)
		dest[i] = src[i];
}

/**
 * merge_sort - sort an int array in ascending order using merge sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *merge_arr;

	merge_arr = malloc(size * sizeof(*merge_arr));
	if (!merge_arr)
		return;
	/* copyarray(array, merge_arr, size); */
	memcpy(merge_arr, array, size);
	splitmerge(array, merge_arr, 0, size);
	free(merge_arr);
}
