#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

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
  * printstr - Writes characters of a string
  * @s: String to write
  *
  * Return: 1 on success, -1 on error.
  */

int printstr(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		printchar((int) *s);
		count++;
		s++;
	}
	return (count);
}

/**
  * printfmt - Prints according to the identifier
  * @identifier: The format specifier
  * @args: Argument pointer
  *
  * Return: Integer
  */

int printfmt(char identifier, va_list args)
{
	int count = 0;

	if (identifier == 'c')
		count += printchar(va_arg(args, int));
	else if (identifier == 's')
		count += printstr(va_arg(args, char *));
	else
		count += write(1, &identifier, 1);
	return (count);
}

/**
  * _printf - Prints formatted output
  * @format: Character string to output
  *
  * Return: Number of characters printed
  */

int _printf(const char *format, ...)
{
	int count = 0;

	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			count += printfmt(*(format + 1), args);
			format++;
		}
		else
		{
			count += write(1, format, 1);
		}

		format++;
	}
	va_end(args);
	return (count);
}
