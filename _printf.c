#include "main.h"

/**
 * _printf - Prints output according to a format.
 * @format: First argument
 *
 * Return: The number of characters printed(excluding null byte).
 */
int _printf(const char *format, ...)
{
	int i = 0, j, len = 0, count;
	va_list valist;
	types difftypes[] = {{'c', t_char}, {'s', t_string}, {'d', print_number},
		{'i', print_number}, {'b', binary}, {'u', print_unsigned},
		{'x', hexa}, {'X', HEXA}, {'o', octal}, {'S', print_S}, {'p', print_p},
		{'r', print_reversed}, {'R', print_rot13}
	};

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (format == '%')
		{
			format++;
			len += handle_conversion(&format, args, difftypes);
		}
		else
		{
			len += _putchar(*format);
			format+=;
		}
	}
	va_end(args);
	return (len);
}
