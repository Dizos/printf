#include "main.h"
#include <stdarg.h>

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

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				count += handle_char(va_arg(args, int));
			else if (format[i] == 's')
				count += handle_string(va_arg(args, char *));
			else if (format[i] == '%')
				count += handle_percent();
			else
			{
				count += _putchar('%');
				count += _putchar(format[i]);
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

/**
 * handle_char - Handles the %c specifier.
 * @c: The character to print.
 *
 * Return: The number of characters printed.
 */
int handle_char(char c)
{
	return (_putchar(c));
}

/**
 * handle_string - Handles the %s specifier
 * @str: The string to print.
 *
 * Return: The number of characters printed.
 */
int handle_string(char *str)
{
	int count = 0;

	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		count += _putchar(*str);
		str++;
	}
	return (count);
}

/**
 * handle_percent - Handles the %% specifier
 *
 * Return: The number of characters printed.
 */
int handle_percent(void)
{
	return (_putchar('%'));
}
