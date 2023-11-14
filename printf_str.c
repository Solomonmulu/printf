#include "main.h"

/**
 * _strlen - Returns the length of a string.
 * @s: Type char pointer
 * Return: c.
 */
int _strlen(char *s)
{
    int c;

    for (c = 0; s[c] != 0; c++)
        ;
    return (c);
}

/**
 * _strlenc - Strlen function but applied for a constant char pointer s
 * @s: Type char pointer
 * Return: c
 */
int _strlenc(const char *s)
{
    int c;

    for (c = 0; s[c] != 0; c++)
        ;
    return (c);
}

/**
 * printfPointer - prints a hexadecimal number.
 * @val: arguments.
 * Return: counter.
 */
int printfPointer(va_list val)
{
    void *p;
    char *s = "(nil)";
    long int a;
    int b;
    int i;

    p = va_arg(val, void*);
    if (p == NULL)
    {
        for (i = 0; s[i] != '\0'; i++)
        {
            _putchar(s[i]);
        }
        return (i);
    }

    a = (unsigned long int)p;
    _putchar('0');
    _putchar('x');
    b = printfHexAux(a);
    return (b + 2);
}

