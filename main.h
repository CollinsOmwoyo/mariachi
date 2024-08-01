#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _print_string(char *str);
int _print_int(int n);
int _print_unsigned(unsigned int n);
int _print_oct(unsigned int n);
int _print_hex(unsigned int n);
int _print_HEX(unsigned int n);
int _print_pointer(void *p);
int _print_exc_string(char *str);
int _print_revs(char *str);
int _print_rot13(char *str);
int _print_bin(unsigned int n);

#endif

