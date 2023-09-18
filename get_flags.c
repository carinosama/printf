#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string
 * @i: parameter
 * Return: Flags:
*/
int get_flags(const char *format, int *i)
{

	int j, curr_d;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_d = *i + 1; format[curr_d] != '\0'; curr_d++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_d] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = curr_d - 1;

	return (flags);
}

