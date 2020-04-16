#include "slide_line.h"
#include <stdio.h>

/**
 * combine - combines two values together
 * @line: pointer to array of integers
 * @i: pointer to line index
 * @direction: direction to merge values
 *
 * Description: modifies i depending on direction, this is done for the calling
 * function
 */
void combine(int *line, size_t *i, int direction)
{
	if (line[*i] == line[*i - direction])
	{
		line[*i] += line[*i - direction];
		line[*i - direction] ^= line[*i - direction];
		*i -= direction;
	}
}
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
			combine(line, &i, direction);
	else
		for (i = size - 1; line[i] && (int) i > -1; --i)
			combine(line, &i, direction);
}

/**
 * swap - swaps two values in an array
 * @line: pointer to array of integers
 * @direction: direction to slide values
 * @empt: pointer to line index with 0 value
 * @i: line index used to check for non 0 values
 * @merged: specifies if merging has been done
 *
 * Description: modifies empt depending on direction, this is done
 * for the calling function
 * Return: 0 initially, 1 subsequently, returning 1 dependent on merged value
 */
int swap(int *line, int direction, size_t *empt, size_t i, int merged)
{
	if (merged && !line[i] && !line[i - direction])
		return (1);
	if (line[i])
	{
		line[*empt] ^= line[i];
		line[i] ^= line[*empt];
		line[*empt] ^= line[i];
		*empt -= direction;
	}
	return (0);
}

/**
 * slide - slides array values in specified direction
 * @line: pointer to array of integers
 * @size: size of array
 * @direction: direction to slide values
 */
void slide(int *line, size_t size, int direction)
{
	static int merged;
	size_t i, empt;

	if (direction == SLIDE_LEFT)
	{
		for (empt = 0; line[empt] && empt < size; ++empt)
			;
		for (i = empt + 1; i < size; ++i)
			if (swap(line, direction, &empt, i, merged))
				break;
	}
	else
	{
		for (empt = size - 1; line[empt] && (int) empt > -1; --empt)
			;
		for (i = empt - 1; (int) i > -1; --i)
			if (swap(line, direction, &empt, i, merged))
				break;
	}
	merged = 1;
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
