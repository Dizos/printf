#include "main.h"

/**
 * octal - prints an unsigned integer in octal.
 * @va: The unsigned int to print.
 * @plus_flag: Unused
 * @space_flag: Unused
 * @hash_flag: If set, print '0' prefix
 *
 * Return: The number of characters printed.
 */
int octal(va_list va, int plus_flag, int space_flag, int hash_flag)
{
    unsigned int n = va_arg(va, unsigned int);
    int len = 0;
    char buffer[20];
    int i;

    (void)plus_flag;
    (void)space_flag;

    if (n == 0)
    {
        _putchar('0');
        return (1);
    }

    if (hash_flag)
    {
        _putchar('0');
        len++;
    }

    while (n != 0)
    {
        buffer[len++] = (n % 8) + '0';
        n /= 8;
    }
    for (i = len - 1; i >= 0; i--)
        _putchar(buffer[i]);

    return (len);
}
