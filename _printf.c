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
 * _putchar - prints char
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
		}
		else
			k = k + _putchar(format[i]);
		i++;
	}
	return (k);
}
