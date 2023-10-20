#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - The printf function.
 * @format: Format.
 * Return: Always the printed chars.
 */

int _printf(const char *format, ...)

{
	int j, prtd = 0, prtd_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[buff_ind++] = format[j];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			prtd_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = getthe_flags(format, &j);
			width = get_width(format, &j, list);
			precision = get_prcsn(format, &j, list);
			size = get_size(format, &j);
			++j;
			prtd = handle_print(format, &j, list, buffer,
				flags, width, precision, size);
			if (prtd == -1)
				return (-1);
			prtd_chars += prtd;
		}
	}
	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (prtd_chars);
}

/**
 * print_buffer - Will prints contents of the buffer if it exist.
 * @buffer: An array of chars.
 * @buff_ind: Index at which to add the next char, represents the length.
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
