#include "main.h"

/**
 * convert_ptr_to_hex - Converts the pointer value to a hexadecimal,
 * string
 * @decimal: Points to the decical formatting
 * @hexa: points to the hexadecimal array that needs to be converted
 *
 * Return: The number of characters printed
 */
int convert_ptr_to_hex(unsigned long int decimal, char hexa[])
{
	int len = 0;

	while (decimal)
	{
		int result = decimal % 16;

		hexa[len++] = (result < 10) ? (result + '0') : (result - 10 + 'a');
		decimal /= 16;
	}
	return (len);
}

/**
 * handle_null_pointer - Handles the cases where the pointer is 'NULL'
 * @buffer: The buffer array to handle print
 *
 * Return: The number of characters printed
 */
int handle_null_pointer(char buffer[])
{
	char *nil = "(nil)";
	int len = 0;

	while (nil[len])
	{
		buffer[len] = nil[len];
		len++;
	}
	write(1, buffer, len);
	return (len);
}

/**
 * print_p - Prints a pointer address
 * @va: The pointer to point
 * @flags:The flags for formatting
 * @width: The width for formatting
 * @precision: The precision for formatting
 * @length: The length modifier
 *
 * Return: The characters printed
 */
int print_p(va_list va, int flags, int width, int precision, int length)
{
	void *addr = va_arg(va, void *);
	unsigned long int decimal = (unsigned long int)addr;
	char buffer[1024], hexa[100];
	int i = 0, len;

	if (!addr)
		return (handle_null_pointer(buffer));

	buffer[i++] = '0';
	buffer[i++] = 'x';

	len = convert_ptr_to_hex(decimal, hexa);

	for (int j = len - 1; j >= 0; j--)
		buffer[i++] = hexa[j];

	write(1, buffer, i);
	return (i);
}
