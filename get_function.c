#include "main.h"

int get_function(const char *format, va_list list, Choice choice[], int size)
{
	int i = 0, j = 0, count = 0, num = 0, width;

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
					if (format[i + 1] == choice[j].specifier[0] && choice[j].specifier[0] != '+')
					{
						num = choice[j].f(list);
						count += num;
						i += 2;
						break;
					}
					if (format[i + 1] == '+' && (format[i + 2] == choice[j].specifier[1]))
					{
						num = choice[j].f(list);
						count += num;
						i += 2;
						break;
					}
					if (format[i + 1] == '+' && (format[i + 2] == ' '))
					{
						int k = 3;
						int space = 0;

						while (format[k] == ' ')
						{
							k++;
							space++;
						}

						if (format[k] == choice[j].specifier[1])
						{
							num = choice[j].f(list);
							count += num;
							i = i + 3 + space;
							break;
						}

					}
				}
			}
		}
	}
	if (format == NULL)
		return (-1);
	return (count);
}
