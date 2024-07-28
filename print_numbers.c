#include "main.h"
#include <unistd.h>

/**
 * print_number - Prints an integer
 * @n: The integer to print
 *
 * Return: Number of characters printed
 */
int print_number(int n)
{
    int count = 0;
    char buffer[12]; /* Buffer to hold the largest integer value including negative sign */
    int i = 0, j;
    unsigned int num;

    if (n < 0)
    {
        write(1, "-", 1);
        count++;
        num = -n;
    }
    else
    {
        num = n;
    }

    if (num == 0)
    {
        write(1, "0", 1);
        return (1);
    }

    while (num > 0)
    {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    }

    for (j = i - 1; j >= 0; j--)
    {
        write(1, &buffer[j], 1);
        count++;
    }

    return (count);
}
