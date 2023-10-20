#include "main.h"

/**
 * This function calculates the size to cast the argument based on the format string.
 * 
 * @param format: Formatted string in which to print the arguments
 * @param i: Pointer to the current index in the format string
 * 
 * @return: The size to cast the argument
 */
int calculateSize(const char *format, int *i)
{
    int current_i = *i + 1;
    int size = 0;

    if (format[current_i] == 'l')
        size = SIZE_LONG;
    else if (format[current_i] == 'h')
        size = SIZE_SHORT;

    if (size == 0)
        *i = current_i - 1;
    else
        *i = current_i;

    return size;
}

