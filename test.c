#include "holberton.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _printf - the function printf
 *@format:char the pointer
 * Return: Always 0
 */
int _printf(const char *format, ...)
{
	int i = 0;
	char type;
	int j;
	int k = 0;
	char *tstring;

	va_list list;

	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			type = format[++i];
			if (type == 'c')
			{
				_putchar((char)va_arg(list, int));
				k++;
			}
			if (type == 's')
			{
				tstring = va_arg(list, char*);
				j = 0;
				do {
					_putchar(tstring[j]);
					j++;
					k++;
				}

				while (tstring[j] != '\0');
			}
			if (type == '%')
			{
				_putchar('%');
				k++;
			}
		}
		else
		{
			_putchar(format[i]);
			k++;
		}

	i++;
	}
	return (k);
}
