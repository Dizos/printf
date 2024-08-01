#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/**
 * struct types_arguments - struct op
 *
 * @t: The operator
 * @f: The function associated
 */
typedef struct types_arguments
{
	char t;
	int (*f)(va_list va, int flags, int width, int precision, int length);
} types;

int _putchar(char c);
int _printf(const char *format, ...);
int t_char(va_list va, int flags, int width, int precision, int length);
int t_string(va_list va, int flags, int width, int precision, int length);
int print_number(va_list va, int flags, int width, int precision, int length);
int binary(va_list va, int flags, int width, int precision, int length);
int hexa(va_list va, int flags, int width, int precision, int length);
int HEXA(va_list va, int flags, int width, int precision, int length);
int octal(va_list va, int flags, int width, int precision, int length);
int print_unsigned(va_list va, int flags, int width, int precision,
		int length);
int print_S(va_list va, int flags, int width, int precision, int length);
int print_p(va_list va, int flags, int width, int precision, int length);
int print_reversed(va_list, int flags, int width, int precision, int length);
int print_rot13(va_list va, int flags, int width, int precision, int length);


int parse_flags(const char **format);
int parse_width(const char **format, va_list args);
int parse_precision(const char **format, va_list args);
int parse_lenth(const char **format);
int handle_conversion(const char **format, va list args, types *difftypes);

#endif /* MAIN_H */
