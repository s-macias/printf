#ifndef _HOLBERTON_H
#define _HOLBERTON_H
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
int _printf(const char *format, ...);
int print_char(va_list argum);
int print_string(va_list argum);
int print_percent(char c);
int print_number(int numb);
int _putchar(char c);
#endif
