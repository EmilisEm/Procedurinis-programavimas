#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_VALIDATION_ATTEMPTS 5
#define FILE_NAME_MAX_SIZE 1000
#define STR_MAX_SIZE 1000
#define CORRECT_INPUT_MSG "Data entered correctly\n\n"
#define INFO_MSG "Please enter three intigers seperated by semicolons. This program will calculate their average and write it into a specified file.\n\n"
#define FILE_MSG "Please enter the name of the file you wish to wrtie the average to. The name must be a plain text file(.txt). You must write the file ending\n\n"

int readData(char *, int (**)(char *, int), int);
double getAverage(int, int, int);
int getFileName(char *, int (**)(char *, int), int);
int writeFile(char *, double);
int isSemicolonSeperatedInt(char str[], int strLen);
int isTxtFile(char str[], int strLen);
int isThreeNums(char str[], int strLen);
int strValidation(int (*functionList[])(char *, int), int, char *, int);
int getNumLength(int);

int main()
{
    int nums[3], i, strOffset = 0;
    char input[STR_MAX_SIZE];
    char fileName[STR_MAX_SIZE];
    int (*numFilterList[])(char *, int) = {isSemicolonSeperatedInt, isThreeNums};
    int (*nameFilterList[])(char *, int) = {isTxtFile};
    double avg;

    printf("%s", INFO_MSG);
    if (!readData(input, numFilterList, 2))
    {
        printf("Failed to enter correct data. Program quiting...");
        return 0;
    }

    for (i = 0; i < 3; ++i)
    {
        nums[i] = atoi(input + strOffset);
        strOffset += getNumLength(nums[i]) + 1;
    }

    avg = getAverage(nums[0], nums[1], nums[2]);

    printf("%s", FILE_MSG);
    if (!readData(fileName, nameFilterList, 1))
    {
        printf("Failed to enter correct data. Program quiting...");
        return 0;
    }
    writeFile(fileName, avg);

    return 0;
}

int readData(char data[], int (*funcList[])(char *, int), int funcCount)
{
    int incorrectValidationCount = 0;
    while (1)
    {
        if (incorrectValidationCount > MAX_VALIDATION_ATTEMPTS)
        {
            return 0;
        }
        printf("Please enter the data in the specified format: ");
        if (scanf("%s", data) == 1 && getchar() == '\n')
        {
            if (strValidation(funcList, funcCount, data, strlen(data)))
            {
                printf("%s", CORRECT_INPUT_MSG);
                return 1;
            }
            ++incorrectValidationCount;
        }
        else
        {
            ++incorrectValidationCount;
            scanf("%*[^\n]");
        }
    }
}

double getAverage(int x, int y, int z)
{
    return (double)(x + y + z) / 3;
}

int writeFile(char fileName[], double num)
{
    FILE *wf;
    wf = fopen(fileName, "w");

    if (wf == NULL)
    {
        return 0;
    }
    fprintf(wf, "%lf", num);
    fclose(wf);

    printf("Average of the three numberes writen to the file %s", fileName);

    return 1;
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
