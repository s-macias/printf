In this project, we'll learn to work collaboratively using GitHub to create a
printf function.

We are allowed to use these functions or macros only:
write (man 2 write)
malloc (man 3 malloc)
free (man 3 free)
va_start (man 3 va_start)
va_end (man 3 va_end)
va_copy (man 3 va_copy)
va_arg (man 3 va_arg)

Task 0 - a function that produces output according to a format.
Prototype: int _printf(const char *format, ...);
Returns: the number of characters printed.
write output to stdout, the standard output stream
format is a character string. You need to handle the following conversion
specifiers:
c, s, %

Task 1 - Handle the following conversion specifiers: d,i

Task 2 -Create a man page for your function.

File: man_3_printf

The function requires four different files:

Holberton.h- header file
_printf.c this file contains all the functions for the 5 different specifiers
we can accept in this function and the _printf function that will choose the
right format according to the specifier given.

Example:
_printf("hello", %s)

Output: hello
Return: 5