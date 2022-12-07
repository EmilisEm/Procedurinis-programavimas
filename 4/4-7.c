#include "stdio.h"

#define MSG_MAX "Max value of "
#define MSG_MIN "Min value of "

int main()
{
    // By definition signed
    char c = 0;
    short s = 0;
    long l = 0;
    int i = 0;
    signed sign = 0;

    unsigned u = 0;
    unsigned int ui = 0;
    unsigned char uc = 0;
    unsigned long ul = 0;
    unsigned short us = 0;

    int iFlag = 1, cFlag = 1, lFlag = 1, sFlag = 1, signFlag = 1;

    printf("Calculates the minimum and maximum values of some data types\n");
    // By definition min value of unsigned values is 0

    printf("%sunsigned: %u\n", MSG_MAX, --u);
    printf("%sunsigned: 0\n\n", MSG_MIN);

    printf("%sunsigned int: %u\n", MSG_MAX, --ui);
    printf("%sunsigned int: 0\n\n", MSG_MIN);

    printf("%sunsigned char: %u\n", MSG_MAX, --uc);
    printf("%sunsigned char: 0\n\n", MSG_MIN);

    printf("%sunsigned long: %ul\n", MSG_MAX, --ul);
    printf("%sunsigned long: 0\n\n", MSG_MIN);

    printf("%sunsigned short: %u\n", MSG_MAX, --us);
    printf("%sunsigned short: 0\n\n", MSG_MIN);

    printf("May take a few seconds...\n");

    while (cFlag || iFlag || signFlag || sFlag || lFlag)
    {
        if (cFlag && c++ > c)
        {
            printf("%schar: %hhi\n", MSG_MIN, c);
            printf("%schar: %hhi\n\n", MSG_MAX, --c);
            cFlag = 0;
        }
        if (lFlag && l++ > l)
        {
            printf("%slong: %li\n", MSG_MIN, l);
            printf("%slong: %li\n\n", MSG_MAX, --l);
            lFlag = 0;
        }
        if (sFlag && s++ > s)
        {
            printf("%sshort: %i\n", MSG_MIN, s);
            printf("%sshort: %i\n\n", MSG_MAX, --s);
            sFlag = 0;
        }
        if (signFlag && sign++ > sign)
        {
            printf("%ssigned: %i\n", MSG_MIN, sign);
            printf("%ssigned: %i\n\n", MSG_MAX, --sign);
            signFlag = 0;
        }
        if (iFlag && i++ > i)
        {
            iFlag = 0;
            printf("%sint: %i\n", MSG_MIN, i);
            printf("%sint: %i\n\n", MSG_MAX, --i);
        }
    }
    return 0;
}