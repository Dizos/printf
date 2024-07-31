#include "main.h"

/**
 * print_p - Prints a pointer address
 * @va: The pointer to point
 * @plus_flag: Unused
 * @space_flag: Unused
 * @hash_flag: Unused
 *
 * Return: The number of characters printed
 */
int print_p(va_list va, int plus_flag, int space_flag, int hash_flag, char length_modifier)
{
    void *ptr;
    unsigned long int addr;
    int len = 0;

    (void)plus_flag;
    (void)space_flag;
    (void)hash_flag;
    (void)length_modifier;
    ptr = va_arg(va, void *);
    addr = (unsigned long int)ptr;

    len += _putchar('0');
    len += _putchar('x');
    /* Print the address in hexadecimal*/
    if (addr == 0)
        len += _putchar('0');
    else
    {
        char hex_digits[] = "0123456789abcdef";
        char buffer[16];
        int i = 0;
        while (addr)
        {
            buffer[i++] = hex_digits[addr % 16];
            addr /= 16;
        }
        while (i--)
            len += _putchar(buffer[i]);
    }

    return len;
}
