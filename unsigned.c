#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer.
 * @va: The unsigned int to print.
 *
 * Return: The number of characters printed.
 */
int print_unsigned(va_list va, int plus_flag, int space_flag, int hash_flag)
{
    unsigned int n = va_arg(va, unsigned int);
    int len = 0;
    int i;
    char buffer[20];

    (void)hash_flag;

    if (n == 0)
    {
        _putchar('0');
        return (1);
    }

    if (plus_flag)
    {
        _putchar('+');
        len++;
    }
    else if (space_flag)
    {
        _putchar(' ');
        len++;
    }

    while (n != 0)
    {
        buffer[len++] = (n % 10) + '0';
        n /= 10;
    }
    for (i = len - 1; i >= 0; i--)
        _putchar(buffer[i]);

    return (len);
}
