#include "main.h"

/**
 * apply_unsigned_padding - Handles the padding when field width,
 * is greather than the number of digits
 * @len: The number of characters to be printed
 * @width: The width for formatting
 * @flags: The flags for formatting
 * @zero_pad: The characters with no padding
 *
 * Return: The number of characters printed
 */
int apply_unsigned_padding(int len, int width, int flags, int zero_pad)
{
	int pad_len = 0;

	if (width > len)
	{
		pad_len = width - len;

		for (int i = 0; i < pad_len; i++)
			_putchar(zero_pad ? '0' : ' ');
	}
	return (pad_len);
}

/**
 * apply_unsigned_precision - Adds leading zeros if the precision is,
 * greater than the number of digits.
 * @len: The number of characters to be printed
 * @precision: The precision for formatting
 *
 * Return: The number of characters printed
 */
int apply_unsigned_precision(int len, int precision)
{
	int pad_len = 0;

	if (precision > len)
	{
		pad_len = precision - len;

		for (int i = 0; i < pad_len; i++)
			_putchar('0')
	}
	return (pad_len);
}

/**
 * print_unsigned - Prints an unsigned integer.
 * @va: The unsigned int to print.
 * @flags: The flags for formatting
 * @width: The width for formatting
 * @precision: The precision for formatting
 * @length: The length modifier
 *
 * Return: The number of characters printed.
 */
int print_unsigned(va_list va, int flags, int width, int precision,
		int length);
{
	unsigned int n = va_arg(va, unsigned int);
	char buffer[20];
	int len = 0, i, total_len = 0, zero_pad = flags & (1 << 3);

	if (n == 0)
		buffer[len++] = '0';
	else
	{
		while (n != 0)
		{
			buffer[len++] = (n % 10) + '0';
			n /= 10;
		}
	}
	total_len += apply_unsigned_precision(len,  precision);

	if (!(flags & (1 << 4)))
		total_len += apply_unsigned_padding(len + total_len, width,
				flags, zero_pad);
	for (i = len - 1; i >= 0; i--)
		_putchar(buffer[i]);
	if (flags & (1 << 4))
		total_len += apply_unsigned_padding(len + total_len, width,
				flags, 0);
	return (total_len + len);
}
