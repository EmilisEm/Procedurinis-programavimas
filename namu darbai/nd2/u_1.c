// Parasyti programa kuri paskirsto dienas per metus lygiais intervalais
// (6men 4men 3men 2men 1men)

#include <stdio.h>
#include <math.h>

#define CORRECT_INPUT "Data entered correctly\n"
#define INCORRECT_INPUT "Data entered incorrectly\n"
#define ROUNDING_ERROR 0.0001

// Returns the amount of days a user enters
int getDays(char *);

// Distributes largest possible amount equaly until there is none left
void splitEvenly(int arr[], int arrSize, int arrLimits[], int num);

int findMin(int arr[], int size);

int findNearestInBounds(int arrLimits[], int arr[], int arrSize, int num);

void printArray(int *arr, int size);

int findNextInBounds(int arrLimits[], int arr[], int arrSize, int num);

void splitRemaider(int arr[], int arrSize, int arrLimits[], int num);

int main()
{
    int workDaysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int daysWorked[12] = {0};
    int days = getDays("Please enter day count:\n");

    printf("Here");
    printf("Here");
    splitEvenly(daysWorked, sizeof(daysWorked) / sizeof(*daysWorked), workDaysInMonth, days);
    printArray(daysWorked, 12);

    return 0;
}

int getDays(char *inputMsg)
{
    int days;
    while (1)
    {
        printf("%s", inputMsg);

        if (scanf("%d", &days) == 1 && getchar() == '\n')
        {
            if (days >= 0)
            {
                printf("%s", CORRECT_INPUT);
                return days;
            }
        }
        else
        {
            scanf("%*[^\n]");
        }
        printf("%s", INCORRECT_INPUT);
    }
}

void splitEvenly(int arr[], int arrSize, int arrLimits[], int num)
{
    int i;
    float gap = 0, gapInitial;

    if (num % arrSize == 0)
    {
        gap = arrSize + 1;
    }
    else
    {
        gapInitial = (float)arrSize / (num % arrSize);
    }

    printf("Here gap : %f\n", gap);

    if (num / arrSize + 1 <= findMin(arrLimits, arrSize))
    {
        for (i = 0; i < arrSize; ++i)
        {
            arr[i] += num / arrSize;
        }
    }
    else
    {
        for (i = 0; i < arrSize; ++i)
        {
            arr[i] += findMin(arrLimits, arrSize);
        }

        printf("%d\n\n", num - arrSize * findMin(arrLimits, arrSize));
        splitRemaider(arr, arrSize, arrLimits, num - arrSize * findMin(arrLimits, arrSize));
    }

    while (gap + ROUNDING_ERROR <= arrSize)
    {
        printf("%f ", gap);
        if (arr[(int)gap] == arrLimits[(int)gap])
        {
            ++arr[findNearestInBounds(arrLimits, arr, arrSize, (int)ceil(gap))];
        }

        ++arr[(int)ceil(gap)];

        gap += gapInitial;
    }

    printf("Here end\n");
}

int findMin(int arr[], int size)
{
    int i;
    if (size < 1)
    {
        return -1;
    }
    int min = arr[0];

    for (i = 1; i < size; ++i)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    printf("Here min : %d\n", min);

    return min;
}

int findNearestInBounds(int arrLimits[], int arr[], int arrSize, int num)
{
    int i = 1;

    while (1)
    {
        if (num - i >= 0)
        {
            if (arr[num - i] < arrLimits[num - i])
            {
                return num - i;
            }
        }
        if (num + i < arrSize)
        {
            if (arr[num + i] < arrLimits[num + i])
            {
                return num + i;
            }
        }
        if (num - i < 0 && num + i >= arrSize)
        {
            return -1;
        }

        ++i;
    }
}

void printArray(int *arr, int size)
{
    int i;

    for (i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void splitRemaider(int arr[], int arrSize, int arrLimits[], int num)
{
    int i = 0;

    while (num > 0)
    {
        if (arr[i] == arrLimits[i])
        {
            i = findNextInBounds(arrLimits, arr, arrSize, i);
            if (arr[i] < arrLimits[i])
            {
                ++arr[i];
                --num;
            }
        }
        else
        {
            ++arr[i++];
            --num;
        }
    }
}

int findNextInBounds(int arrLimits[], int arr[], int arrSize, int num)
{
    while (num <= arrSize && arr[num] == arrLimits[num])
    {
        if (num >= arrSize)
        {
            return 0;
        }
        ++num;
    }

    return num;
}

int arrSum(int arrSize, int arr[])
{
    int i, sum = 0;

    for (i = 0; i < arrSize; ++i)
    {
        sum += arr[i];
    }

    return sum;
}