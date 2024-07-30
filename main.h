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
	char c;
	int (*f)(va_list va, char flags[]);
} types;

int _putchar(char c);
int _printf(const char *format, ...);
int t_char(va_list va, char flags[]);
int t_string(va_list va, char flags[]);
int print_number(va_list va, char flags[]);
int binary(va_list va, char flags[]);
int print_unsigned(va_list va, char flags[]);
int hexa(va_list va, char flags[]);
int HEXA(va_list va, char flags[]);
int octal(va_list va, char flags[]);
int print_S(va_list va, char flags[]);
int print_p(va_list va, char flags[]);
int print_unsigned(va_list va, char flags[]);

/*int handle_format(const char *format, va_list valist) */
/* void write_buffer(char *buffer, int *buffer_len); */


#endif /* MAIN_H */
