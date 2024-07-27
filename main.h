#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib>

/* Task 0 _printf function */
int _printf(const char *format, ...);
int _putchar(char c);


/* Helper functions to help function print char, string and pecentage */
int print_char(va_list args);
int print_string(va_list args);

#endif /* MAIN_H */
