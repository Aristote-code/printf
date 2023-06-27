/*
 * File: _printf.c
 * Auth: Gahima Aristote
 */
#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _strlen(const char *str);

/**
 * _strlen - Counts the length of a string
 * @str: The string
 *
 * Return: The length of the string.
 */
int _strlen(const char *str)
{
int i = 0;
while (str[i] != '\0')
i++;

return (i);
}

/**
 * _printf - Prints formatted output
 * @format: Character string to output
 *
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
int i = 0;
int fmt_len = _strlen(format);
char c;
char *s;
int count = 0;
int j = 0;

va_list args;
va_start(args, format);

for (i = 0; i < fmt_len; i++)
{
if (format[i] == '%')
{
i++;
if (format[i] == 'c')
{
c = va_arg(args, int);
printchar(c);
count++;
}
else if (format[i] == 's')
{
s = va_arg(args, char *);
j = 0;
while (s[j] != '\0')
{
printchar(s[j]);
j++;
count++;
}
}
else if (format[i] == '%')
{
printchar('%');
count++;
}
else
{
printchar('%');
printchar(format[i]);
count += 2;
}
}
else
{
printchar(format[i]);
count++;
}
}

va_end(args);
return (count);
}
