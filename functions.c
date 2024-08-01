#include "main.h"

/**
 * get_digit_count - calculates the number of digits in the number
 * @num: The number
 *
 * Return: The number of digits in the number, 1 if number is 0
 */
int get_digit_count(unsigned int num)
{
	int count = 0;

	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

/**
 * print_digits - Prints numbers in recursive
 * @num: The number to be printed
 */
void print_digits(unsigned int num)
{
	if (num / 10)
		print_digits(num / 10);
	_putchar((num % 10) + '0');
}

/**
 * handle_sign_and_padding - Handles the sign of numbers and padding
 * @n: The number to be printed
 * @len: The number of characters to be printed
 * @flags: The flags for formatting
 * @width: The width for formatting
 * @num_digits: Numbers and digits to be printed
 */
void handle_sign_and_padding(int n, int *len, int flags, int width,
		int num_digits)
{
	int padding = width - num_digits;
	char pad_char = (flags & (1 << 3)) ? '0' : ' ';

	if (n < 0)
	{
		_putchar('-');
		(*len)++;
	}
	else if (flags & (1 << 0))
	{
		_putchar('+');
		(*len)++;
		padding--;
	}
	else if (flags & (1 << 1))
	{
		_putchar(' ');
		(*len)++;
		padding--;
	}
	if (!(flags & (1 << 4)))
	{
		while (padding-- > 0)
		{
			_putchar(pad_char);
		}
	}
}
/**
 * print_number - Prints an integer
 * @va: The integer to print
 * @flags: The flags for formatting
 * @width: The width for formatting
 * @precision: The precision for formatting
 * @length: The length modifier
 * Return: The number of characters printed.
 */
int print_number(va_list va, int flags, int width, int precision, int length)
{
	int n = va_arg(va, int);
	unsigned int abs = (n < 0) ? -n : n;
	int num_digits = get_digit_count(abs);
	int len = 0;

	handle_sign_and_padding(n, &len, flags, width, num_digits);
	if (abs == 0)
	{
		_putchar('0');
		len++;
	}
	else
	{
		print_digits(abs);
		len += num_digits;
	}
	return (len);
}

/**
 * binary - Prints an unsigned int in binary.
 * @va: The argument list with the unsigned int to print
 * Return: The number of characters printed.
 */
int binary(va_list va, int flags, int width, int precision, int length)
{
	unsigned int c;
	int i, k;
	int arr[100];

	/* suppress unused parameter */
	(void)flags;
	(void)width;
	(void)precision;
	(void)length;

	c = va_arg(va, unsigned int);
	i = 0;

	if (c == 0)
	{
		_putchar('0');
			return (1);
	}
	while (c > 0)
	{
		arr[i] = c % 2;
		c = c / 2;
		i++;
	}
	for (k = i - 1; k >= 0; k--)
		_putchar(arr[k] + '0');
	return (i);
}
