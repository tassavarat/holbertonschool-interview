#include "palindrome.h"

/**
 * intlen - calculates the amount of digits in a number
 * @n: number to check
 *
 * Return: number of digits
 */
size_t intlen(size_t n)
{
	size_t len;

	len = 0;
	while (n)
	{
		n /= 10;
		++len;
	}
	return (len);
}

/**
 * is_palindrome - checks whether given unsigned integer is a palindrome
 * @n: number to check
 *
 * Return: 1 if palindrome, otherwise 0
 */
int is_palindrome(unsigned long n)
{
	size_t len, beg, end, i;

	len = i = intlen(n);
	for (beg = 1; --i; beg *= 10)
		;
	end = 1;
	for (i = 0; i < len / 2; ++i)
	{
		if (n / beg % 10 != n / end % 10)
			return (0);
		beg /= 10;
		end *= 10;
	}
	return (1);
}
