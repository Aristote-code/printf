#include <stdarg.h>
#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int printchar(char s);
int printstr(char *s);
int printfmt(char identifiers, va_list args);

#endif
