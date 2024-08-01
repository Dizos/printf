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
int convert_to_hex(unsigned int n, char buffer[], char base_char);
void handle_padding(char buffer[], int *len, int flags, int width,
		int precision);
int handle_null_pointer(char buffer[]);
int convert_ptr_to_hex(unsigned long int decimal, char hexa[]);
int handle_non_printable_char(unsigned char c);
int apply_padding(int len, int width, int flags);
int apply_unsigned_padding(int len, int width, int flags, int zero_pad);
int apply_unsigned_precision(int len, int precision);
int get_digit_count(unsigned int num);
void print_digit(unsigned int num);
void handle_sign_and_padding(int n, int *len, int flags, int width,
		int num_digits);
/* int print_rot13(va_list args); */
/* int print_reversed(va_list args); */

int parse_flags(const char **format);
int parse_width(const char **format, va_list args);
int parse_precision(const char **format, va_list args);
int parse_lenth(const char **format);
int handle_conversion(const char **format, va_list args, types *difftypes);

#endif /* MAIN_H */
