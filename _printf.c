#include <stdarg.h>
#include <stddef.h>
#include "main.h"

int _printf(const char *format, ...)
{
    int i = 0, j, len = 0, count, plus_flag = 0, space_flag = 0, hash_flag = 0;
    char length_modifier = 0;
    va_list valist;

    types difftypes[] = {
        {'c', t_char}, {'s', t_string}, {'d', print_number}, {'i', print_number},
        {'b', binary}, {'u', print_unsigned}, {'x', hexa}, {'X', HEXA},
        {'o', octal}, {'S', print_S}, {'p', print_p}
    };

    if (format == NULL || (format[0] == '%' && format[1] == 0))
        return (-1);

    va_start(valist, format);

    while (format != NULL && format[i])
    {
        if (format[i] != '%')
            len += _putchar(format[i]);
        else
        {
            i++;
            if (format[i] == '%')
            {
                len += _putchar('%');
            }
            else
            {
                plus_flag = space_flag = hash_flag = 0;
                length_modifier = 0;

                if (format[i] == '+')
                {
                    plus_flag = 1;
                    i++;
                }
                if (format[i] == ' ')
                {
                    space_flag = 1;
                    i++;
                }
                if (format[i] == '#')
                {
                    hash_flag = 1;
                    i++;
                }
                if (format[i] == 'l' || format[i] == 'h')
                {
                    length_modifier = format[i];
                    i++;
                }

                j = 0;
                count = 0;
                while (j < 11)
                {
                    if (format[i] == difftypes[j].t)
                    {
                        len += difftypes[j].f(valist, plus_flag, space_flag, hash_flag, length_modifier);
                        count = 1;
                        break;
                    }
                    j++;
                }

                if (!count)
                {
                    len += _putchar('%');
                    len += _putchar(format[i]);
                }
            }
        }
        i++;
    }

    va_end(valist);
    return (len);
}
