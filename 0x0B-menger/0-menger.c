#include "menger.h"

/**
 * detchar - determines whether to print '#' or ' '
 * @row: row index
 * @col: column index
 *
 * Return: '#' or ' '
 */
char detchar(size_t row, size_t col)
{
	while (row && col)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return (' ');
		row /= 3, col /= 3;
	}
	return ('#');
}

/**
 * menger - draws a 2D Menger sponge
 * @level: level of Menger sponge to draw
 *
 * Does nothing if level is lower than 0.
 */
void menger(int level)
{
	size_t size, row, col;

	if (level < 0)
		return;
	size = pow(3, level);
	for (row = 0; row < size; ++row)
	{
		for (col = 0; col < size; ++col)
			putchar(detchar(row, col));
		putchar('\n');
	}
}
