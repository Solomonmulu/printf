#include "main.h"

/**
 * printfBin - prints a binary number.
 * @val: arguments.
 * Return: number of characters printed.
 */
int printfBin(va_list val)
{
	int flag = 0;
	int count = 0;
	int i, bit;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int mask;

	for (i = 0; i < 32; i++)
	{
		mask = ((1u << (31 - i)) & num);
		if (mask >> (31 - i))
			flag = 1;
		if (flag)
		{
			bit = mask >> (31 - i);
			_putchar(bit + '0');
			count++;
		}
	}
	if (count == 0)
	{
		count++;
		_putchar('0');
	}
	return (count);
}

/**
 * printfOct - prints an octal number.
 * @val: arguments.
 * Return: number of characters printed.
 */
int printfOct(va_list val)
{
	int i;
	int *array;
	int counter = 0;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int temp = num;

	while (num / 8 != 0)
	{
		num /= 8;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(int));

	for (i = 0; i < counter; i++)
	{
		array[i] = temp % 8;
		temp /= 8;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		_putchar(array[i] + '0');
	}
	free(array);
	return (counter);
}

