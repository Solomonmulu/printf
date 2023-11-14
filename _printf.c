#include "main.h"

/**
 * _printf - Selects the correct function to print based on the format.
 * @format: Identifier to look for.
 * Return: The length of the string.
 */
int _printf(const char * const format, ...)
{
	convert_match conversion[] = {
		{"%s", printfString}, {"%c", printfChar},
		{"%%", printfPercent},
		{"%i", printfInt}, {"%d", printfDec}, {"%r", printfSrev},
		{"%R", printfRot13}, {"%b", printfBin}, {"%u", printfUnsigned},
		{"%o", printfOct}, {"%x", printfHex}, {"%X", printfHEX},
		{"%S", printfExclusiveString}, {"%p", printfPointer}
	};

	va_list args;
	int i = 0, j, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[i] != '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (conversion[j].id[0] == format[i] && conversion[j].id[1] == format[i + 1])
			{
				len += conversion[j].f(args);
				i = i + 2;
				goto Here;
			}
			j--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(args);
	return (len);
}
