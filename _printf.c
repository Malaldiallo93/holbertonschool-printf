#include "main.h"

/**
 *
 *
 *
 */

int _printf(const char *format, ...)
{
	int count = 0;
	int value = 0;
	int i = 0;
	int (*f)(va_list);

	va_list args;
	va_start(args, format);

	if (&format[i] == NULL)
	{
		return (-1);
	}

	while (format[i])
	{
		if (format[i] != '%')
		{
			value = write(1, &format[i], 1);
			count = count + value;
			i++;
			continue;
		}

		if (format[i] == '%')
		{
			f = specifiers(&format[i + 1]);
		}

		if (f != NULL)
		{
			value = f(args);
			count = count + value;
			i = i + 2;
			continue;
		}

		if (format[i + 1] == '\0')
		{
			break;
		}

		if (format[i + 1] != '\0')
		{
			value = write(1, &format[i], 1);
			count = count + value;
			i = i + 2;
			continue;
		}
	}
	va_end(args);
	return count;
}
