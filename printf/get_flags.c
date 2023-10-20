#include "main.h"

/**
 * getthe_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @k: take a parameter.
 * Return: Flags.
 */

int getthe_flags(const char *format, int *k)
{

	int z, curr_m;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_m = *k + 1; format[curr_m] != '\0'; curr_m++)
	{
		for (z = 0; FLAGS_CH[z] != '\0'; z++)
			if (format[curr_m] == FLAGS_CH[z])
			{
				flags |= FLAGS_ARR[z];
				break;
			}

		if (FLAGS_CH[z] == 0)
			break;
	}

	*k = curr_m - 1;

	return (flags);
}
