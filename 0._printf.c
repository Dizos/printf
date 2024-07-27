#include "main.h"

/**
 * print_char - Prints a character.
 * @args: List of arguments.
 *
 * Return: Number of characters printed.
 */
int print_char(va_list args)
{
	return (_putchar(va_arg(args, int)));
}

/**
 * print_string - Prints a string.
 * @args: List of arguments.
 *
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (!str)
		str = "(null)";
	while (*str)
		count += _putchar(*str++);
	return (count);
}

/**
 * handle_format - Handles the format specifier.
 * @format: Format string
 * @args: List of arguments
 * @i: Index of format string
 *
 * Return: Number of characters printed.
 */
int handle_format(const char *format, va_list args, int *i)
{
	int count = 0;

	switch (format[*i])
	{
		case 'c':
			count += print_char(args);
			break;
		case 's':
			count += print_string(args);
			break;
		case '%':
			count += _putchar('%');
			break;
		default:
			count += _putchar('%');
			count += _putchar(format[*i]);
			break;
	}
	return (count);
}
/**
 * _printf - Produces output according to a format
 * @format: A character string composed of zero or more directives
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += handle_format(format, args, &i);
		}
		else
		{
			count += _putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
