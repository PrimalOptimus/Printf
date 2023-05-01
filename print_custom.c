#include "main.h"

/**
 *
 * print_bigS - Non printable character
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_bigS(va_list l, flags_t *f)
{
	int a, numb = 0;
	char *res;
	char *s = va_arg(l, char *);

	(void)f;
	if (!s)
		return (_puts("(null)"));

	for (a = 0; s[a]; a++)
	{
		if (s[a] > 0 && (s[a] < 32 || s[a] >= 127))
		{
			_puts("\\x");
			numb += 2;
			res = convert(s[a], 16, 0);
			if (!res[1])
				numb += _putchar('0');
			numb += _puts(res);
		}
		else
			numb += _putchar(s[i]);
	}
	return (numb);
}

/**
 * print_rev - prints a string in reverse
 * @l: argument from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: length of the printed string
 */
int print_rev(va_list l, flags_t *f)
{
	int a = 0, b;
	char *s = va_arg(l, char *);

	(void)f;
	if (!s)
		s = "(null)";

	while (s[a])
		a++;

	for (b = a - 1; b >= 0; b--)
		_putchar(s[b]);

	return (a);
}

/**
 * print_rot13 - prints a string using rot13
 * @l: list of arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: length of the printed string
 */
int print_rot13(va_list l, flags_t *f)
{
	int a, b;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *s = va_arg(l, char *);

	(void)f;
	for (b = 0; s[b]; b++)
	{
		if (s[b] < 'A' || (s[b] > 'Z' && s[b] < 'a') || s[b] > 'z')
			_putchar(s[b]);
		else
		{
			for (a = 0; a <= 52; a++)
			{
				if (s[b] == rot13[a])
					_putchar(ROT13[a]);
			}
		}
	}

	return (b);
}

/**
 * print_percent - prints a percent
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags in which we turn the flags on
 *
 * Return: number of char printed
 */
int print_percent(va_list l, flags_t *f)
{
	(void)l;
	(void)f;
	return (_putchar('%'));
}
