#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);

/* Helper functions to print chars, strings and percent */
int print_char(va_list args);
int print_string(va_list args);
int handle_format(const char *format, va_list args, int *i);

#endif /* MAIN_H */
