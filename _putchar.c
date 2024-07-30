#include "main.h"

/**
 * _putchar - Writes a character to stdout
 * @c: Character to write
 * Return: On success 1, on error negative
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
