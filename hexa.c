#include "main.h"

/**
 * convert_to_hex - Converts integer to a hexadecimal string
 * @n: Integer to convert
 * @buffer: Buffer array to handle print
 * @base_char: Character string to print
 * Return: The number of characters to print
 */
int convert_to_hex(unsigned int n, char buffer[], char base_char)
{
	int len = 0;

	if (n == 0)
		buffer[len++] = '0';
	else
	{
		while (n != 0)
		{
			int digit = n % 16;

			buffer[len++] = (digit < 10) ? (digit + '0') : (digit - 10 + base_char);
			n /= 16;
		}
	}
	return (len);
}

/**
 * handle_padding - Handles the padding and flags
 * @buffer: Buffer array to handle print
 * @len: The number of characters printed
 * @flags: The flags for formatting
 * @width: The width for formatting
 * @precision: The precision for formatting
 */
void handle_padding(char buffer[], int *len, int flags, int width,
		int precision)
{
	while (*len < precision)
		buffer[(*len)++] = '0';
	if (!(flags & (1 << 4)))
	{
		while (*len < width)
			buffer[(*len)++] = (flags & (1 << 3)) ? '0' : ' ';
	}
}

/**
 * hexa - Prints an unsigned integer in hexadecimal(lowercase)
 * @va: The unsigned int to print.
 * @flags: The flags for formatting
 * @width: The width for formatting
 * @precision: The precision for formatting
 * @length: The length modifier
 *
 * Return: The number of characters printed.
 */
int hexa(va_list va, int flags, int width, int precision, int length)
{
	unsigned int n = (length == 1) ? va_arg(va, unsigned long) :
		(length == 2) ? (unsigned short)va_arg(va, unsigned int) :
		va_arg(va, unsigned int);
	char buffer[20];
	int len = convert_to_hex(n, buffer, 'a');

	handle_padding(buffer, &len, flags, width, precision);

	if ((flags & (1 << 2)) && n != 0)
	{
		buffer[len++] = 'x';
		buffer[len++] = '0';
	}
	for (int i = len - 1; i >= 0; i--)
		_putchar(buffer[i]);
	if (flags & (1 << 4))
	{
		while (len < width)
		{
			_putchar(' ');
			len++;
		}
	}
	return (len);
}

/**
 * Hexa - Prints an unsigned integer in hexadecimal(uppercase)
 * @va: The unsigned int to print.
 * @flags: The flags for formatting
 * @width: The width for formatting
 * @precision: The precision for formatting
 * @length: The length modifier
 *
 * Return: The number of characters printed.
 */
int Hexa(va_list va, int flags, int width, int precision, int length)
{
	unsigned int n = (length == 1) ? va_arg(va, unsigned long) :
		(length == 2) ? (unsigned short)va_arg(va, unsigned int) :
		va_arg(va, unsigned int);

	char buffer[20];
	int len = convert_to_hex(n, buffer, 'A');

	handle_padding(buffer, &len, flags, width, precision);

	if ((flags & (1 << 2)) && n != 0)
	{
		buffer[len++] = 'x';
		buffer[len++] = '0';
	}
	for (int i = len - 1; i >= 0; i--)
		_putchar(buffer[i]);
	if (flags & (1 << 4))
	{
		while (len < width)
		{
			_putchar(' ');
			len++;
		}
	}
	return (len);
}
