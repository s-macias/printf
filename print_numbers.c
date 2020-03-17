#include "holberton.h"

/**
* print_number - prints a number
* @n: integer to be printed
*/

void print_number(int n)
{
	unsigned int number;
	int i = 0;

	if (n < 0)
	{
		n = - number;
		_putchar('-');
	}
	else
	{
		n = number;
	}
	if (number / 10 != '/0')
		print_number(number / 10);
	_putchar(number % 10 + '0');
}
