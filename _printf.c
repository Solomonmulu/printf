#include "main.h"

/**
 * _printf - selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
	int i, j, len = 0;
	va_list args;
	convert_match m[] = {
		{"%s", printfString}, {"%c", printfChar},
		{"%%", printfpercent},
		{"%i", printfInt}, {"%d", printfDec}, {"%r", printfRev},
		{"%R", printfRot13}, {"%b", printfBin}, {"%u", printfUnsigned},
		{"%o", printfOct}, {"%x", printfHex}, {"%X", printfHEX},
		{"%S", printfExclusiveString}, {"%p", printfPointer}
	};

	va_start(args, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		for (j = 13; j >= 0; j--)
		{
			if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
			{
				len += m[j].f(args);
				i += 2;
				goto here;
			}
		}
		_putchar(format[i]);
		len++;
	here:
		continue;
	}

	va_end(args);
	return (len);
}
