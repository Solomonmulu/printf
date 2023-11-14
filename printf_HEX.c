#include "main.h"

/**
 * printfHex - prints a hexadecimal number.
 * @val: arguments.
 * Return: counter.
 */
int printfHex(va_list val)
{
	unsigned int num = va_arg(val, unsigned int);
	int counter = 0;

	counter = printfHexAux(num);
	return (counter);
}

/**
 * printf_hex - prints a hexadecimal number.
 * @val: arguments.
 * Return: counter.
 */
int printf_hex(va_list val)
{
	unsigned int num = va_arg(val, unsigned int);
	int counter = 0;

	counter = printfHex(num);
	return (counter);
}

/**
 * printfHexAux - prints a hexadecimal number.
 * @num: number to print.
 * Return: counter.
 */
int printfHexAux(unsigned int num)
{
	int counter = 0;
	int i;
	int *array;
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(int));

	for (i = 0; i < counter; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 39;
		_putchar(array[i] + '0');
	}
	free(array);
	return (counter);
}

/**
 * printfHexAux - prints a hexadecimal number.
 * @num: arguments.
 * Return: counter.
 */
int printfHexAux(unsigned long int num)
{
	int counter = 0;
	long int i;
	long int *array;
	unsigned long int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(long int));

	for (i = 0; i < counter; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 39;
		_putchar(array[i] + '0');
	}
	free(array);
	return (counter);
}
