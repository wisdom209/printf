#include <stdio.h>
/**
 * convert - base converter
 * @a: number to be converted
 * @base: base to convert to
 * @flag_upper: takes care of uppercase hex
 * @flag_ptr: flag pointer
 * Return: length
 */
int convert(unsigned long a, int base, int flag_upper, int flag_ptr)
{
	unsigned int num = (unsigned int)a;
	int i = 0;
	static char Representation[] = "0123456789ABCDEF";
	static char sRepresentation[] = "0123456789abcdef";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';

	if (flag_ptr == 1)
	{
		do
		{
			*--ptr = sRepresentation[a % base];
			a /= base;
		} while (a != 0);
	}
	else
	{
		do
		{
			if (flag_upper == 1)
				*--ptr = Representation[num % base];
			else
				*--ptr = sRepresentation[num % base];

			num /= base;

		} while (num != 0);
	}

	while (ptr[i] != '\0')
	{
		_putchar(ptr[i]);
		i++;
	}

	return (i);
}
/**
 * percent_func - print mod
 * @list: list args
 * Return: 1
 */
int percent_func(__attribute__((unused)) va_list list)
{
	_putchar('%');
	return (1);
}
