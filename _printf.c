#include "main.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 *
 *
 * Return: length of the formatted output string
 */
int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, flags_t *);
	const char *a;
	va_list arguments;
	flags_t flags = {0, 0, 0};

	register int numb = 0;

	va_start(arguments, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (a = format; *a; a++)
	{
		if (*a == '%')
		{
			a++;
			if (*a == '%')
			{
				numb += _putchar('%');
				continue;
			}
			while (get_flag(*a, &flags))
				a++;
			pfunc = get_print(*a);
			numb += (pfunc)
				? pfunc(arguments, &flags)
				: _printf("%%%c", *a);
		} else
			numb += _putchar(*a);
	}
	_putchar(-1);
	va_end(arguments);
	return (numb);

}
