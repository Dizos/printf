#include "main.h"

/**
 * print_p - Prints a pointer address
 * @va: The pointer to point
 *
 * Return: The number of characters printed
 */
int print_p(va_list va)
{
	void *addr;
	unsigned long int decimal, result;
	char buffer[1024];
	char hexa[100];
	int len = 0, i = 0, j;
	char *nil = "(nil)";

	addr = va_arg(va, void *);
	decimal = (unsigned long int)addr;

	if (!addr)
	{
		while (nil[len])
		{
			buffer[i++] = nil[len++];
		}
		write(1, buffer, len);
		return (len);
	}
	buffer[i++] = '0';
	buffer[i++] = 'x';
	len += 2;

	while (decimal)
	{
		result = decimal % 16;
		hexa[len - 2] = (result < 10) ? (result + '0') : (result - 10 + 'a');
		decimal /= 16;
		len++;
	}
	for (j = 0; j < len - 2; j++)
	{
		buffer[i++] = hexa[len - 3 - j];
	}
	write(1, buffer, i);
	return (i);
}

