#include "sort.h"
#include <string.h>

/**
 * merge - merge subarrays into sorted array
 * @arr: array to sort
 * @cpy_arr: copy of array to sort
 * @beg: start index of left subarray
 * @mid: start index of right subarray
 * @n: size of array
 */
void merge(int *arr, int *cpy_arr, size_t beg, size_t mid, size_t n)
{
	size_t i, l, r;

	printf("Merging...\n[left]: ");
	print_array(cpy_arr + beg, mid - beg);
	printf("[right]: ");
	print_array(cpy_arr + mid, n - mid);
	for (i = l = beg, r = mid; i < n; ++i)
	{
		if (l < mid && (r >= n || cpy_arr[l] <= cpy_arr[r]))
			arr[i] = cpy_arr[l++];
		else
			arr[i] = cpy_arr[r++];
	}
	printf("[Done]: ");
	print_array(arr + beg, n - beg);
}

/**
 * splitmerge - divide unsorted array into subarrays
 * @arr: array to sort
 * @cpy_arr: copy of array to sort
 * @beg: beginning index
 * @n: size of array
 */
void splitmerge(int *arr, int *cpy_arr, size_t beg, size_t n)
{
	size_t mid;

	if (n - beg <= 1)
		return;
	mid = (beg + n) / 2;
	splitmerge(cpy_arr, arr, beg, mid);
	splitmerge(cpy_arr, arr, mid, n);
	merge(arr, cpy_arr, beg, mid, n);
}

/**
 * merge_sort - sort an int array in ascning order using merge sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *cpy_arr;

	if (!array || size < 2)
		return;
	cpy_arr = malloc(size * sizeof(*cpy_arr));
	if (!cpy_arr)
		return;
	memcpy(cpy_arr, array, size * sizeof(*cpy_arr));
	splitmerge(array, cpy_arr, 0, size);
	free(cpy_arr);
}
