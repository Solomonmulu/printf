#include "main.h"

/**
 * printfChar - Character print.
 * @args: arguments.
 * Return: 1.
 */
int printfChar(va_list args)
{
	char c;

	c = va_arg(args, int);
	_putchar(c);
	return (1);
}

/**
 * printfString - print a string.
 * @args: arguments.
 * Return: the length of the string.
 */

int printfString(va_list args)
{
	char *str;
	int i, ln;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		str = "(null)";
		ln = _strlen(str);
		for (i = 0; i < ln; i++)
			_putchar(str[i]);
		return (ln);
	}
	else
	{
		ln = _strlen(str);
		for (i = 0; i < ln; i++)
			_putchar(str[i]);
		return (ln);
	}
}

/**
 * _strlen - Returns the lenght of a string.
 * @str: Type char pointer
 * Return: s
 */
int _strlen(char *str)
{
	int s;

	for (s = 0; str[s] != 0; s++)
		;
	return (s);

}

/**
 * _strlenc - Strlen function but applied for constant char pointer str
 * @str: Type char pointer
 * Return: s
 */
int _strlenc(const char *str)
{
	int s;

	for (s = 0; str[s] != 0; s++)
		;
	return (s);
}