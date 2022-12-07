// Parasyti programa kuri paskirsto dienas per metus lygiais intervalais
// (6men 4men 3men 2men 1men)

#include <stdio.h>
#include <math.h>

#define CORRECT_INPUT "Data entered correctly\n"
#define INCORRECT_INPUT "Data entered incorrectly\n"
#define ROUNDING_ERROR 0.0001
#define DAY_COUNT 365

// Scans user input
int getDays(char *inputMsg, int max);

// Splits days so that the gap between each day is even
void splitDays(int days[], int holidays[], int dayCount, int daysToSplit);

// Finds the nearest index of day that is not a holiday and is not a study day. Returns -1 on error
int findNearestDay(int days[], int holidays[], int dayCount, int index);

// Prints the items of an array
void printArray(int *arr, int size);

// Calculates the sum of an array
int arrSum(int arrSize, int arr[]);

// Prints a period of months in year array
void printMonths(int days[], int dayCount, int months[], int monthPeriod);

// Sets values in holiday array. 1 means the day is a holiday, 0 means its not
void getHolidays(int holidays[], int dayCount);

// Gets the number of the day
int getDay(char *inputMsg, int max);

int main()
{
    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, i, n, sum = 0;
    int days[DAY_COUNT] = {0};
    int holidays[DAY_COUNT] = {0};

    printf("This program will devide the days a person wants to study as evenly as posible in a non leap-year year. Firstly the user enters the numbers of the days he wants to not study (for example fabruary 2nd is 32, fabruary 3rd is 33), than the amount of days he wishes to study. The program will print how much time should the person study during various periods\n\n");
    getHolidays(holidays, DAY_COUNT);
    splitDays(days, holidays, DAY_COUNT, getDays("Enter the number of days to disperse in the year: ", DAY_COUNT - arrSum(DAY_COUNT, holidays)));

    printf("Study days devided in various periods:\n");
    printf("\n monthly:\n");
    printMonths(days, DAY_COUNT, months, 1);
    printf("\n quarterly:\n");
    printMonths(days, DAY_COUNT, months, 3);
    printf("\n every six months:\n");
    printMonths(days, DAY_COUNT, months, 6);

    return 0;
}

int getDays(char *inputMsg, int max)
{
    int days;
    while (1)
    {
        printf("%s", inputMsg);

        if (scanf("%d", &days) == 1 && getchar() == '\n')
        {
            if (days >= 0 && days <= max)
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

void splitDays(int days[], int holidays[], int dayCount, int daysToSplit)
{
    int i, nearestDay;
    float gap = 0;
    for (i = 0; i < daysToSplit; ++i)
    {

        if (holidays[(int)gap] == 0 && days[(int)gap] != 1)
        {
            days[(int)gap] = 1;
        }
        else
        {
            nearestDay = findNearestDay(days, holidays, dayCount, (int)gap);
            if (nearestDay != -1)
            {
                days[nearestDay] = 1;
            }
            else
            {
                printf("To many days to fit in a year. Quiting");
            }
        }

        gap += (float)dayCount / daysToSplit;
    }
}

int findNearestDay(int days[], int holidays[], int dayCount, int index)
{
    int i = 1;

    while (index + i < dayCount || index - i >= 0)
    {
        if (index + i < dayCount)
        {
            if (days[index + i] == 0 && holidays[index + i] == 0)
            {
                return index + i;
            }
        }

        if (index - i >= 0)
        {
            if (days[index - i] == 0 && holidays[index - i] == 0)
            {
                return index - i;
            }
        }
        ++i;
    }

    return -1;
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

int arrSum(int arrSize, int arr[])
{
    int i, sum = 0;

    for (i = 0; i < arrSize; ++i)
    {
        sum += arr[i];
    }

    return sum;
}

void printMonths(int days[], int dayCount, int months[], int monthPeriod)
{
    int sum, i, n, daysPassed = 0;

    for (i = 0; i < 12 / monthPeriod; ++i)
    {
        sum = 0;
        for (n = i * monthPeriod; n < (i + 1) * monthPeriod; ++n)
        {
            sum += arrSum(months[n], days + daysPassed);
            daysPassed += months[n];
        }

        printf("%d\n", sum);
    }
}

void getHolidays(int holidays[], int dayCount)
{
    int input;
    while (input = getDay("Enter a date to make a holiday: ", DAY_COUNT))
    {
        holidays[input - 1] = 1;
    }
}

int getDay(char *inputMsg, int max)
{
    int days;
    while (1)
    {
        printf("%s", inputMsg);

        if (scanf("%d", &days) == 1 && getchar() == '\n')
        {
            if (days >= 0 && days <= max)
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