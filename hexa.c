#include "main.h"

/**
 * hexa - Prints an unsigned integer in hexadecimal(lowercase)
 * @va: The unsigned int to print.
 * @plus_flag: Unused
 * @space_flag: Unused
 * @hash_flag: If set, print '0x' prefix
 *
 * Return: The number of characters printed.
 */
int hexa(va_list va, int plus_flag, int space_flag, int hash_flag, char length_modifier)
{
    unsigned long int n;
    int len = 0;
    char buffer[16];
    int i = 0;
    char hex_digits[] = "0123456789abcdef";

    (void)plus_flag;
    (void)space_flag;
    (void)hash_flag;
    (void)length_modifier;
    n = va_arg(va, unsigned int);

    if (n == 0)
        return _putchar('0');

    while (n)
    {
        buffer[i++] = hex_digits[n % 16];
        n /= 16;
    }

    while (i--)
        len += _putchar(buffer[i]);

    return len;
}

/**
 * HEXA - prints an unsigned inteeger in hexadecimal(uppercase)
 * @va: The unsigned int to print
 * @plus_flag: Unused
 * @space_flag: Unused
 * @hash_flag: If set, print '0X' prefix
 *
 * Return: The number of characters printed.
 */
int HEXA(va_list va, int plus_flag, int space_flag, int hash_flag, char length_modifier)
{
    unsigned long int n;
    int len = 0;
    char buffer[16];
    int i = 0;
    char hex_digits[] = "0123456789ABCDEF";

    (void)plus_flag;
    (void)space_flag;
    (void)hash_flag;
    (void)length_modifier;
    n = va_arg(va, unsigned int);

    if (n == 0)
        return _putchar('0');

    while (n)
    {
        buffer[i++] = hex_digits[n % 16];
        n /= 16;
    }

    while (i--)
        len += _putchar(buffer[i]);

    return len;
}
