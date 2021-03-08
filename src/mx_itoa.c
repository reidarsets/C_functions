#include "libmx.h"

char *mx_itoa(int number) {
	int length = 0;
	int numb = 0;

	while (numb) {
		numb /= 10;
		length++;
	}

	char *result = mx_strnew(length);

	if (number == 0)
		return mx_strcpy(result, "0");

	if (number == -2147483648)
		return mx_strcpy(result, "-2147483648");

	for (int i = 0; i < length; i++) {
		if (number < 0) {
			result[length] = '-';
			number = -number;
		}

		result[i] = (number % 10) + '0';
		number /= 10;
	}

	mx_str_reverse(result);

	return result;
}
