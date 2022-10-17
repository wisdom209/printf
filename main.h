#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <ctype.h>

/**
 * Choice - name of struct for choosing function
 * @format: format specifier
 * @f: pointer to function to call
 */

typedef struct Choice
{
	char *specifier;
	int (*f)(va_list list);
} Choice;

int width_func(va_list list);
int _putchar(char c);
int print_char(va_list list);
#endif
