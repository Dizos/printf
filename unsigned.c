#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer.
 * @va: The unsigned int to print.
 *
 * Return: The number of characters printed.
 */
int print_unsigned(va_list va, int plus_flag, int space_flag, int hash_flag, char length_modifier)
{
    unsigned long int n;
    int len = 0;

    (void)plus_flag;
    (void)space_flag;
    (void)hash_flag;
    (void)length_modifier;
    n = va_arg(va, unsigned int);

    /* Print the unsigned number recursively */
    if (n / 10)
    {
        len += print_unsigned_helper(n / 10);
    }
    len += _putchar((n % 10) + '0');

    return len;
}

int print_unsigned_helper(unsigned long int n)
{
    int len = 0;
    if (n / 10)
    {
        len += print_unsigned_helper(n / 10);
    }
    len += _putchar((n % 10) + '0');
    return len;
}
