#include "main.h"
#include <stdarg.h>
#include <stdio.h>

int print_S(va_list va, char flags[])
{
    char *s;
    int i, len = 0;
    char hex[3];

    (void)flags; /* This will be used for flags handling in the future */
    
    s = va_arg(va, char *);

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
    return len;
}
