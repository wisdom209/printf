#include "main.h"



int ptr_func(va_list list)
{
	int count = 0;
	uintptr_t ptr = (uintptr_t)va_arg(list, void *);

	_putchar('0');
	_putchar('x');
	count = convert(ptr, 16, 0, 1);

	return (count + 2);
}

int plus_func_num(va_list list)
{
	int num = va_arg(list, int);

	if (num < 0)
	{
		num = print_number(num);
		return (num);
	}

	_putchar('+');
	num = print_number(num);

	return (num + 1);
}

int plus_func_ptr(va_list list)
{
	int num = 0;

	_putchar('+');
	num = ptr_func(list);

	return (num + 1);
}
int width_func(va_list list)
{
	char *s = va_arg(list, char *);
	char *skip = "#0- +";
	int i = 0, fieldw = 0;
	for (; s[i]; i++)
	{
		if (isdigit(s[i]))
		{
			fieldw = fieldw * 10 + (s[i] - '0');
		}
		if (s[i] == '*')
		{
			i++;
			fieldw = va_arg(list, int);
			break;
		}
		else
			break;
	}
	return (i);
}
void write_buffer(char buffer[], int count)
{
	int i = 0;
	
	for (; count > 0; i++, count--)
	{
		write(1, &buffer[i], 1);
	}
	i = 0;
}
