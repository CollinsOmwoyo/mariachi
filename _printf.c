#include "main.h"

/**
 * _printf - Our custom printf function
 * @format: Format string
 * Return: Number of characters
 */
int _printf(const char *format, ...)
{
/*We will initialize a variable argument list*/
va_list args;
int i = 0, count = 0;
/*Here we start processing the variable arguments*/
va_start(args, format);
while (format && format[i])
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
/* We will then clean up the variable argument list*/
va_end(args);
return (count);
}
