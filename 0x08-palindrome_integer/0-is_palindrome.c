#include "palindrome.h"

/**
 * is_palindrome - checks whether given unsigned integer is a palindrome
 * @n: number to check
 *
 * Return: 1 if palindrome, otherwise 0
 */
int is_palindrome(unsigned long n)
{
	char str[BUFSIZ];
	size_t i, end;

	sprintf(str, "%lu", n);
	for (i = 0, end = strlen(str) - 1; i < end - i; ++i)
		if (str[i] != str[end - i])
			return (0);
	return (1);
}
