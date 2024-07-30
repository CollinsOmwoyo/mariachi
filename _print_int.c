#include "main.h"

/**
 * _print_int - Prints an integer to stdout
 * @n: Integer to print
 * Return: Number of characters printed
 */
int _print_int(int n)
{
int count = 0;
unsigned int num;

if (n < 0)
{
count += _putchar('-');
num = -n;
}
else
{
num = n;
}
if (num / 10)
{
count += _print_int(num / 10);
}
count += _putchar((num % 10) + '0');

return (count);
}
