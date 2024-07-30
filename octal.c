#include "main.h"

/**
 * octal - prints an unsigned integer in octal.
 * @va: The unsigned int to print.
 *
 * Return: The number of characters printed.
 */
int octal(va_list va, char flags[])
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
        len++;
    }

	while (n != 0)
	{
		buffer[len++] = (n % 8) + '0';
		n /= 8;
	}
	for (i = len - 1; i >= 0; i--)
		_putchar(buffer[i]);

	return (len);
}
