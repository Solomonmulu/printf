#include "main.h"

/**
 * printfChar - prints a char.
 * @val: arguments.
 * Return: 1.
 */
int printfChar(va_list val)
{
	char character = va_arg(val, int);
	_putchar(character);
	return (1);
}

/**
 * printfString - print a string.
 * @val: argument.
 * Return: the length of the string.
 */
int printfString(va_list val)
{
	char *str = va_arg(val, char *);
	int i, len;

	if (str == NULL)
	{
		str = "(null)";
		len = _strlen(str);
		for (i = 0; i < len; i++)
			_putchar(str[i]);
		return (len);
	}
	else
	{
		len = _strlen(str);
		for (i = 0; i < len; i++)
			_putchar(str[i]);
		return (len);
	}
}

/**
 * printfExclusiveString - print exclusive string.
 * @val: argument.
 * Return: the length of the string.
 */
int printfExclusiveString(va_list val)
{
	char *str = va_arg(val, char *);
	int i, len = 0;
	int cast;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			len += 2;
			cast = str[i];
			if (cast < 16)
			{
				_putchar('0');
				len++;
			}
			len += printf_HEX_aux(cast);
		}
		else
		{
			_putchar(str[i]);
			len++;
		}
	}
	return (len);
}

