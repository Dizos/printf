#include "main.h"

/**
 * t_char - Prints a single character.
 * @va: The character to print
 *
 * Return: The number of characters printed
 */
int t_char(va_list va, char flags[])
{
    char c;

    (void)flags; /* This will be used for flags handling in the future */

    c = (char)va_arg(va, int);

    _putchar(c);

    return 1;
}

/**
 * t_string - Prints a string.
 * @va: Pointer to string
 *
 * Return: The number of strings pointed
 */
int t_string(va_list va, char flags[])
{
    char *s;
    int i, len;

    (void)flags; /* This will be used for flags handling in the future */

    s = va_arg(va, char *);

    if (s == NULL)
        s = "(null)";

    len = 0;
    for (i = 0; s[i] != '\0'; i++)
    {
        _putchar(s[i]);
        len++;
    }

    return len;
}
/**
 * print_number - Prints an integer
 * @va: The integer to print
 *
 * Return: The number of characters printed.
 */
int print_number(va_list va, char flags[])
{
    int n = va_arg(va, int);
    int len = 0;
    int num = n;

    /* Check for '+' flag */
    if (flags[0] == 1 && n >= 0)
    {
        _putchar('+');
        len++;
    }

    /* Check for ' ' flag */
    else if (flags[1] == 1 && n >= 0)
    {
        _putchar(' ');
        len++;
    }

    /* Handle negative numbers */
    if (n < 0)
    {
        _putchar('-');
        len++;
        num = -n;
    }

    /* Calculate the length and print the number */
    if (num == 0)
    {
        _putchar('0');
        len++;
    }
    else
    {
        char str[10];
        int i = 0;
        
        while (num != 0)
        {
            str[i++] = (num % 10) + '0';
            num /= 10;
        }
        
        len += i;
        while (i > 0)
        {
            _putchar(str[--i]);
        }
    }
    return len;
}
/**
 * binary - Prints an unsigned int in binary.
 * @va: The unsigned int to print.
 *
 * Return: The number of characters printed.
 */
int binary(va_list va, char flags[])
{
    unsigned int n;
    int len;
    char bin[32];
    int i;

    (void)flags; /* This will be used for flags handling in the future */

    n = va_arg(va, unsigned int);

    if (n == 0)
    {
        _putchar('0');
        return 1;
    }

    len = 0;
    for (i = 0; n > 0; i++)
    {
        bin[i] = (n % 2) + '0';
        n /= 2;
    }
    i--;

    for (; i >= 0; i--)
    {
        _putchar(bin[i]);
        len++;
    }

    return len;
}
