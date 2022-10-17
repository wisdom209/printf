#include "main.h"

/**
 * nextFunction - next function
 * @current: current format
 * @check: choice to check against
 * @i: param i
 * @list: struct
 *
 * Return: loop return
 */
LoopReturn nextFuncton(const char *current, Choice check, int i, va_list list)
{
	LoopReturn lt;

	if (current[i + 2] == check.specifier[1] && check.specifier[0] == '+')
	{
		lt.count = check.f(list);
	}
	lt.i = i + 2;
	return (lt);
}

/**
 * get_function - gets needed function
 * @format: string
 * @list: variadic list
 * @choice: variadic struct
 * @size: size of struct
 *
 * Return: size of formatted string
 */
int get_function(const char *format, va_list list, Choice choice[], int size)
{
	int i = 0, j = 0, count = 0, num = 0;
	/* LoopReturn lp; */

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
					if (format[i + 1] == choice[j].specifier[0] && !choice[j].specifier[1])
					{
						num = choice[j].f(list);
						count += num;
						i += 1;
						break;
					}
				}
				if (choice[j].specifier && choice[j].specifier[1])
				{
					nextFuncton(format, choice[j], i, list);
				}
			}
		}
	}
	if (format == NULL)
		return (-1);
	return (count);
}
