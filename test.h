
/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
    char fmt;
    int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fn_t: The function associated.
 */
typedef struct fmt fmt_t;

int custom_printf(const char *format, ...);
int custom_handle_print(const char *fmt, int *i, va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Functions to print chars and strings */
int custom_print_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int custom_print_string(va_list types, char buffer[], int flags, int width, int precision, int size);
int custom_print_percent(va_list types, char buffer[], int flags, int width, int precision, int size);

/* Functions to print numbers */
int custom_print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int custom_print_binary(va_list types, char buffer[], int flags, int width, int precision, int size);
int custom_print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size);
int custom_print_octal(va_list types, char buffer[], int flags, int width, int precision, int size);
int custom_print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size);
int custom_print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size);

int custom_print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non-printable characters */
int custom_print_non_printable(va_list types, char buffer[], int flags, int width, int precision, int size);

/* Function to print memory address */
int custom_print_pointer(va_list types, char buffer[], int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int custom_get_flags(const char *format, int *i);
int custom_get_width(const char *format, int *i, va_list list);
int custom_get_precision(const char *format, int *i, va_list list);
int custom_get_size(const char *format, int *i);

/* Function to print string in reverse */
int custom_print_reverse(va_list types, char buffer[], int flags, int width, int precision, int size);

/* Function to print a string in ROT13 */
int custom_print_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size);

/* Width handler */
int custom_handle_write_char(char c, char buffer[], int flags, int width, int precision, int size);
int custom_write_number(int is_positive, int ind, char buffer[], int flags, int width, int precision, int size);
int custom_write_num(int ind, char bff[], int flags, int width, int precision, int length, char padd, char extra_c);
int custom_write_pointer(char buffer[], int ind, int length, int width, int flags, char padd, char extra_c, int padd_start);
int custom_write_unsgnd(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size);

/****************** UTILS ******************/
int custom_is_printable(char);
int custom_append_hexa_code(char, char[], int);
int custom_is_digit(char);

long int custom_convert_size_number(long int num, int size);
long int custom_convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */

