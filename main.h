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
    int (*f)(va_list va, int plus_flag, int space_flag, int hash_flag);
} types;

int _putchar(char c);
int _printf(const char *format, ...);
int t_char(va_list va, int plus_flag, int space_flag, int hash_flag);
int t_string(va_list va, int plus_flag, int space_flag, int hash_flag);
int print_number(va_list va, int plus_flag, int space_flag, int hash_flag);
int binary(va_list va, int plus_flag, int space_flag, int hash_flag);
int hexa(va_list va, int plus_flag, int space_flag, int hash_flag);
int HEXA(va_list va, int plus_flag, int space_flag, int hash_flag);
int octal(va_list va, int plus_flag, int space_flag, int hash_flag);
int print_unsigned(va_list va, int plus_flag, int space_flag, int hash_flag);
int print_S(va_list va, int plus_flag, int space_flag, int hash_flag);
int print_p(va_list va, int plus_flag, int space_flag, int hash_flag);
int print_unsigned_helper(unsigned int n);

#endif /* MAIN_H */
