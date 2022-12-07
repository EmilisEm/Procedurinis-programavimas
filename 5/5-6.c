#include "stdio.h"

#define INCORRECT_INPUT "Entered value does not meet requirements\n"
#define CORRECT_INPUT "Data entered correctly\n\n"
#define REAPEAT_INPUT_MSG "Please repeat the input: "
#define INFO_MSG "Please enter a whole number x and n amount of whole numbers. The program will calculate how many ways there are to add the n real numbers in a way that their sum would be equal to x. If several numbers of the same value are provided they will be counted as seperate numbers\n"
#define ARRAY_MAX_SIZE 1000

int scanNum(char type)
{
    int num, correctInput = 0;

    while (!correctInput)
    {
        if (scanf("%d", &num) == 1 && getchar() == '\n')
        {
            if ((type == 'n' && num >= 0 && num <= ARRAY_MAX_SIZE) || (type != 'n'))
            {
                correctInput = 1;
                break;
            }

            else
            {
                printf("%s%s", INCORRECT_INPUT, REAPEAT_INPUT_MSG);
            }
        }
        else
        {
            scanf("%*[^\n]");
            printf("%s%s", INCORRECT_INPUT, REAPEAT_INPUT_MSG);
        }
    }

    printf("%s", CORRECT_INPUT);
    return num;
}

void printSums(int arr[], int arrLength, int num)
{
    int i, sum = 0;
    for (i = 0; i < arrLength; ++i)
    {
        sum += arr[i];
    }
    if (sum == num)
    {
        printf("%d = ", num);
        for (i = 0; i < arrLength; ++i)
        {
            printf("%d", arr[i]);
            if (i == arrLength - 1)
            {
                printf("\n");
            }
            else
            {
                printf(" + ");
            }
        }
    }
}

// Recurcive function to find all posible ways to get num
// arr[] - array of initial numbers
// arrSize - size of arr[]
// ctm - calls to make. Shows how many times the function has to make a recurcive call. Decreases by iteration
// tctm - total calls to make. Initial ctm used in calculations
// num - number that is to be goten by adding numbers from arr[]
int getSums(int arr[], int arrSize, int newArr[], int ctm, int tctm, int num)
{
    int i;
    if (ctm > 0)
    {

        if (arrSize > 0)
        {
            for (i = 0; i < arrSize; ++i)
            {
                *(newArr + tctm - ctm) = arr[i];
                getSums(arr + 1 + i, arrSize - 1 - i, newArr, ctm - 1, tctm, num);
            }
        }

        return 1;
    }
    printSums(newArr, tctm, num);

    // Return values are for possible error handling
    return 1;
}

int main()
{
    int x, n, i;
    int numArray[ARRAY_MAX_SIZE];
    int tempArray[ARRAY_MAX_SIZE];

    printf("%s", INFO_MSG);

    printf("Please enter the number x: ");
    x = scanNum('r');

    printf("Please enter the number n: ");
    n = scanNum('n');

    for (i = 0; i < n; ++i)
    {
        printf("Please enter the %d number in the array: ", i + 1);
        numArray[i] = scanNum('r');
    }

    for (i = 1; i <= n; ++i)
    {
        getSums(numArray, n, tempArray, i, i, x);
    }

    return 0;
}
