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
				if (choice[j].specifier)
				{
					if ((format[i + 1] == choice[j].specifier[0]) ||
						(format[i + 1] == choice[j].specifier[0] &&
						 format[i + 2] == choice[j].specifier[1]))
					{
						num = choice[j].f(list);
						count += num;
						i++;
						if (choice[j].specifier[1] != '\0')
							i++;
						break;
					}
				}
			}
			if (choice[i].specifier == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != 0)
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					count += 2;
					i++;
				}
				else
					return (-1);
			}
		}
	}
	if (format == NULL)
		return (-1);
	return (count);
}