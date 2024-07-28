#include "main.h"

/**
 * t_char - Prints a single character.
 * @va: The character to print
 *
 * Return: The number of characters printed
 */
int t_char(va_list va)
{
	int c;

	c = va_arg(va, int);
	_putchar(c);
	return (1);
}

/**
 * t_string - Prints a string.
 * @va: Pointer to string
 *
 * Return: The number of strings pointed
 */
int t_string(va_list va)
{
	int i, j;
	char n[] = "(null)";
	char *s = va_arg(va, char *);

	if (s == NULL)
	{
		for (i = 0; n[i] != '\0'; i++)
			_putchar(n[i]);
		return (6);
	}
	for (j = 0; s[j] != '\0'; j++)
		_putchar(s[j]);
	return (j);
}
/**
 * print_number - Prints an integer
 * @va: The integer to print
 *
 * Return: The number of characters printed.
 */
int print_number(va_list va)
{
	int n = va_arg(va, int);
	int i, len, r, l;
	unsigned int abs, num, numt;

	len = 0;
	i = 0;
	r = 1;
	l = 1;

	if (n < 0)
	{
		_putchar('-');
		len++;
		abs = -n;
	} else
	{
		abs = n;
	}
	num = abs;

	while (num > 0)
	{
		num /= 10;
		i++;
	}
	while (r < i)
	{
		l *= 10;
		r++;
	}
	while (l >= 1)
	{
		numt = (abs / l) % 10;
		_putchar(numt + '0');
		len++;
		l /= 10;
	}
	return (len);
}
/**
 * binary - Prints an unsigned int in binary.
 * @va: The unsigned int to print.
 *
 * Return: The number of characters printed.
 */
int binary(va_list va)
{
	unsigned int c;
	int i, k;
	int arr[100];

	c = va_arg(va, int);
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
