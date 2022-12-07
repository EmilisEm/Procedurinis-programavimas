#include <stdio.h>
#include <string.h>

#define MAX_VALIDATION_ATTEMPTS 5
#define EMAIL_MAX_LENGTH 1000
#define EMAIL_MAX_COUNT 1000
#define CORRECT_INPUT_MSG "Data entered correctly\n\n"
#define INCORRECT_INPUT_MSG "Data entered incorrectly\n\n"
#define REQUEST_INPUT "Please enter data in the specified format: "
#define INFO_MSG "Please enter a string. The program will check if it is an email. An entered string will count as such if it contains one '@' simbol, at least one '.' simbol affter the '@' and at least one charecter before, in between and after these simbols. Correct emails will be appended to the file 'emails.txt'\n\n"

int readData(char *, int (**)(char *, int), int);
void appendFile(FILE *, char *);
int isEmail(char *, int);
int strValidation(int (**)(char *, int), int, char *, int);

int main()
{
    char email[EMAIL_MAX_LENGTH];
    int (*filterList[])(char *, int) = {isEmail}, i, afterAt = 0;
    FILE *file;

    printf("%s", INFO_MSG);

    if (!readData(email, filterList, 1))
    {
        printf("Failed to enter correct data. Program quiting...");
        return 0;
    }
    printf("%s", INFO_MSG);

    printf("The domain of the email is: ");
    for (i = 0; i < strlen(email); ++i)
    {
        if (afterAt)
        {
            printf("%c", email[i]);
            continue;
        }
        if (email[i] == '@')
        {
            afterAt = 1;
        }
    }
    printf("\n");

    appendFile(file, email);

    return 0;
}

int readData(char str[], int (**funcList)(char[], int), int funcCount)
{
    int wrongInputCount = 0;
    while (1)
    {
        if (wrongInputCount >= MAX_VALIDATION_ATTEMPTS)
        {
            return 0;
        }
        printf("%s", REQUEST_INPUT);
        if (scanf("%s", str) == 1 && getchar() == '\n')
        {
            if (strValidation(funcList, funcCount, str, strlen(str)))
            {
                printf("%s", CORRECT_INPUT_MSG);
                return 1;
            }
            else
            {
                ++wrongInputCount;
            }
        }
        else
        {
            ++wrongInputCount;
            printf("%s", INCORRECT_INPUT_MSG);
            scanf("%*[^\n]");
        }
    }
}

void appendFile(FILE *file, char str[])
{
    file = fopen("emails.txt", "a");

    if (file == NULL)
    {
        printf("Failed to oppen file");
        fclose(file);
    }

    fprintf(file, "%s\n", str);
    fclose(file);

    printf("%s added to emails.txt", str);
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
