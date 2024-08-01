#include "main.h"

/**
 * octal - prints an unsigned integer in octal.
 * @va: The unsigned int to print.
 * @flags: The flags for formatting
 * @width: The width for formatting
 * @precision: The prescision for formatting
 * @length: The length modifier
 * Return: The number of characters printed.
 */
int octal(va_list va, int flags, int width, int precision, int length)
{
	unsigned int n = (length == 1) ? va_arg(va, unsigned long) :
		(length == 2) ? (unsigned short)va_arg(va, unsigned int) :
		va_arg(va, unsigned int);
	int len = 0;
	char buffer[20];
	int i;

	if (n == 0)
	{
		buffer[len++] = '0'; }
	else
	{
		while (n != 0)
		{
			buffer[len++] = (n % 8) + '0';
			n /= 8; }}
	while (len < precision)
		buffer[len++] = '0';
	if ((flags & (1 << 2)) && n != 0)
		buffer[len++] = '0';
	if (!(flags & (1 << 4)))
	{
		while (len < width)
			buffer[len++] = (flags & (1 << 3)) ? '0' : ' '; }
	for (i = len - 1; i >= 0; i--)
		_putchar(buffer[i]);
	if (flags & (1 << 4))
	{
		while (len < width)
		{
			_putchar(' ');
			len++; }}
	return (len);
}
