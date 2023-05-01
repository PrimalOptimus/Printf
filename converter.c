#include "main.h"
#include <stdio.h>
/**
 * convert - function to converts number and base into string
 * 
 * @num: input number
 * @base: input base
 * @lowercase: flag if hexa values need to be lowercase
 * Return: result string
 *
 */
char *convert(unsigned long int num, int base, int lowercase)
{
	static char *polo;
	static char buffer[50];
	char *ptr;

	polo = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";

	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = polo[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}
