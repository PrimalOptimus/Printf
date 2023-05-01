#include "main.h"

/**
 * print_int - prints an integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_int(va_list l, flags_t *f)
{
	int n = va_arg(l, int);
	int sh = count_digit(n);

	if (f->space == 1 && f->plus == 0 && n >= 0)
		sh += _putchar(' ');
	if (f->plus == 1 && n >= 0)
		sh += _putchar('+');
	if (n <= 0)
		sh++;
	print_number(n);
	return (sh);
}

/**
 * print_unsigned - prints an unsigned integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_unsigned(va_list l, flags_t *f)
{
	unsigned int u = va_arg(l, unsigned int);
	char *str = convert(u, 10, 0);

	(void)f;
	return (_puts(str));
}

/**
 * print_number - helper function that loops through
 * an integer and prints all its digits
 *
 * @n: integer to be printed
 */
void print_number(int n)
{
	unsigned int x;

	if (n < 0)
	{
		_putchar('-');
		x = -n;
	}
	else
		x = n;

	if (x / 10)
		print_number(x / 10);
	_putchar((x % 10) + '0');
}

/**
 * count_digit - returns the number of digits in an integer
 * for _printf
 *
 * @i: integer to evaluate
 * Return: number of digits
 */
int count_digit(int i)
{
	unsigned int y = 0;
	unsigned int x;

	if (i < 0)
		x = i * -1;
	else
		x = i;
	while (x != 0)
	{
		x /= 10;
		y++;
	}
	return (y);
}
