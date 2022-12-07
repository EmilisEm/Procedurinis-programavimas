#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_VALIDATION_ATTEMPTS 5
#define NUM_MAX_LENGTH 1000
#define FILE_NAME_LENGTH 1000
#define LENGTH_ERROR "Entered value has to many charecteres\n\n"
#define NEW_INPUT_MSG "The value in the file does not meet the requirements or the file does not exist. Please enter a new file to be scaned: "
#define CORRECT_INPUT_MSG "Data entered correctly\n"
#define INFO_MSG "Please enter a real nuber in the range of 10 and 1000 into the file in.txt. The program will return the length of the number. The intiger values are seperated from the decimal values by a comma. There can not be more than 3 values after the comma\n\n"

void printResult(int);
int readData(char *, char *, int (**)(char *, int), int);
int strIsRealNumber(char str[], int strLen);
int checkStrNumPercision(char str[], int strLen);
int strInRange(char str[], int strLen);
int strValidation(int (*functionList[])(char *, int), int, char *, int);
int getNumLength(int);

int main()
{
    char data[NUM_MAX_LENGTH], fileName[FILE_NAME_LENGTH] = "in.txt";
    int (*funcList[])(char *, int) = {strIsRealNumber, checkStrNumPercision, strInRange};
    int correctInput = 0, incorrectInputCount = 0;

    printf("%s", INFO_MSG);
    while (!readData(fileName, data, funcList, 3))
    {
        if (incorrectInputCount >= MAX_VALIDATION_ATTEMPTS)
        {
            printf("Failed to enter correct data. Program quiting...");
            return 0;
        }
        ++incorrectInputCount;
        printf("%s", NEW_INPUT_MSG);
        scanf("%s", fileName);
    }
    printf("The number contains %d digits", strIsRealNumber(data, strlen(data)));

    return 0;
}

// Returns the amount of digits in the number if it meets requirements
int readData(char fileName[], char data[], int (*funcList[])(char *, int), int funcCount)
{
    int length = 0, i;
    char temp;

    FILE *rf;
    rf = fopen(fileName, "r");
    if (rf == NULL)
    {
        fclose(rf);
        return 0;
    }
    fscanf(rf, "%s", data);
    fclose(rf);

    length = strlen(data);

    if (strValidation(funcList, funcCount, data, length))
    {
        printf("%s", CORRECT_INPUT_MSG);
        return 1;
    }

    return 0;
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
