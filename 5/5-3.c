#include "stdio.h"

#define INCORRECT_INPUT_MSG "Entered data does not meet requirements\n\n"
#define CORRECT_INPUT_MSG "Data entered correctly\n\n"
#define INFO_MSG "Enter a natural number s and a natural number n. The program will scan n natural numbers and output the pairs that when multipied produce s\n"
#define REQUEST_MSG "Please enter the specified number: "
#define OUTPUT_MSG "Pairs that when multiplied produce the number s:\n"
#define ARRAY_MAX_SIZE 1000

int scanNaturalNumber(char type)
{
    int num, correctInput = 0;
    while (!correctInput)
    {
        printf("%s", REQUEST_MSG);
        if (scanf("%d", &num) == 1 && getchar() == '\n')
        {
            if (num > 0 || type == 'z')
            {
                correctInput = 1;
            }
            else
            {
                printf("%s", INCORRECT_INPUT_MSG);
            }
        }
        else
        {
            printf("%s", INCORRECT_INPUT_MSG);
            scanf("%*[^\n]");
        }
    }

    printf("%s", CORRECT_INPUT_MSG);

    return num;
}

int main()
{
    int s, n, i, j;
    int nums[ARRAY_MAX_SIZE];

    printf("%s", INFO_MSG);

    printf("Enter s:\n");
    s = scanNaturalNumber('n');

    printf("Enter n:\n");
    n = scanNaturalNumber('z');

    for (i = 0; i < n; ++i)
    {
        printf("Enter the %d number:\n", i + 1);
        nums[i] = scanNaturalNumber('n');
    }

    printf("%s", OUTPUT_MSG);
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (nums[i] * nums[j] == s)
            {
                printf("%d * %d = %d\n", nums[i], nums[j], s);
            }
        }
    }
    return 0;
}