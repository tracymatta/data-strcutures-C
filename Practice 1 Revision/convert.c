#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calculateBiggestExponent(int num, int base, int exponent) {
    if(num < base) return 0;
    if(num < pow(base, exponent+1)) return exponent;
    return calculateBiggestExponent(num, base, exponent+1);
}

int calculateNumberOfTimes(int num, int base, int exponent, int times) {
    if(num < base || num < pow(base, exponent)) return times;
    num -= pow(base, exponent);
    return calculateNumberOfTimes(num, base, exponent, times+1);
}

void convertHelper(int num, int base, int exponent, char *str) {
    if(exponent == 0) {
        if(num < 10) *str = num + '0';
        else *str = num%10 + 'A';
        str = str + 1;
        *str = '\0';
        return;
    }
    int times = calculateNumberOfTimes(num, base, exponent, 0);
    if(times < 10) *str = times + '0';
    else *str = times%10 + 'A';
    num -= pow(base, exponent)*times;
    convertHelper(num, base, exponent-1, str+1);
}

char *convert(int num, int base, char *str) {
    int exponent = calculateBiggestExponent(num, base, 0);
    convertHelper(num, base, exponent, str);
    return str;
}

void main() {
    char *inWantedBase = (char*)malloc(sizeof(char)*5);
    convert(8, 2, inWantedBase);
    printf("%s", inWantedBase);
}