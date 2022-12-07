#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

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

int getNumLength(int num)
{
    int length = 0;
    if (num == 0)
    {
        return 1;
    }

    while (num > 0)
    {
        ++length;
        num /= 10;
    }

    return length;
}

int getStrLength(char str[])
{
    int i;
    for (i = 0; i < 5; ++i)
    {
        if (str[i] == '\0')
        {
            return i + 1;
        }
    }
}

int strIsRealNumber(char str[], int strLen)
{
    int i, commaCount = 0;
    for (i = 0; i < strLen; ++i)
    {
        if (str[i] != ',' && (str[i] < 48 || str[i] > 57))
        {
            return 0;
            printf("String value is not real number\n");
        }
        else if (str[i] == ',')
        {
            if (++commaCount > 1)
            {
                return 0;
                printf("String value is not real number\n");
            }
        }
    }

    // Check if the last simbol is a comma does not count as a num
    if (str[strLen - 1] == ',')
    {
        return 0;
    }
    return commaCount == 1 ? strLen - 1 : strLen;
}

int isSemicolonSeperatedInt(char str[], int strLen)
{
    int i;
    for (i = 0; i < strLen; ++i)
    {
        if (!isdigit(str[i]))
        {
            if (str[i] == ';' && i == 0 || str[i] == ';' && str[i - 1] == ';' || str[i] != ';')
            {
                printf("Data is not of specified format\n");
                return 0;
            }
        }
    }
    return 1;
}

int isThreeNums(char str[], int strLen)
{
    int count = 0;
    char *token;
    token = strtok(str, ";");

    while (token != 0)
    {
        ++count;
        token = strtok(NULL, ";");
    }

    if (count == 3)
    {
        return 1;
    }

    printf("Input must countain 3 numbers, contains only %d\n", count);
    return 0;
}

int isTxtFile(char str[], int strLen)
{
    if (strcmp(".txt", &(str[strLen - 1]) - 3))
    {
        printf("file name must end with .txt\n");
        return 0;
    }
    return 1;
}

int checkStrNumPercision(char str[], int strLen)
{
    int i, count = 0, afterCommaFlag = 0;
    for (i = 0; i < strLen; ++i)
    {
        if (str[i] == ',')
        {
            afterCommaFlag = 1;
        }

        else if (afterCommaFlag)
        {
            ++count;
        }
    }

    return (count <= 3) ? 1 : !printf("Too manny digits after the comma\n");
}

int strInRange(char str[], int strLen)
{
    int wholeNum = atoi(str);

    if (wholeNum >= 10 && wholeNum < 1000)
    {
        return 1;
    }
    else if (wholeNum == 1000 && !atoi(str + getNumLength(wholeNum) + 1))
    {
        return 1;
    }
    else
    {
        printf("The entered number is not in specified range");
        return 0;
    }
}

int isPositive(int num)
{
    return (num > 0) ? 1 : !printf("Nuber is not positive\n") && 0;
}

int isDateFormat(char str[], int strLen)
{
    int i;
    for (i = 0; i < strLen; ++i)
    {
        if ((i == 4 || i == 7) && str[i] == '-')
        {
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

int isEmail(char str[], int strLen)
{
    int i, atFlag = 0, dotFlag = 0;
    char *point;

    for (i = 0; i < strLen; ++i)
    {
        if (str[i] == '@' && !atFlag)
        {
            if (i == 0)
            {
                printf("Input is not of email format\n");
                return 0;
            }

            atFlag = 1;
            point = str + i;
        }
        else if (str[i] == '@')
        {
            printf("Input is not of email format\n");
            return 0;
        }

        if (str[i] == '.' && atFlag && !dotFlag)
        {
            if ((str + i - point <= 1) || (i == strLen - 1))
            {
                printf("Input is not of email format\n");
                return 0;
            }

            dotFlag = 1;
        }
    }
    if (dotFlag && atFlag)
    {
        return 1;
    }
    else
    {
        printf("Input is not of email format\n");
        return 0;
    }
}

int intigerValidation(int (*funcList[])(int), int funcCount, int num)
{
    int i, requirementFlag;
    for (i = 0; i < funcCount; ++i)
    {
        if (!(*funcList[i])(num))
        {
            return 0;
        }
    }

    return 1;
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
