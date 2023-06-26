#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _strlen - Counts the length of string
 * @str: The string
 *
 * Return: The count.
 */
int _strlen(const char *str)
{
	int i;

	while (str[i] != '\0')
		i++;
	return (i);
/**
  * _printf - Prints formatted output
  * @format: Character string to output
  *
  * Return: Number of characters printed
  */
int _printf(const char *format, ...)
{
	int i = 0;
	int fmt_len = 0;
	char c;
	char *s;
	int count = 0;
	int j = 0;
	va_list args;

	fmt_len = _strlen(format);
	va_start(args, format);

	for (i = 0; i < fmt_len; i++)
	{
		while (format[i] == '%')
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

				while (s[j] != '\0')
				{
					printchar(s[j]);
					j++;
					count++;
				}
				else if (format[i] == '%')
				{
                                printchar('%');
                                count++;
                        }
                        else
                        {
				printchar(format[i]);
                                count++;
                        }
                }
        }
        va_end(args);
        return (count);
}
