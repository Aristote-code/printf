/*
 * File: _printf.c
 * Auth: Gahima Aristote
 *			
 */

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

int _printf(const char *format, ...);
int printchar(char s);
int _strlen(const char *str);

/**
 * printchar - Writes the character s to stdout
 * @s: Character to write
 *
 * Return: 1 on success, -1 on error.
 */
int printchar(char s)
{
return (write(1, &s, 1));
}

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

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(void)
{
int len;
int len2;
unsigned int ui;
void *addr;

len = _printf("Let's try to printf a simple sentence.\n");
len2 = printf("Let's try to printf a simple sentence.\n");
ui = (unsigned int)INT_MAX + 1024;
addr = (void *)0x7ffe637541f0;

_printf("Length:[%d, %i]\n", len, len);
printf("Length:[%d, %i]\n", len2, len2);

_printf("Negative:[%d]\n", -762534);
printf("Negative:[%d]\n", -762534);

_printf("Unsigned:[%u]\n", ui);
printf("Unsigned:[%u]\n", ui);

_printf("Unsigned octal:[%o]\n", ui);
printf("Unsigned octal:[%o]\n", ui);

_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);

_printf("Character:[%c]\n", 'H');
printf("Character:[%c]\n", 'H');

_printf("String:[%s]\n", "I am a string !");
printf("String:[%s]\n", "I am a string !");

_printf("Address:[%p]\n", addr);
printf("Address:[%p]\n", addr);

len = _printf("Percent:[%%]\n");
len2 = printf("Percent:[%%]\n");

_printf("Len:[%d]\n", len);
printf("Len:[%d]\n", len2);

_printf("Unknown:[%c]\n", 'r');
printf("Unknown:[%c]\n", 'r');

return (0);
}
