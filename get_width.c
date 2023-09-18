#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string
 * @i: List of argument
 * @list: list of argument
 * Return: width
*/
int get_width(const char *format, int *i, va_list list)
{
	int curr_d;
	int width = 0;

	for (curr_d = *i + 1; format[curr_d] != '\0'; curr_d++)
	{
		if (is_digit(format[curr_d]))
		{
			width *= 10;
			width += format[curr_d] - '0';
		}
		else if (format[curr_d] == '*')
		{
			curr_d++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_d - 1;

	return (width);
}

