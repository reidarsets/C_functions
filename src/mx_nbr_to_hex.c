#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    unsigned long num = nbr;
    int length = 0;

    while (num) {
        num /= 16;
        length++;
    }
    num = nbr;
    char *number = mx_strnew(length);
    if (nbr == 0)
        return mx_strcpy(number, "0");

    while (num) {
        int temp = num % 16;

        if (temp < 10)
            number[--length] = 48 + temp;
        if (temp >= 10)
            number[--length] = 87 + temp;
            
        num /= 16;
    }

    return number;
}
