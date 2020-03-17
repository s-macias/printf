#include "holberton.h"
#include <stdarg.h>
#include <unistd.h>
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
 * _printf_string - the function printfstring
 *@tstring:char the pointer
 * Return: Always 0
 */
void _printf_string(char *tstring)
{
	int j = 0;

	do {
		_putchar(tstring[j]);
		j++;
	} while (tstring[j] != '\0');
}
/**
 * _printf - the function printf
 *@format:char the pointer
 * Return: Always 0
 */
int _printf(const char *format, ...)
{
	int i = 0, k = 0;
	char type;

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
				_printf_string(va_arg(list, char*));
				k++;
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
