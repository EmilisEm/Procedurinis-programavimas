#include "stdio.h"
#include "math.h"

#define MAX_DIGIT_RESULT "Daugiausia skaitmenu turintis ivestas skaicius: "
#define INCORRECT_INPUT "Ivesti neteisingi duomenys\n"
#define CORRECT_INPUT "Duomenys sekmingai nuskenuoti\n"
#define NO_INPUT "Nebuvo ivestas teigiamas realusis skaicius"
#define INPUT_MSG "Iveskite realuji skaiciu: "
#define ROUNDING_CORRECTION 0.000001

// Gets real number from user
double getNumber()
{
    double number;

    printf("%s", INPUT_MSG);

    //          while

    // while ((scanf("%lf", &number) != 1) || (getchar() != '\n'))
    // {
    //     scanf("%*[^\n]");
    //     printf("%s%s", INCORRECT_INPUT, INPUT_MSG);
    // }

    //          do while

    // int correctInput = 0;

    // do
    // {
    //     if ((scanf("%lf", &number) == 1) && (getchar() == '\n'))
    //     {
    //         correctInput = 1;
    //     }
    //     else
    //     {
    //         scanf("%*[^\n]");
    //         printf("%s%s", INCORRECT_INPUT, INPUT_MSG);
    //     }
    // } while (!correctInput);

    //          for

    // int correctInput = 0;

    // for (; !correctInput;)
    // {
    //     if ((scanf("%lf", &number) == 1) && (getchar() == '\n'))
    //     {
    //         correctInput = 1;
    //     }
    //     else
    //     {
    //         scanf("%*[^\n]");
    //         printf("%s%s", INCORRECT_INPUT, INPUT_MSG);
    //     }
    // }

    //          if goto

    int correctInput = 0;

check:
    if ((scanf("%lf", &number) == 1) && (getchar() == '\n'))
    {
        correctInput = 1;
    }
    else
    {
        scanf("%*[^\n]");
        printf("%s%s", INCORRECT_INPUT, INPUT_MSG);
        goto check;
    }

    // If a user enters a number with more zeros after the dot (for example 12.100) the extra zeros will be removed
    return number;
}

// Gets the number of digits of a real number
int getNumberOfDigits(double num)
{
    if (num > 0)
    {
        int newNum, numOfDigits = 0;
        // Turns the real number into a whole number with the same amount of digits

        //          while
        // while ((ceil(num) - num) > ROUNDING_CORRECTION)
        // {
        //     if (num < 1)
        //     {
        //         num += 1;
        //     }
        //     else
        //     {
        //         num *= 10;
        //     }
        // }

        //          for

        // for (;(ceil(num) - num) > ROUNDING_CORRECTION;)
        // {
        //     if (num < 1)
        //     {
        //         num += 1;
        //     }
        //     else
        //     {
        //         num *= 10;
        //     }
        // }

        //          do while

        int isWhole = 0;

        do
        {
            if ((ceil(num) - num) > ROUNDING_CORRECTION)
            {
                if (num < 1)
                {
                    num += 1;
                }
                else
                {
                    num *= 10;
                }
            }
            else
            {
                isWhole = 1;
            }
        } while (!isWhole);

        newNum = (int)num;

        // Gets the number of digits of the whole number of the same length as the real number
        while (newNum != 0)
        {
            newNum /= 10;
            ++numOfDigits;
        }

        return numOfDigits;
    }

    return -1;
}

int main()
{
    int maxDigits;
    double temp;
    double maxDigitNum; // Number with most digits

    temp = getNumber();

    maxDigits = getNumberOfDigits(temp);
    maxDigitNum = temp;

    while (temp > 0)
    {
        temp = getNumber();

        if ((getNumberOfDigits(temp) > maxDigits) && (temp > 0))
        {
            maxDigitNum = temp;
            maxDigits = getNumberOfDigits(temp);
        }
    }

    // Checks if there was valid input
    if (maxDigits > 0)
    {
        printf("%s%f", MAX_DIGIT_RESULT, maxDigitNum);
    }

    else
    {
        printf("%s", NO_INPUT);
    }

    return 0;
}