#include "main.h"

/**
 * print_S - Prints a string and handles non-printable characters
 * @va: The string to print
 *
 * Return: The number of characters printed
 */
int print_S(va_list va, int plus_flag, int space_flag, int hash_flag)
{
    char *s = va_arg(va, char *);
    int i, len = 0;
    char hex[3];

    (void)plus_flag;
    (void)space_flag;
    (void)hash_flag;

    if (s == NULL)
        s = "(null)";

    for (i = 0; s[i] != '\0'; i++)
    {
        if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
        {
            _putchar('\\');
            _putchar('x');
            sprintf(hex, "%02X", (unsigned char)s[i]);
            _putchar(hex[0]);
            _putchar(hex[1]);
            len += 4;
        }
        else
        {
            _putchar(s[i]);
            len++;
        }
    }
    return (len);
}
