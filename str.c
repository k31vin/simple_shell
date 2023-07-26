#include "lesh.h"

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int w = 0;

	if (!s)
		return (0);

	while (*s++)
		w++;
	return (w);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with stack
 * @stack: string to search
 * @ndle: the substring to find
 *
 * Return: address of next char of stack or NULL
 */
char *starts_with(const char *stack, const char *ndle)
{
	while (*ndle)
		if (*ndle++ != *stack++)
			return (NULL);
	return ((char *)stack);
}

/**
 * _strcat - conczats two strings
 * @dst:destination buffer
 * @src:source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dst, char *src)
{
	char *ret = dst;

	while (*dst)
		dst++;
	while (*src)
		*dst++ = *src++;
	*dst = *src;
	return (ret);
}
