#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: Characternstring composed of zero or more directives.
 * Return: The number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	char ch;
	char *str;

	if (!format)
		return (-1);

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					ch = (char)va_arg(args, int);
					write(1, &ch, 1);
					count++;
					break;
				case 's':
					str = va_arg(args, char *);

					if (!str)
						str = "(null)";
					while (*str)
					{
						write(1, str++, 1);
						count++;
					}
					break;
				case '%':
					write(1, "%", 1);
					count++;
					break;
				default:
					write(1, &format[i - 1], 1);
					write(1, &format[i], 1);
					count += 2;
					break;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
