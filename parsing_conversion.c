#include "main.h"

/**
 * parse_flags - parses the flag characters.
 * @format: The format string.
 *
 * Return: The parsed flags.
 */
int parse_flags(const char **format)
	{
    int flags = 0;

    while (**format == '+' || **format == ' ' || **format == '#' || **format == '0' || **format == '-')
    {
        if (**format == '+')
            flags |= 1 << 0;  /* Plus flag*/
        else if (**format == ' ')
            flags |= 1 << 1;  /* Space flag*/
        else if (**format == '#')
            flags |= 1 << 2;  /* Hash flag*/
        else if (**format == '0')
            flags |= 1 << 3;  /* Zero flag*/
        else if (**format == '-')
            flags |= 1 << 4;  /* Minus flag*/
        (*format)++;
    }
    return flags;
}

/**
 * parse_width - Parses the width specifier
 * @format: The format string.
 * @args: The argument list.
 *
 * Return: The parsed width.
 */
int parse_width(const char **format, va_list args)
	{
    int width = 0;

    if (**format == '*')
    {
        width = va_arg(args, int);
        (*format)++;
    }
    else
    {
        while (**format >= '0' && **format <= '9')
        {
            width = width * 10 + (**format - '0');
            (*format)++;
        }
    }
    return width;
}

/**
 * parse_precision - Parses the precision specifier
 * @format: The format string.
 * @args: The argument list.
 *
 * Return: The parsed precision.
 */
int parse_precision(const char **format, va_list args)
	int parse_precision(const char **format, va_list args)
{
    int precision = -1;

    if (**format == '.')
    {
        (*format)++;
        if (**format == '*')
        {
            precision = va_arg(args, int);
            (*format)++;
        }
        else
        {
            precision = 0;
            while (**format >= '0' && **format <= '9')
            {
                precision = precision * 10 + (**format - '0');
                (*format)++;
            }
        }
    }
    return precision;
}

/**
 * parse_length - Parses the lenth modifier.
 * @format: The format string
 *
 * Return: The parsed length
 */
int parse_length(const char **format)
	{
    int length = 0;

    if (**format == 'l')
    {
        length = 1;
        (*format)++;
    }
    else if (**format == 'h')
    {
        length = 2;
        (*format)++;
    }
    return length;
}

