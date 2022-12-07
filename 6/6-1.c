#include <stdio.h>

#define MAX_VALIDATION_ATTEMPTS 5
#define CORRECT_INPUT "Data entered correctly\n\n"
#define NAN_INPUT "The entered value is not a natural number\n"
#define INFO_MSG "enter a natural number N. The program will calculate the factorial of N print it to the screen and save it in the file out.txt\n\n"

int readInput(int (*data[])(int), int);
int getFactorial(int);
void writeToFile(int);
int isPositive(int);
int intigerValidation(int (**)(int), int, int);

int main()
{
    int (*funcArr[10])(int) = {isPositive};
    printf("%s", INFO_MSG);

    int n = readInput(funcArr, 1);

    if (n == -1)
    {
        return 0;
    }

    printf("%d! ", n);

    n = getFactorial(n);
    printf("= %d", n);
    writeToFile(n);

    return 0;
}

// Function returns user input if all values in function array criteria[] return true
int readInput(int (**criteria)(int), int size)
{
    int num;
    int failedValidation = 0;
    while (1)
    {
        if (failedValidation >= MAX_VALIDATION_ATTEMPTS)
        {
            printf("Failed to enter correct data. Program quiting...");
            return -1;
        }
        printf("Please enter N: ");
        if (scanf("%d", &num) == 1 && getchar() == '\n')
        {
            if (intigerValidation(criteria, size, num))
            {
                printf("%s", CORRECT_INPUT);
                return num;
            }
            else
            {
                ++failedValidation;
                printf("%s", NAN_INPUT);
            }
        }
        else
        {
            ++failedValidation;
            printf("%s", NAN_INPUT);
            scanf("%*[^\n]");
        }
    }
}

int getFactorial(int num)
{
    int returnNum = 1, i;

    for (i = 2; i <= num; ++i)
    {
        returnNum *= i;
    }

    return returnNum;
}

void writeToFile(int num)
{
    FILE *wf;

    wf = fopen("out.txt", "w");
    fprintf(wf, "%d", num);
    fclose(wf);
}

int isPositive(int num)
{
    return (num > 0) ? 1 : !printf("Nuber is not positive\n") && 0;
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
