#include "stdio.h"
#include "math.h"

int printBinary(int d)
{
    // Uzpildo masyva nuliais ir apskaiciuoja didziausia 2 laipsnio eile
    int binaryNum[32] = {0}, length = (int)log2(d);
    printf("%d - ", d);

    while (d != 0)
    {
        binaryNum[(int)log2(d)] = 1;
        d -= pow(2, (int)log2(d));
    }

    for (; length >= 0; --length)
    {
        printf("%d", binaryNum[length]);
    }

    printf(" decimal to binary\n\n");
}

int convertBinaryToDecimal(char *b, int length)
{
    int num = 0, i;

    for (i = length - 1; i >= 0; --i)
    {
        if (b[i] - '0')
            num += pow(2, length - i - 1);
    }

    return num;
}

int main()
{
    // Negalima paskaiciuoti array length funkcijoje nes programa nezino kad pointer yra array
    printf("%s - %d binary to decimal\n\n", "11011", convertBinaryToDecimal("11011", sizeof("11011") - 1));
    printf("%s - %d binary to decimal\n\n", "10010100", convertBinaryToDecimal("10010100", sizeof("10010100") - 1));
    printf("%s - %d binary to decimal\n\n", "11001011010101", convertBinaryToDecimal("11001011010101", sizeof("11001011010101") - 1));

    // Kad nereiketu grazinti masyvo sispausdina dar funkcijoje
    printBinary(37);
    printBinary(241);
    printBinary(2487);

    printf("%x - %d hexadecimal to decimal\n\n", 0x6E2, 0x6E2);
    printf("%x - %d hexadecimal to decimal\n\n", 0xED33, 0xED33);
    printf("%x - %d hexadecimal to decimal\n\n", 0x123456, 0x123456);

    printf("%d - %x decimal to hexadecimal\n\n", 243, 243);
    printf("%d - %x decimal to hexadecimal\n\n", 2483, 2483);
    printf("%d - %x decimal to hexadecimal\n\n", 4612, 4612);

    return 0;
}