#include "stdio.h"

int main()
{
    int num = 7;

    // printf("Iveskite sveikaji skaiciu: ");

    // while ((scanf("%d", &num) != 1) || (getchar() != '\n'))
    // {
    //     scanf("%*[^\n]");
    //     printf("Iveskite sveikaji skaiciu: ");
    // }

    printf("skaicius %d yra %s", num, num % 2 == 0 ? "lyginis" : "nelyginis");

    return 0;
}