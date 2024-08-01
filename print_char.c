#include "main.h"

/**
 * t_char - Prints a single character.
 * @va: The character to print
 * @flags: The flags for formatting
 * @width: The width for formating
 * @precision: The precision for formatting
 * @length: The length modifier
 *
 * Return: The number of characters printed
 */
int t_char(va_list va, int flags, int width, int precision, int length)
{
	int c = va_arg(va, int);
	int total_len = 0;
	char pad_char = (flags & (1 << 3)) ? '0' : ' ';

	if (!(flags & (1 << 4)))
	{
		while (width > 1)
		{
			_putchar(pad_char);
			total_len++;
			width--; }}
	_putchar(c);
	total_len++;

	if (flags & (1 << 4))
	{
		while (width > 1)
		{
			_putchar(' ');
			total_len++;
			width--; }}
	return (total_len);
}
