#include "main.h"
#include "helper_functions.c"
#include "get_function.c"

/**
 * _printf - prints formatted string
 * @format: formatted string to print
 *
 * Return: string length
 */
int _printf(const char *format, ...)
{

	va_list ptr;
	int size = 0;

	Choice choice[] =
		{
			{"c", char_func},
			{"s", str_func},
			{"d", digit_func},
			{"i", digit_func},
			{"%", percent_func},
			{"b", binary_func},
			{"u", unsig_int_func},
			{"X", hex_upper_func},
			{"x", hex_lower_func},
			{"o", octal_func},
			{"S", stringupperCase_func},
			{"r", rev_func},
			{"R", rot13_func},
			{"p", ptr_func},
			/* {"+i",plus_func},
			{"+d",plus_func},
			{"+ptr",plus_func}, */
			{"+b", binary_func},
			{"+x", hex_lower_func},
			{"+X", hex_upper_func},
			{"+s", str_func},
			{"+c", char_func},
			{NULL, NULL}};

	va_start(ptr, format);

	size = sizeof(choice) / sizeof(Choice);

	size = get_function(format, ptr, choice, size);

	return (size);
}