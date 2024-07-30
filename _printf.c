#include "main.h"
#include <stdarg.h>

/**
 * _printf - Prints output according to a format.
 * @format: First argument
 *
 * Return: The number of characters printed(excluding null byte).
 */
int _printf(const char *format, ...)
{
	va_list valist;
	int i = 0, j, len = 0;

	types difftypes[] = {{'c', t_char}, {'s', t_string}, {'d', print_number},
		{'i', print_number}, {'b', binary}, {'u', print_unsigned},
		{'x', hexa}, {'X', HEXA}, {'o', octal}, {'S', print_S}, {'p', print_p}
};

char flags[3] = {0, 0, 0}; /* Flags array: flags[0] for '+', flags[1] for ' ', flags[2] for '#'*/

	va_start(valist, format);
    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            for (j = 0; j < 11; j++)
            {
                if (format[i] == difftypes[j].c)
                {
                    len += difftypes[j].f(valist, flags);
                    break;
                }
            }
        }
        else
        {
            _putchar(format[i]);
            len++;
        }
        i++;
    }
    va_end(valist);
    return len;
}
