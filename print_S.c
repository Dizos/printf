#include "main.h"

/**
 * print_S - Prints a string and handles non-printable characters
 * @va: The string to print
 *
 * Return: The number of characters printed
 */
int print_S(va_list va, int plus_flag, int space_flag, int hash_flag, char length_modifier)
{
    char *s;
    int i, len = 0;

    (void)plus_flag;
    (void)space_flag;
    (void)hash_flag;
    (void)length_modifier;
    s = va_arg(va, char *);

    if (!s)
        s = "(null)";
    for (i = 0; s[i]; i++)
    {
        if (s[i] < 32 || s[i] >= 127)
        {
            len += _putchar('\\');
            len += _putchar('x');
            len += _putchar("0123456789ABCDEF"[(s[i] >> 4) & 0xF]);
            len += _putchar("0123456789ABCDEF"[s[i] & 0xF]);
        }
        else
        {
            len += _putchar(s[i]);
        }
    }
    return len;
}
