#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/**
 * struct format - match the conversion specifiers for printf
 * @id: type char pointer of the specifier i.e (l, h) for (d, i, u, o, x, X)
 * @f: type pointer to function for the conversion specifier
 */
typedef struct format
{
    char *id;
    int (*f)();
} convertMatch;

int printfPointer(va_list val);
int printfHexAux(unsigned long int num);
int printfHEXAux(unsigned int num);
int printfExclusiveString(va_list val);
int printfHEX(va_list val);
int printfHex(va_list val);
int printfOct(va_list val);
int printfUnsigned(va_list args);
int printfBin(va_list val);
int printfSrev(va_list args);
int printfRot13(va_list args);
int printfInt(va_list args);
int printfDec(va_list args);
int strlen(char *s);
int *strcpy(char *dest, char *src);
int strlenc(const char *s);
int revString(char *s);
int strlenc(const char *s);
int printf37(void);
int printfChar(va_list val);
int printfString(va_list val);
int _putchar(char c);
int _printf(const char *format, ...);

#endif

