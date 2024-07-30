#include "main.h"

/**
 * hexa - Prints an unsigned integer in hexadecimal(lowercase)
 * @va: The unsigned int to print.
 *
 * Return: The number of characters printed.
 */
int hexa(va_list va, char flags[])
{
	unsigned int n = va_arg(va, unsigned int);
	int len = 0;
	char buffer[20];
	int i;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	if (flags[2] == 1)
    {
        _putchar('0');
        _putchar('x');
        len += 2;
    }

	while (n != 0)
	{
		int digit = n % 16;

		buffer[len++] = (digit < 10) ? (digit + '0') : (digit - 10 + 'a');

		n /= 16;
	}
	for (i = len - 1; i >= 0; i--)
		_putchar(buffer[i]);

	return (len);
}

/**
 * HEXA - prints an unsigned inteeger in hexadecimal(uppercase)
 * @va: The unsigned int to print
 *
 * Return: The number of characters printed.
 */
int HEXA(va_list va, char flags[])
{
	unsigned int n = va_arg(va, unsigned int);
	int len = 0;
	char buffer[20];
	int i;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	if (flags[2] == 1)
    {
        _putchar('0');
        _putchar('X');
        len += 2;
    }


	while (n != 0)
	{
		int digit = n % 16;

		buffer[len++] = (digit < 10) ? (digit + '0') : (digit - 10 + 'A');

		n /= 16;
	}
	for (i = len - 1; i >= 0; i--)
		_putchar(buffer[i]);

	return (len);
}
