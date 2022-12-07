#include "stdio.h"
#include "ctype.h"
#include "math.h"
#include "string.h"

#define NUM_MAX 65
#define WRONG_INPUT_MSG "Ivesti reikalavimu neatitinkantys duomenys\n"

int convertToBase(int base1, char num1[], int base2, int num2[])
{
    int i, k, tempNum;

    for (i = 0; i < strlen(num1); ++i)
    {
        if (isdigit(num1[i]))
        {
            tempNum = num1[i] - '0';
        }
        else
        {
            tempNum = tolower(num1[i]) - 'a' + 10;
        }

        tempNum *= pow(base1, i);

        for (k = 0; tempNum != 0; ++k)
        {
            tempNum += num2[k] * pow(base2, k);
            num2[k] = tempNum / pow(base2, k);
            num2[k] %= base2;
            tempNum -= num2[k] * pow(base2, k);
        }
    }
    return k;
}

int main()
{
    int i = 0, base1 = 16, base2 = 2, wrongInput = 0;
    char number[NUM_MAX] = "e";
    int newNum[NUM_MAX] = {0};

    //              INPUT
    // printf("Iveskite naturaluji skaiciu kuris yra skaiciavimo sistemos pagrinda(pvz. 10 , jei desimtaine): ");
    // while (scanf("%d", &base1) != 1 && getchar() != '\n')
    // {
    //     printf("Ivesti netvarkingi duomenys\n");
    //     scanf("%[^\n]");
    // }

    // printf("Iveskite bazes kuria nuredete skaiciu: ");

    // while (1)
    // {

    //     while (scanf("%s", number) != 1 && getchar() != '\n')
    //     {
    //         printf("%s", WRONG_INPUT_MSG);
    //         scanf("%[^\n]");
    //     }

    //     for (i = 0; i < strlen(number); ++i)
    //     {
    //         if (!isalnum(number[i]))
    //         {
    //             wrongInput = 1;
    //         }
    //     }

    //     if (!wrongInput)
    //     {
    //         strrev(number);
    //         break;
    //     }

    //     printf("%s", WRONG_INPUT_MSG);
    //     wrongInput = 0;
    // }

    // printf("Iveskite naturaluji skaiciu kuris yra skaiciavimo sistemos, i kuria norite paversti skaicu, pagrinda(pvz. 10 , jei desimtaine): ");
    // while ((scanf("%d", &base2) != 1) && (getchar() != '\n'))
    // {
    //     printf("Ivesti netvarkingi duomenys\n");
    //     scanf("%[^\n]");
    // }

    int newLen = convertToBase(base1, number, base2, newNum);
    for (int i = newLen - 1; i >= 0; --i)
    {
        printf("%d", newNum[i]);
    }
    return 0;
}