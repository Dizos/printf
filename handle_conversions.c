#include "main.h"

/**
 * handle_conversion - Handles the conversion specifiers.
 * @format: The format string.
 * @args: The argument list.
 * @difftypes: Array of conversion specifiers and their handlers.
 *
 * Return: The number of characters printed.
 */
int handle_conversion(const char **format, va_list args,
		types *difftypes)
{
	int len = 0, flags, width, precision, length, i;

	flags = parse_flags(format);
	with = parse_width(format, args);
	precision = parse_precision(format, args);
	length = parse_length(format);

	for (i = 0; i < 13; i++)
	{
		if (**format == difftypes[i].t)
		{
			len += difftypes[i].f(args, flags, width, precision, length);
			(*format)++;
			return (len);
		}
	}
	if (**format)
	{
		len += _putchar('%');
		len += _putchar(**format);
		(*format)++;
	}
	return (len);
}
