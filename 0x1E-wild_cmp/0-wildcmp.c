#include "holberton.h"

/**
 * wildcmp - compare two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 1 if strings identical, 0 if not or on error
 */
int wildcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	if (!*s1)
	{
		if (*s2 == '*')
			return (wildcmp(s1, s2 + 1));
		return (*s2 == '\0');
	}
	if (*s2 == '*')
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	return (0);
}
