#include "stdio.h"
#include "math.h"

#define REQUEST_INPUT_MSG "Please enter a whole number: "
#define INCORRECT_INPUT_MSG "Entered number does not meet requirements\n"
#define CORRECT_INPUT_MSG "Entered number accepted\n\n"
#define INFO_MSG "Enter a real number s, a natural number n and n amout of real numbers. The program will print the numbers that can be made out of the digits of the number s\n\n"
#define ARRAY_MAX_SIZE 1000
#define ROUNDING_ERROR_OFSET 0.0000001

void getDigits(int num, int digitCount[])
{
    int i;

    for (i = 0; i < 10; ++i)
    {
        digitCount[i] = 0;
    }

    if (num == 0)
    {
        digitCount[0]++;
    }

    while (num != 0)
    {
        digitCount[num % 10]++;
        num /= 10;
    }
}

int scanWholeNum()
{
    int num;

    while (1)
    {

        if (scanf("%d", &num) == 1 && getchar() == '\n')
        {
            if (num >= 1)
            {
                break;
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
    int n, s, temp, i, j, canMakeNum = 1;
    int sDigits[10] = {0}, tempDigits[10] = {0};

    int nums[ARRAY_MAX_SIZE];
    printf("%s", INFO_MSG);

    printf("Please enter the number s: ");
    s = scanWholeNum();
    getDigits(s, sDigits);

    printf("Please enter the number n: ");
    n = scanWholeNum();

    for (i = 0; i < n; ++i)
    {
        printf("Plesase enter the %d number: ", i + 1);
        nums[i] = scanWholeNum();
    }

    for (i = 0; i < n; ++i)
    {
        getDigits(nums[i], tempDigits);

        for (j = 0; j < 10; ++j)
        {
            if (sDigits[j] < tempDigits[j])
            {
                canMakeNum = 0;
                break;
            }
        }

        if (canMakeNum)
        {
            printf("%d ", nums[i]);
        }
        canMakeNum = 1;
    }

    return 0;
}
