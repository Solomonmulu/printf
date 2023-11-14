#include "main.h"

/**
 * process_format_specifiers - Process the format string and call the appropriate functions.
 * @format: The format string.
 * @args: The variable arguments list.
 * Return: The total length of the printed string.
 */
static int process_format_specifiers(const char *format, va_list args)
{
    int i = 0, j, len = 0;
    convert_match m[] = {
        {"%s", printfString}, {"%c", printfChar},
        {"%%", printfpercent},
        {"%i", printfInt}, {"%d", printfDec}, {"%r", printfRev},
        {"%R", printfRot13}, {"%b", printfBin}, {"%u", printfUnsigned},
        {"%o", printfOct}, {"%x", printfHex}, {"%X", printfHEX},
        {"%S", printfExclusiveString}, {"%p", printfPointer}
    };

    while (format[i] != '\0')
    {
        int specifier_found = 0;

        for (j = 13; j >= 0; j--)
        {
            if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
            {
                len += m[j].f(args);
                i = i + 2;
                specifier_found = 1;
                break;
            }
        }

        if (!specifier_found)
        {
            _putchar(format[i]);
            len++;
            i++;
        }
    }

    return len;
}

/**
 * _printf - Custom printf function.
 * @format: The format string.
 * Return: The total length of the printed string.
 */
int _printf(const char * const format, ...)
{
    int len;
    va_list args;

    va_start(args, format);

    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
    {
        va_end(args);
        return -1;
    }

    len = process_format_specifiers(format, args);

    va_end(args);
    return len;
}
