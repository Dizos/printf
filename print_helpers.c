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
int t_char(va_list va, int plus_flag, int space_flag, int hash_flag)
{
    int c;

    (void)plus_flag;
    (void)space_flag;
    (void)hash_flag;

    c = va_arg(va, int);
    _putchar(c);
    return (1);
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
int t_string(va_list va, int plus_flag, int space_flag, int hash_flag)
{
    int i, j;
    char n[] = "(null)";
    char *s = va_arg(va, char *);

    (void)plus_flag;
    (void)space_flag;
    (void)hash_flag;

    if (s == NULL)
    {
        for (i = 0; n[i] != '\0'; i++)
            _putchar(n[i]);
        return (6);
    }
    for (j = 0; s[j] != '\0'; j++)
        _putchar(s[j]);
    return (j);
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
int print_number(va_list va, int plus_flag, int space_flag, int hash_flag)
{
    int n = va_arg(va, int);
    int len = 0;
    unsigned int abs;

    (void)hash_flag;

    if (n < 0)
    {
        _putchar('-');
        abs = -n;
        len++;
    } 
    else 
    {
        abs = n;
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
    }

    len += print_unsigned_helper(abs);
    return (len);
}

/**
 * print_unsigned_helper - Helper function to print an unsigned integer
 * @n: The unsigned integer to print
 *
 * Return: The number of characters printed.
 */
int print_unsigned_helper(unsigned int n)
{
    int len = 0;
    int i;
    char buffer[20];

    if (n == 0)
    {
        _putchar('0');
        return (1);
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

/**
 * binary - Prints an unsigned int in binary.
 * @va: The unsigned int to print.
 * @plus_flag: Unused
 * @space_flag: Unused
 * @hash_flag: Unused
 *
 * Return: The number of characters printed.
 */
int binary(va_list va, int plus_flag, int space_flag, int hash_flag)
{
    unsigned int c;
    int i, k;
    int arr[100];

    (void)plus_flag;
    (void)space_flag;
    (void)hash_flag;

    c = va_arg(va, int);
    i = 0;

    if (c == 0)
    {
        _putchar('0');
        return (1);
    }
    while (c > 0)
    {
        arr[i] = c % 2;
        c = c / 2;
        i++;
    }
    for (k = i - 1; k >= 0; k--)
        _putchar(arr[k] + '0');
    return (i);
}
