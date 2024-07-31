#include "main.h"

/**
 * t_char - Prints a single character.
 * @va: The character to print
 * @plus_flag: Unused
 * @space_flag: Unused
 * @hash_flag: Unused
 *
 * Return: The number of characters printed
 */
int t_char(va_list va, int plus_flag, int space_flag, int hash_flag, char length_modifier)
{
    int c;

    (void)plus_flag;
    (void)space_flag;
    (void)hash_flag;
    (void)length_modifier;
    c = va_arg(va, int);
    return _putchar(c);
}

/**
 * t_string - Prints a string.
 * @va: Pointer to string
 * @plus_flag: Unused
 * @space_flag: Unused
 * @hash_flag: Unused
 *
 * Return: The number of strings pointed
 */
int t_string(va_list va, int plus_flag, int space_flag, int hash_flag, char length_modifier)
{
    char *s;
    int i, j = 0;

    (void)plus_flag;
    (void)space_flag;
    (void)hash_flag;
    (void)length_modifier;
    s = va_arg(va, char *);

    if (!s)
        s = "(null)";
    for (i = 0; s[i]; i++)
        j += _putchar(s[i]);
    return j;
}

/**
 * print_number - Prints an integer
 * @va: The integer to print
 * @plus_flag: If set, prepend '+' to positive numbers
 * @space_flag: If set, prepend a space to positive numbers
 * @hash_flag: Unused
 *
 * Return: The number of characters printed.
 */
int print_number_helper(unsigned long int n);  /* Declaration*/
int print_unsigned_helper(unsigned long int n);  /* Declaration*/

int print_number(va_list va, int plus_flag, int space_flag, int hash_flag, char length_modifier)
{
    long int n;
    unsigned long int abs;
    int len = 0;

    (void)hash_flag;
    (void)length_modifier;
    n = va_arg(va, int);

    if (plus_flag && n >= 0)
        len += _putchar('+');
    else if (space_flag && n >= 0)
        len += _putchar(' ');

    if (n < 0)
    {
        len += _putchar('-');
        abs = -n;
    }
    else
    {
        abs = n;
    }

    if (abs / 10)
    {
        len += print_number_helper(abs / 10);
    }
    len += _putchar((abs % 10) + '0');

    return len;
}
/**
 * print_number_helper
 *
 * */

int print_number_helper(unsigned long int n)
{
    int len = 0;
    if (n / 10)
    {
        len += print_number_helper(n / 10);
    }
    len += _putchar((n % 10) + '0');
    return len;
}

/**
 * binary - Prints an unsigned int in binary.
 * @va: The unsigned int to print.
 * @plus_flag: Unused
 * @space_flag: Unused
 * @hash_flag: Unused
 *
 * Return: The number of characters printed.
 */
int binary(va_list va, int plus_flag, int space_flag, int hash_flag, char length_modifier)
{
    unsigned int c;
    int len = 0;
    char buffer[32];
    int i = 0;

    (void)plus_flag;
    (void)space_flag;
    (void)hash_flag;
    (void)length_modifier;
    c = va_arg(va, unsigned int);

    if (c == 0)
        return _putchar('0');

    while (c)
    {
        buffer[i++] = (c % 2) + '0';
        c /= 2;
    }

    while (i--)
        len += _putchar(buffer[i]);

    return len;
}
