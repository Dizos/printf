#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int _putchar(char c);

/* Helper functions to print chars, strings and percent */
int handle_char(char c);
int handle_string(char *str);
int handle_percent(void);

#endif /* MAIN_H */
