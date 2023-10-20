#include "main.h"

/**
 * Determines if a character is printable.
 * 
 * @c The character to be evaluated.
 * @return 1 if c is printable, 0 otherwise.
 */
int isCharacterPrintable(char c)
{
    if (c >= 32 && c < 127)
        return 1;

    return 0;
}

/**
 * Appends the ASCII code in hexadecimal format to a buffer.
 * 
 * @buffer The array of characters.
 * @i The index at which to start appending.
 * @asciiCode The ASCII code.
 * @return Always 3.
 */
int affixHexaCode(char asciiCode, char buffer[], int i)
{
    char mapping[] = "0123456789ABCDEF";
    /* The hexadecimal format code is always 2 digits long */
    if (asciiCode < 0)
        asciiCode *= -1;

    buffer[i++] = '\\';
    buffer[i++] = 'x';

    buffer[i++] = mapping[asciiCode / 16];
    buffer[i] = mapping[asciiCode % 16];

    return 3;
}

/**
 * Determines if a character is a digit.
 * 
 * @c The character to be evaluated.
 * @return 1 if c is a digit, 0 otherwise.
 */
int isCharacterDigit(char c)
{
    if (c >= '0' && c <= '9')
        return 1;

    return 0;
}

/**
 * Converts a number to the specified size.
 * 
 * @num The number to be shown
 * @size The number indicating the type to be shown
 * @return The casted value of num.
 */
long int convertSizeNumber(long int num, int size)
{
    if (size == SIZE_LONG)
        return num;
    else if (size == SIZE_SHORT)
        return (short)num;

    return (int)num;
}

/**
 * Converts an unsigned number to the specified size.
 * 
 * @num The number to be shown
 * @size The number indicating the type to be shown
 * @return The casted value of num.
 */
long int convertSizeUnsigned(unsigned long int num, int size)
{
    if (size == SIZE_LONG)
        return num;
    else if (size == SIZE_SHORT)
        return (unsigned short)num;

    return (unsigned int)num;
}

