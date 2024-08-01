#include "main.h"

/**
 * handle_non_printable_char - Handles the non_printable characters
 * @c: The character to handle
 *
 * Return: The number of characters printed
 */
int handle_non_printable_char(unsigned char c)
{
	char hex[3];

	_putchar('\\');
	_putchar('x');
	sprintf(hex, "%02X", c);
	_putchar(hex[0]);
	_putchar(hex[1]);

	return (4);
}

/**
 * apply_padding - Handles non-printable character conversion
 * @len: The number of characters printed
 * @width: The width formatting
 * @flags: The flags formatting
 *
 * Return: The number of non-printable characters printed
 */
int apply_padding(int len, innt width, int flags)
{
	int pad_len = 0;

	if (width > len)
	{
		pad_len = width - len;

		for (int i = 0; i < pad_len; i++)
			_putchar(flags & (1 << 3) ? '0' : ' ');
	}
	return (pad_len);
}

/**
 * print_S - Prints a string and handles non-printable characters
 * @va: The string to print
 * @flags: The flags for formatting
 * @width: The width for formatting
 * @precision: The precision for formatting
 * @length: The length modifier
 *
 * Return: The number of printable and non_printable characters printed
 */
int print_S(va_list va, int flags, int width, int precision, int length)
{
	char *s = va_arg(va, char *);
	int i, len = 0, pad_len = 0;

	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i] != '\0'; i++)
	{
		if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
			len += handle_non_printable_char((unsigned char)s[i]);
		else
			len++, _putchar(s[i]);
		if
			len++, _putchar(s[i]);
		if (precision && len >= precision)
			break;
	}
	pad_len = apply_padding(len, width, flags);
	return (len + pad_len);
}
