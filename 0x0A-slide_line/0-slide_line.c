#include "slide_line.h"
#include <stdio.h>

/**
 * merge - merges array adjacent identical array values in specified direction
 * @line: pointer to array of integers
 * @size: size of array
 * @direction: direction to merge values
 */
void merge(int *line, size_t size, int direction)
{
	size_t i;

	if (direction == SLIDE_LEFT)
		for (i = 0; line[i] && i < size; ++i)
			MERGE(line, i, direction);
	else
		for (i = size - 1; line[i] && (int) i > -1; --i)
			MERGE(line, i, direction);
}

/**
 * slide - slides array values in specified direction
 * @line: pointer to array of integers
 * @size: size of array
 * @direction: direction to slide values
 */
void slide(int *line, size_t size, int direction)
{
	size_t i, empt;

	if (direction == SLIDE_LEFT)
		for (empt = i = 0; empt < size - 1 && i < size; ++empt)
			for (i = empt + 1; !line[empt] && i < size; ++i)
				SWAP(line, empt, i);
	else
		for (empt = i = size - 1; empt > 0 && (int) i > -1; --empt)
			for (i = empt - 1; !line[empt] && (int) i > -1; --i)
				SWAP(line, empt, i);
}

/**
 * slide_line - slides and merges array of integers
 * @line: pointer to array of integers
 * @size: size of array
 * @direction: direction to slide and merge
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	slide(line, size, direction);
	merge(line, size, direction);
	slide(line, size, direction);
	return (1);
}
