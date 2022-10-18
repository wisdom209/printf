#include "main.h"

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
