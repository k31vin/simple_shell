#include "lesh.h"

/**
 * _strcpy - copies a string
 * @dst:destination
 * @src:source
 *
 * Return: pter to destination
 */
char *_strcpy(char *dst, char *src)
{
	int k = 0;

	if (dst == src || src == 0)
		return (dst);
	while (src[k])
	{
		dst[k] = src[k];
		k++;
	}
	dst[k] = 0;
	return (dst);
}

/**
 * _strdup - duplicates a string
 * @str:string to duplicate
 *
 * Return: pointer to  duplicate string
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	for (len++; len--;)
		ret[len] = *--str;
	return (ret);
}

/**
 *_puts - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On sucess 1.
 * On error, -1 is returned, and err no is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
