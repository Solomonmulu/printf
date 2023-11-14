#include "main.h"

/**
 * printfBin - prints a binary number.
 * @args: arguments.
 * Return: 1.
 */
int printfBin(va_list args)
{
	int fl = 0, c = 0, i, a = 1, b;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int p;

	for (i = 0; i < 32; i++)
	{
		p = ((a << (31 - i)) & num);
		if (p >> (31 - i))
			fl = 1;
		if (fl)
		{
			b = p >> (31 - i);
			_putchar(b + 48);
			c++;
		}
	}
	if (c == 0)
	{
		c++;
		_putchar('0');
	}
	return (c);
}

/**
 * printfOct - prints an octal number.
 * @args: arguments.
 * Return: count.
 */
int printfOct(va_list args)
{
	int i;
	int *array;
	int count = 0;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int temp = num;

	while (num / 8 != 0)
	{
		num /= 8;
		count++;
	}
	count++;
	array = malloc(count * sizeof(int));

	for (i = 0; i < count; i++)
	{
		array[i] = temp % 8;
		temp /= 8;
	}
	for (i = count - 1; i >= 0; i--)
	{
		_putchar(array[i] + '0');
	}
	free(array);
	return (count);
}
