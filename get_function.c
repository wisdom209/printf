#include "main.h"

int get_function(const char *format, va_list list, Choice choice[], int size)
{
	int i = 0, j = 0, count = 0, num = 0;
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else
		{
			for (j = 0; j < size; j++)
			{
				if (format[i + 1] == choice[j].specifier[0] && choice[j].specifier[0] != '+')
					{
						num = choice[j].f(list);
						count += num;
						i++;
						break;
					}
					if (format[i + 1] == '+' && (format[i + 2] == choice[j].specifier[1]))
					{
						num = choice[j].f(list);
						count += num;
						i += 2;
						break;
					}
			}
		}
	}
	if (format == NULL)
		return (-1);
	return (count);
}
