#include "main.h"

/**
 * _putchar - prints a char to stdout
 * @c: char to print
 *
 * Return: 1 if successful
 */
int _putchar(char c)
{
	int i = write(1, &c, 1);
	return (i);
}

/**
 * char_func - prints single char
 * @list: list of arguments
 *
 * Return: 1 if char is printed
 */
int char_func(va_list list)
{
	char c = va_arg(list, int);
	_putchar(c);

	return (1);
}

/**
 * str_func - prints single char
 * @list: list of arguments
 *
 * Return: 1 if char is printed
 */
int str_func(va_list list)
{
	char *s = va_arg(list, char *);
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
	return (i);
}

int print_number(long int n)
{
	static int count = 0;

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

int digit_func(va_list list)
{
	int numLen = -1;
	int a = va_arg(list, int);

	if (a <= INT_MAX && a >= INT_MIN)
	{
		numLen = print_number(a);
	}

	return (numLen);
}

int percent_func(__attribute__((unused)) va_list list)
{
	_putchar('%');
	return (1);
}

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

int binary_func(va_list list)
{
	int b = va_arg(list, unsigned int);
	int a = convert(b, 2, 1, 0);

	return (a);
}

int unsig_int_func(va_list list)
{
	unsigned int n = va_arg(list, unsigned int);

	if (n > UINT_MAX)
		n = n - UINT_MAX - 1;

	print_number(n);
	return (0);
}

int hex_upper_func(va_list list)
{
	int num = va_arg(list, unsigned int);
	int a = convert(num, 16, 1, 0);

	return (a);
}

int hex_lower_func(va_list list)
{
	int num = va_arg(list, unsigned int);
	int a = convert(num, 16, 0, 0);

	return (a);
}

int octal_func(va_list list)
{
	int num = va_arg(list, unsigned int);
	int a = convert(num, 8, 0, 0);

	return (a);
}

int stringupperCase_func(va_list list)
{
	char *s = va_arg(list, char *);
	int i = 0;
	int count = 0;

	while (s[i] != '\0')
	{
		if (!(s[i] > 32 && s[i] < 127))
		{
			_putchar('\\');
			_putchar('x');

			if (s[i] >= 0 && s[i] <= 15)
			{
				_putchar('0');
			}

			convert(s[i], 16, 1, 0);

			count += 4;
		}
		else
		{
			_putchar(s[i]);
			count++;
		}
		i++;
	}

	return (count);
}

int rev_func(va_list list)
{
	char *s = va_arg(list, char *);
	int size = 0, i = 0;

	while (s[size] != '\0')
		size++;

	for (i = size - 1; i >= 0; i--)
		_putchar(s[i]);

	return (size);
}

/**
 * rot13 - rot13 encryption of strings
 * @s: string to encrypt
 *
 * Return: encrypted string
 */
int rot13_func(va_list list)
{
	char *s = va_arg(list, char *);

	char ref[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char src[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	int i = 0, j = 0;

	while (s[i] != '\0')
	{
		j = 0;
		while (ref[j] != '\0')
		{
			if (s[i] == ref[j])
			{
				_putchar(src[j]);
				break;
			}
			j++;
		}

		if (s[i] != ref[j])
			_putchar(s[i]);

		i++;
	}
	
	return (i);
}

int ptr_func(va_list list)
{
	int count = 0;
	uintptr_t ptr = (uintptr_t)va_arg(list, void *);

	_putchar('0');
	_putchar('x');
	count = convert(ptr, 16, 0, 1);
	
	return (count + 2);
}


