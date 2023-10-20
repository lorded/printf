#include "main.h"

/**
 * This function calculates the width for printing based on the format string and arguments.
 * 
 * @param format: The formatted string in which to print the arguments.
 * @param i: The current index of the format string.
 * @param list: The list of arguments.
 *
 * @return: The calculated width.
 */
int calculate_width(const char *format, int *i, va_list list)
{
	int currentIndex;
	int width = 0;

	for (currentIndex = *i + 1; format[currentIndex] != '\0'; currentIndex++)
	{
		if (width(format[currentIndex]))
		{
			width *= 10;
			width += format[currentIndex] - '0';
		}
		else if (format[currentIndex] == '*')
		{
			currentIndex++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = currentIndex - 1;

	return width;
}

