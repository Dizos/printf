#include "main.h"

/**
 * print_p - Prints a pointer address
 * @va: The pointer to point
 *
 * Return: The number of characters printed
 */
int print_p(va_list va)
{
	unsigned long int addr = (unsigned long int)va_arg(va, void *);
	int len = 0, i = 0, j;
	char buffer[20];

	if (!addr)
	{
		return (_printf("(nil)"));
	}

	buffer[i++] = '0';
	buffer[i++] = 'x';
	len += 2;


	while (addr)
	{
		int digit = addr % 16;

		buffer[i++] = (digit < 10) ? (digit + '0') : (digit - 10 + 'a');
		addr /= 16;
	}
	for (j = 2; j < i / 2 + 2; j++)
	{
		char tmp = buffer[j];

		buffer[j] = buffer[i - j + 1];
		buffer[i - j + 1] = tmp;
	}

	for (j = 0; j < i; j++)
	{
		_putchar(buffer[j]);
	}
	len += i - 2;
	return (len);
}
