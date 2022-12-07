#include "stdio.h"
#include "math.h"

#define INCORRECT_INPUT_MSG "Entered number does not meet requirements\n"
#define CORRECT_INPUT_MSG "Entered number accepted\n\n"
#define REQUEST_INPUT_MSG "Please enter a positive whole number: "
#define INFO_MSG "Enter a series of positive whole numbers. The series will be terminated by a non-positive number. The program will print the prime numbers that were entered\n"
#define OUTPUT_MSG "Prime numbers that were entered: "
#define NO_OUTPUT_MSG "No prime number was entered"
#define ARRAY_MAX_SIZE 1000

unsigned scanNum()
{
    int num;

    while (1)
    {
        printf("%s", REQUEST_INPUT_MSG);
        if (scanf("%d", &num) == 1 && getchar() == '\n')
        {
            break;
        }
        else
        {
            printf("%s", INCORRECT_INPUT_MSG);
            scanf("%*[^\n]");
        }
    }

    printf("%s", CORRECT_INPUT_MSG);
    if (num > 0)
    {
        return num;
    }
    else
    {
        return 0;
    }
}

char isPrime(unsigned num)
{
    char isPrime = 't';
    int i;

    for (i = 2; i < (int)sqrt(num) + 1; ++i)
    {
        if (num % i == 0)
        {
            isPrime = 'f';
            break;
        }
    }
    if (num == 1)
    {
        return 'f';
    }
    return isPrime;
}

void filterNonPrimesAndDuplicates(unsigned arrMain[], unsigned arrMainSize, unsigned arrSecond[], unsigned *arrSecondSize)
{
    int i, j, isInSecondArray = 0;

    for (i = 0; i < arrMainSize; ++i)
    {
        for (j = 0; j < *arrSecondSize; ++j)
        {
            if (arrMain[i] == arrSecond[j])
            {
                isInSecondArray = 1;
                break;
            }
        }

        if (!isInSecondArray && isPrime(arrMain[i]) == 't')
        {
            arrSecond[*arrSecondSize] = arrMain[i];
            ++(*arrSecondSize);
        }
        isInSecondArray = 0;
    }
}

int main()
{
    unsigned temp, enteredNumsSize = 0, enteredPrimesSize = 0;
    unsigned enteredNums[ARRAY_MAX_SIZE];
    unsigned enteredPrimes[ARRAY_MAX_SIZE];

    printf("%s", INFO_MSG);
    do
    {
        temp = scanNum();
        if (temp > 0)
        {
            enteredNums[enteredNumsSize] = temp;
            ++enteredNumsSize;
        }

    } while (temp > 0);

    filterNonPrimesAndDuplicates(enteredNums, enteredNumsSize, enteredPrimes, &enteredPrimesSize);

    if (enteredPrimesSize > 0)
    {
        printf("%s", OUTPUT_MSG);
        for (temp = 0; temp < enteredPrimesSize; ++temp)
        {
            printf("%d ", enteredPrimes[temp]);
        }
    }
    else
    {
        printf("%s", NO_OUTPUT_MSG);
    }

    return 0;
}