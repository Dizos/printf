#include "main.h"

/**
 * print_reversed - Prints a reversed string.
 * @args: The argument list.
 *
 * Return: The number character printed.
 */
int print_reversed(va_list args)
{
	char *s = va_arg(args, char *);
	int len = 0, i;

	if (s == NULL)
		s = "(null)";
	for (i = strlen(s) - 1; i >= 0; i--)
		len += _putchar(s[i]);
	return (len);
}
