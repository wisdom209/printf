#include "main.h"

/**
 * print_int_func - prints signed numbers
 * @n: parameter
 * Return: count
 */
int print_int_func(long int n)
{
	static int count;

	unsigned int x = 0;

	if (n < 0)
	{
		n = n * -1;

		x = n;
		_putchar('-');
		count++;
	}
	else
		x = n;

	if (x / 10)
		print_number(x / 10);

	_putchar((x % 10) + '0');
	count++;

	return (count);
}

/**
 * space_func_num - space num
 * @list: list args
 * Return: num
 */
int space_func_num(va_list list)
{
	int num = va_arg(list, int);

	return (num);
}

/**
 * space_func_ptr - space ptr
 * @list: list args
 * Return: num
 */
int space_func_ptr(va_list list)
{
	int num = va_arg(list, int);

	return (num);
}

/**
 * mod_octal_func - space ptr
 * @list: list args
 * Return: num
 */
int mod_octal_func(va_list list)
{
	int num = va_arg(list, int);

	return (num);
}

/**
 * mod_hex_func - octal func
 * @list: list args
 * Return: num
 */
int mod_hex_func(va_list list)
{
	int num = va_arg(list, int);

	return (num);
}
