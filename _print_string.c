#include "main.h"

/**
 * _print_string - Prints a string to stdout
 * @str: String to print
 * Return: Number of characters printed
 */
int _print_string(char *str)
{
int count = 0;

if (str == NULL)
str = "(null)";
while (*str)
{
count += _putchar(*str);
str++;
}
return (count);
}
