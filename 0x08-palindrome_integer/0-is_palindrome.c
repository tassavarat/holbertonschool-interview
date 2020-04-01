#include "palindrome.h"

/**
 * getbeg - finds number number needed to index first digit of n
 * @n: number to check
 *
 * Return: beginning index
 */
unsigned long getbeg(unsigned long n)
{
	unsigned long beg = 1;

	do
		beg *= 10;
	while (n /= 10);
	return (beg / 10);
}

/**
 * is_palindrome - checks whether given unsigned integer is a palindrome
 * @n: number to check
 *
 * Return: 1 if palindrome, otherwise 0
 */
int is_palindrome(unsigned long n)
{
	unsigned long beg, end;

	for (beg = getbeg(n), end = 1; beg > end; beg /= 10, end *= 10)
		if (n / beg % 10 != n / end % 10)
			return (0);
	return (1);
}
