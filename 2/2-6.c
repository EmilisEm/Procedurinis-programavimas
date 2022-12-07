#include "stdio.h"

int main()
{
    int num1 = 1, num2 = 9, num3 = 2;
    // printf("Iveskite 3 sveikus skaicius: ");

    // while ((scanf("%d%d%d", &num1, &num2, &num3) != 3) || (getchar() != '\n'))
    // {
    //     scanf("%*[^\n]");
    //     printf("Iveskite 3 sveikus skaicius: ");
    // }

    int largestNum = (num1 > num2) ? ((num1 > num3) ? num1 : num3) : ((num2 > num3) ? num2 : num3);
    int smallestNum = (num1 < num2) ? ((num1 < num3) ? num1 : num3) : ((num2 < num3) ? num2 : num3);
    printf("Maziausia reiksme: %d\nDidziausia reiksme: %d", smallestNum, largestNum);

    return 0;
}