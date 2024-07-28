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
	int (*f)(va_list va);
} types;

int _putchar(char c);
int _printf(const char *format, ...);
int t_char(va_list va);
int t_string(va_list va);
int print_number(va_list va);







#endif /* MAIN_H */
