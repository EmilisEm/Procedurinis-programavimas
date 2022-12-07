#include "stdio.h"
#include "math.h"

#define INCORRECT_INPUT "Entered value does not meet requirements\n"
#define CORRECT_INPUT "Data entered correctly\n\n"
#define REAPEAT_INPUT_MSG "Please repeat the input: "
#define INFO_MSG "Please enter a natural nuber n and then n amount of real numbers. The program will split the numbers in a way that the sum of the two halves is as close as posible\n\n"
#define ARRAY_MAX_SIZE 1000

// Data validation
double scanNum(char type)
{
    double num;
    int correctInput = 0;

    while (!correctInput)
    {
        if (scanf("%lf", &num) == 1 && getchar() == '\n')
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

int findLargesNumIndex(double arr[], int size)
{
    int i, maxIndex = 0;

    for (i = 1; i < size; ++i)
    {
        if (arr[i] > arr[maxIndex])
        {
            maxIndex = i;
        }
    }

    return maxIndex;
}

int findSmallestNumIndex(double arr[], int size)
{
    int smallestIndex = 0, i;

    for (i = 1; i < size; ++i)
    {
        if (arr[i] < arr[smallestIndex])
        {
            smallestIndex = i;
        }
    }

    return smallestIndex;
}

void delDoubleArrItem(double arr[], int index, int *lastIndex)
{
    int i;
    for (i = index; i < *lastIndex; ++i)
    {
        arr[i] = arr[i + 1];
    }

    --(*lastIndex);
}

void printDoubleArray(double arr[], int arrSize)
{
    int i;
    for (i = 0; i < arrSize; ++i)
    {
        printf("%lf", arr[i]);

        if (i == arrSize - 1)
        {
            printf("\n");
        }
        else
        {
            printf(" ");
        }
    }
}

int main()
{
    int elementCount, i, arrIndex2 = 0, arrIndex3 = 0;
    double arr1[ARRAY_MAX_SIZE], arr2[ARRAY_MAX_SIZE], arr3[ARRAY_MAX_SIZE], temp;

    double arrSum1 = 0, arrSum2 = 0, arrSum3 = 0;

    printf("%s", INFO_MSG);

    printf("Please enter n: ");
    elementCount = ceil(scanNum('n'));

    for (i = 0; i < elementCount; ++i)
    {
        printf("Please enter the %d element of the array: ", i + 1);
        arr1[i] = scanNum('r');
        arrSum1 += arr1[i];
    }

    int indexTemp = findLargesNumIndex(arr1, elementCount);
    arr2[arrIndex2++] = arr1[indexTemp];
    arrSum2 = arr1[indexTemp];
    arrSum3 = arrSum1 - arrSum2;

    for (i = 0; i < elementCount; ++i)
    {
        if (i != indexTemp)
        {
            arr3[arrIndex3++] = arr1[i];
        }
    }

    double prevPrevSmallestDiff, prevSmallestDiff = -1, smallestDiff = fabs(arrSum2 - arrSum3), currDiff;

    while (1)
    {
        if (arrSum2 > arrSum3)
        {
            indexTemp = findSmallestNumIndex(arr2, arrIndex2);
            arr3[arrIndex3++] = arr2[indexTemp];
            arrSum2 -= arr2[indexTemp];
            arrSum3 += arr2[indexTemp];
            delDoubleArrItem(arr2, indexTemp, &arrIndex2);
        }
        else
        {
            indexTemp = findSmallestNumIndex(arr3, arrIndex3);
            arr2[arrIndex2++] = arr3[indexTemp];
            arrSum3 -= arr3[indexTemp];
            arrSum2 += arr3[indexTemp];
            delDoubleArrItem(arr3, indexTemp, &arrIndex3);
        }

        currDiff = fabs(arrSum2 - arrSum3);
        if (currDiff <= smallestDiff)
        {
            prevPrevSmallestDiff = prevSmallestDiff;
            prevSmallestDiff = smallestDiff;
            smallestDiff = currDiff;
        }

        if ((prevSmallestDiff == currDiff) && (currDiff == smallestDiff) && (prevPrevSmallestDiff == currDiff))
        {
            printDoubleArray(arr2, arrIndex2);
            printDoubleArray(arr3, arrIndex3);
            break;
        }
    }

    return 0;
}