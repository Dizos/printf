#include "main.h"

/**
 * print_char - Prints a character.
 * @args: Argument list containing the character
 * Return: Number of character.
 */
int print_char(va_list args)
{
	char c = (char) va_arg(args, int);

	return (_putchar(c));
}

/**
 * print_string - Printss a string
 * @args: Argument list containing the string.
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	int count = 0;
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";

	while (*str)
	{
		count += _putchar(*str);
		str++;
	}
	return (count);
}

/**
 * _printf - Produces output according to a format.
 * @format: Character string containing the format.
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i = 0;

	va_start(args, format);

	if (!format)
		return (-1);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					count += print_char(args);
					break;
				case 's':
					count += print_string(args);
					break;
				case '%':
					count += _putchar('%');
					count += _putchar(format[i]);
					break;
			}
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
