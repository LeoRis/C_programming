#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>

int minscanf(char *str, char *fmt, ...);

int minscanf(char *str, char *fmt, ...)
{
	va_list ap;
	int matched = 0;
	char *p;

	va_start(ap, fmt);
	for (; *fmt; fmt++) {
		if (isspace(*fmt))
			continue;
		for (; isspace(*str); str++)
			;
		if (*str == '\0')
			break;
		if (*fmt != '%') {
			if (*fmt == *str) {
				str++;
				continue;
			} else {
				break;
			}
		}

		switch (*++fmt) {
		case 'd':
			if (!isdigit(*str) && !((*str == '+' || *str == '-') &&
						isdigit(*(str + 1))))
				break;
			*va_arg(ap, int *) = atoi(str);
			str++;
			while (isdigit(*str) && *str)
				str++;
			matched++;
			continue;
		case 'f':
			*va_arg(ap, double *) = strtod(str, &p);
			if (p == str)
				break;
			str = p;
			matched++;
			continue;
		case 's':
			if (isspace(*str) || !*str)
				break;
			p = va_arg(ap, char *);
			while (!isspace(*str) && *str)
				*p++ = *str++;
			*p = '\0';
			matched++;
			continue;
		case '%':
			if (*str == '%') {
				str++;
				continue;
			} else {
				break;
			}
		default:
			break;
		}
		break;
	}
	va_end(ap);
	return matched;
}
