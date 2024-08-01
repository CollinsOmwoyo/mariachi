#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to print.
 * Return: The number of characters written.
 */
int _putchar(char c)
{
return write(1, &c, 1);
}

/**
 * _print_unsigned - Prints an unsigned integer.
 * @n: The unsigned integer to print.
 * Return: The number of characters printed.
 */
int _print_unsigned(unsigned int n)
{
int count = 0;
if (n / 10)
count += _print_unsigned(n / 10);
count += _putchar((n % 10) + '0');
return count;
}

/**
 * _print_oct - Prints an unsigned integer in octal format.
 * @n: The unsigned integer to print.
 * Return: The number of characters printed.
 */
int _print_oct(unsigned int n)
{
int count = 0;
if (n / 8)
count += _print_oct(n / 8);
count += _putchar((n % 8) + '0');
return count;
}

/**
 * _print_hex - Prints an unsigned integer in hexadecimal format (lowercase).
 * @n: The unsigned integer to print.
 * Return: The number of characters printed.
 */
int _print_hex(unsigned int n)
{
int count = 0;
if (n / 16)
count += _print_hex(n / 16);
count += _putchar("0123456789abcdef"[n % 16]);
return count;
}

/**
 * _print_HEX - Prints an unsigned integer in hexadecimal format (uppercase).
 * @n: The unsigned integer to print.
 * Return: The number of characters printed.
 */
int _print_HEX(unsigned int n)
{
int count = 0;
if (n / 16)
count += _print_HEX(n / 16);
count += _putchar("0123456789ABCDEF"[n % 16]);
return count;
}

/**
 * _print_pointer - Prints a pointer value in hexadecimal format.
 * @p: The pointer to print.
 * Return: The number of characters printed.
 */
int _print_pointer(void *p)
{
unsigned long addr = (unsigned long)p;
int count = 0;
count += _putchar('0');
count += _putchar('x');
count += _print_HEX(addr >> 4);
count += _print_hex(addr & 0xF);
return count;
}

/**
 * _print_exc_string - Prints a string with non-printable characters escaped.
 * @str: The string to print.
 * Return: The number of characters printed.
 */
int _print_exc_string(char *str)
{
int count = 0;
while (*str)
{
if (*str < 32 || *str >= 127)
{
count += _putchar('\\');
count += _putchar('x');
count += _putchar("0123456789ABCDEF[(*str >> 4) & 0xF]");
count += _putchar("0123456789ABCDEF[*str & 0xF]");
}
else
{
count += _putchar(*str);
}
str++;
}
return count;
}

/**
 * _print_revs - Prints a string in reverse.
 * @str: The string to print.
 * Return: The number of characters printed.
 */
int _print_revs(char *str)
{
int count = 0;
int length = 0;
char *start = str;
while (*str++)
length++;
str--;
while (length--)
{
count += _putchar(*str--);
}
return count;
}

/**
 * _print_rot13 - Prints a string encoded in ROT13.
 * @str: The string to print.
 * Return: The number of characters printed.
 */
int _print_rot13(char *str)
{
int count = 0;
char c;
while (*str)
{
if ((*str >= 'A' && *str <= 'Z'))
c = ((*str - 'A' + 13) % 26) + 'A';
else if ((*str >= 'a' && *str <= 'z'))
c = ((*str - 'a' + 13) % 26) + 'a';
else
c = *str;
count += _putchar(c);
str++;
}
return count;
}

/**
 * _printf - Our custom printf function.
 * @format: Format string.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
va_list args;
int i = 0, count = 0;
char *str;
unsigned int num;

if (format == NULL)
return (-1);

va_start(args, format);
    
while (format[i])
{
if (format[i] == '%' && format[i + 1])
{
i++;
switch (format[i])
{
case 'c':
count += _putchar(va_arg(args, int));
break;
case 's':
count += _print_string(va_arg(args, char *));
break;
case '%':
count += _putchar('%');
break;
case 'd':
case 'i':
count += _print_int(va_arg(args, int));
break;
case 'u':
count += _print_unsigned(va_arg(args, unsigned int));
break;
case 'o':
count += _print_oct(va_arg(args, unsigned int));
break;
case 'x':
count += _print_hex(va_arg(args, unsigned int));
break;
case 'X':
count += _print_HEX(va_arg(args, unsigned int));
break;
case 'p':
count += _print_pointer(va_arg(args, void *));
break;
case 'S':
count += _print_exc_string(va_arg(args, char *));
break;
case 'b':
count += _print_bin(va_arg(args, unsigned int));
break;
case 'r':
count += _print_revs(va_arg(args, char *));
break;
case 'R':
count += _print_rot13(va_arg(args, char *));
break;
default:
count += _putchar('%');
count += _putchar(format[i]);
}
}
else
{
count += _putchar(format[i]);
}
i++;
}

va_end(args);
return (count);
}
