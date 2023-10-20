#include "main.h"

/**
 * get_prcsn - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @z: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_prcsn(const char *format, int *z, va_list list)
{
	int curr_m = *z + 1;
	int precision = -1;

	if (format[curr_m] != '.')
		return (precision);

	precision = 0;

	for (curr_m += 1; format[curr_m] != '\0'; curr_m++)
	{
		if (is_digit(format[curr_m]))
		{
			precision *= 10;
			precision += format[curr_m] - '0';
		}
		else if (format[curr_m] == '*')
		{
			curr_m++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*z = curr_m - 1;

	return (precision);
}
