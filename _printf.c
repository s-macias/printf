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
 * print_numbers - prints a number
 * @n: integer to be printed
 * Return: integer
 */

int print_numbers(int n)
{
	unsigned int number;
	int i = 0;

	if (n < 0)
	{
		number = -n;
		i = i + _putchar('-');
	}
	else
	{
		number = n;
	}
	if (number / 10 != '\0')
		i = i + print_numbers(number / 10);
	i = i + _putchar(number % 10 + '0');
	return (i);
}

/**
 * print_unsigned - prints an unsigned integer
 * @number: unsigned integer to be printed
 * @mode: identifies base notation: 8, 10 or 16
 * Return: integer
 */

int print_unsigned(unsigned int number, int mode)
{
	int i = 0;

	if (number / mode != '\0')
		i = i + print_numbers(number / mode);
	i = i + _putchar(number % mode + '0');
	return (i);
}

/**
 * _printf_string - the function printfstring
 *@tstring:char the pointer
 * Return: Always 0
 */
int _printf_string(char *tstring)
{
	int j = 0;

	do {
		_putchar(tstring[j]);
		j++;
	} while (tstring[j] != '\0');
	return (j);
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
				k = k + _putchar((char)va_arg(list, int));
			if (type == 's')
				k = k + _printf_string(va_arg(list, char*));
			if (type == '%')
				k = k + _putchar('%');
			if (type == 'd' || type == 'i')
				k = k + print_numbers(va_arg(list, int));
			if (type == 'u')
				k = k + print_unsigned
					(va_arg(list, unsigned int), 10);
			if (type == 'o')
				k = k + print_unsigned
					(va_arg(list, unsigned int), 8);
			if (type == 'x' || type == 'X')
				k = k + print_unsigned
					(va_arg(list, unsigned int), 16);
			if (type != 'c' && type != 's' && type != '%'
			    && type != 'd' && type != 'i' && type != 'u'
			    && type != 'o' && type != 'x' && type != 'X')
				k = k + _putchar('%') + _putchar(type);
		}
		else
			k = k + _putchar(format[i]);
		i++;
	}
	return (k);
}
