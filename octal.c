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
int octal(va_list va, int plus_flag, int space_flag, int hash_flag, char length_modifier)
{
    unsigned long int n;
    int len = 0;
    char buffer[22];
    int i = 0;

    (void)plus_flag;
    (void)space_flag;
    (void)hash_flag;
    (void)length_modifier;
    n = va_arg(va, unsigned int);

    if (n == 0)
        return _putchar('0');

    while (n)
    {
        buffer[i++] = (n % 8) + '0';
        n /= 8;
    }

    while (i--)
        len += _putchar(buffer[i]);

    return len;
}
