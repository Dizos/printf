#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer.
 * @va: The unsigned int to print.
 *
 * Return: The number of characters printed.
 */
int print_unsigned(va_list va, char flags[])
{
    unsigned int n = va_arg(va, unsigned int);
    unsigned int num = n;
    char str[10];
    int i = 0, len = 0;

    (void)flags;  /* This line can be removed if you are planning to use the flags*/

    /* Handle 0 separately */
    if (num == 0)
    {
        _putchar('0');
        return 1;
    }

    /* Convert number to string */
    while (num != 0)
    {
        str[i++] = (num % 10) + '0';
        num /= 10;
    }

    /* Print the number */
    len = i;
    while (i > 0)
    {
        _putchar(str[--i]);
    }

    return len;
}
