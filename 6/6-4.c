#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define CORRECT_INPUT_MSG "Data entered correctly\n\n"
#define INCORRECT_INPUT_MSG "Data entered incorrectly\n\n"
#define REQUEST_INPUT "Please enter a date in the specified format: "
#define INFO_MSG "Please enter a date in the format yyyy-mm-dd. The program will calculate what day of the week the given date is and read it from the file week.txt.\n\n"
#define DATE_MAX_LENGTH 11
#define WEEKDAY_MAX_LENGTH 200
#define MAX_VALIDATION_ATTEMPTS 5

int getWeekday(char str[], int strLen);
int readData(char str[], int (**funcList)(char[], int), int funcCount);
void printWeekday(int day);
int isDateFormat(char str[], int strLen);
int dateInRange(char str[], int strLen);
int strValidation(int (*functionList[])(char *, int), int, char *, int);
int isLeapYear(int year);

int main()
{
    char str[DATE_MAX_LENGTH];
    int (*funcList[])(char *, int) = {isDateFormat, dateInRange}, weekday;

    printf("%s", INFO_MSG);
    if (!readData(str, funcList, 2))
    {
        printf("Failed to enter correct data. Program quiting...");
        return 0;
    }
    weekday = getWeekday(str, strlen(str));

    printWeekday(weekday);

    return 0;
}

int readData(char str[], int (**funcList)(char[], int), int funcCount)
{
    int incorrectInputCount = 0;
    while (1)
    {
        if (incorrectInputCount >= MAX_VALIDATION_ATTEMPTS)
        {
            return 0;
        }
        printf("%s", REQUEST_INPUT);
        if (scanf("%s", str) == 1 && getchar() == '\n')
        {
            if (strlen(str) != 10)
            {
                ++incorrectInputCount;
                printf("%s", INCORRECT_INPUT_MSG);
                continue;
            }
            else if (strValidation(funcList, funcCount, str, 10))
            {
                printf("%s", CORRECT_INPUT_MSG);
                return 1;
            }
            else
            {
                ++incorrectInputCount;
            }
        }
        else
        {
            ++incorrectInputCount;
            printf("%s", INCORRECT_INPUT_MSG);
            scanf("%*[^\n]");
        }
    }
}

int getWeekday(char str[], int strLen)
{
    int y, m, d;

    y = atoi(str);
    m = atoi(str + 5);
    d = atoi(str + 8);

    return (d += m < 3 ? y-- : y - 2, 23 * m / 9 + d + 4 + y / 4 - y / 100 + y / 400) % 7;
}

void printWeekday(int day)
{
    int i;
    FILE *rf;
    rf = fopen("week.txt", "r");
    char dayOfWeek[WEEKDAY_MAX_LENGTH];

    if (rf == NULL)
    {
        printf("week.txt does not exsist, cannot read day of week");
        return;
    }

    for (i = 0; i < day; ++i)
    {
        fscanf(rf, "%s", dayOfWeek);
    }

    fscanf(rf, "%s", dayOfWeek);

    printf("The specified date is a %s", dayOfWeek);
    fclose(rf);
}
int isDateFormat(char str[], int strLen)
{
    int i;
    for (i = 0; i < strLen; ++i)
    {
        if (i == 4 || i == 7)
        {
            if (str[i] != '-')
            {
                return 0;
            }
        }
        else if (!isdigit(str[i]))
        {
            printf("Input is not of date format\n");
            return 0;
        }
    }
    return 1;
}

int dateInRange(char str[], int strLen)
{
    int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year = atoi(str);
    int month = atoi(str + 5);
    int day = atoi(str + 8);

    if (month < 13 && month > 0 && day <= ((isLeapYear(year) && month == 2) ? daysPerMonth[month - 1] + 1 : daysPerMonth[month - 1]) && day > 0 && year != 0)
    {
        return 1;
    }

    printf("Date is not posible\n");
    return 0;
}

int strValidation(int (*functionList[])(char *, int), int funcCount, char str[], int strLength)
{
    int i;
    for (i = 0; i < funcCount; ++i)
    {
        if (!(functionList[i](str, strLength)))
        {
            return 0;
        }
    }

    return 1;
}

int isLeapYear(int year)
{
    if (year % 4 != 0)
    {
        return 0;
    }
    else if (year % 100 != 0)
    {
        return 1;
    }
    else if (year % 400 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
