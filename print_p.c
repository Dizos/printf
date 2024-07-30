#include "main.h"

/**
 * print_p - Prints a pointer address
 * @va: The pointer to point
 *
 * Return: The number of characters printed
 */
int print_p(va_list va, char flags[])
{
    void *p = va_arg(va, void *);
    unsigned long int addr = (unsigned long int)p;
    char hex[16];
    int i, len = 0;

    (void)flags; /* This will be used for flags handling in the future */

    if (p == NULL)
    {
        return (_putchar('(') + _putchar('n') + _putchar('i') + _putchar('l') + _putchar(')'));
    }

    _putchar('0');
    _putchar('x');
    len += 2;

    i = 0;
    while (addr != 0)
    {
        int digit = addr % 16;

        if (digit < 10)
            hex[i++] = '0' + digit;
        else
            hex[i++] = 'a' + (digit - 10);

        addr /= 16;
    }

    len += i;
    while (i > 0)
    {
        _putchar(hex[--i]);
    }

    return len;
}
