#include "main.h"
/**
 * hex_upper_func - base 16
 * @list: list args
 * Return: value
 */
int hex_lower_func(va_list list)
{
	int num = va_arg(list, unsigned int);
	int a = convert(num, 16, 0, 0);

	return (a);
}
