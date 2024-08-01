#include "man.h"

/**
 * print_rot13 - Prints a string in rot13 encoding.
 * @args: The argument list.
 *
 * Return: The number of characters printed.
 */
int print_rot13(va_list args)
{
	char *s = va_arg(args, char *);
	int len = 0, i;
	char c;

	if (!s)
		s = "(null)";
	for (i = 0; s[i]; i++)
	{
		c = s[i];
		if ((c >= 'a' && c <= 'z'))
			c = ((c - 'a' + 13) % 26) + 'a';
		else if ((c >= 'A' && c <= 'Z'))
			c = ((c - 'A' + 13) % 26) + 'A';
		len += _putchar(c);
	}
	return (len);
}
