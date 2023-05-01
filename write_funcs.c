#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1
 * Description: _putchar uses a local buffer of 1024 to call write
 * as little as possible
 */
int _putchar(char c)
{
	static char buf[1024];
	static int a;

	if (c == -1 || a >= 1024)
	{
		write(1, &buf, a);
		a = 0;
	}
	if (c != -1)
	{
		buf[a] = c;
		a++;
	}
	return (1);
}

/**
 * _puts - prints a string to stdout
 * @str: pointer to the string to print
 * Return: number of chars written
 */
int _puts(char *str)
{
	register int a;

	for (a = 0; str[a] != '\0'; a++)
		_putchar(str[a]);
	return (a);
}
