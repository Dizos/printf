#include "main.h"

/**
 * t_string - Prints a string.
 * @va: Pointer to string
 * @flags: The flags for formatting
 * @width: The width for formatting
 * @precision: The precision for formatting
 * @length: The length modifier
 *
 * Return: The number of strings pointed
 */
int t_string(va_list va, int flags, int width, int precision, int length)
{
	int i, len = 0;
	char *s = va_arg(va, char *);
	char pad_char = (flags & (1 << 3)) ? '0' : ' ';

	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] && (precision < 0 || i < precision))
		len++;
	width -= len;

	if (!(flags & (1 << 4)))
		while (width-- > 0)
			_putchar(pad_char);
	for (i = 0; i < len; i++)
		_putchar(s[i]);
	while (width-- > 0)
		_putchar(' ');
	return (len + (width > 0 ? width : 0));
}
