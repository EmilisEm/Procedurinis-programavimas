#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"

#define CORRECT_INPUT_MSG "Data entered correctly\n\n"
#define INCORRECT_INPUT_MSG "Data entered incorrectly\n\n"
#define INVALID_RANGE_MSG "Entered range [a; b] is invalid\n\n"
#define DESCRIPTION_MSG "Enter 3 whole numbers(a, b and c). The pogram will generate c amount of whole numbers in the range [a; b]\n"

int scanInput(char type)
{
    int num, correctInput = 0;
    while (!correctInput)
    {
        printf("Please enter the value of %c: ", type);

        if (scanf("%d", &num) == 1 && getchar() == '\n')
        {
            if (((type == 'c') && (num >= 0) && (num <= 1000)) || (type == 'a') || (type == 'b'))
            {
                correctInput = 1;
            }
            else
            {
                printf("%s", INCORRECT_INPUT_MSG);
            }
        }
        else
        {

            scanf("%*[^\n]");
            printf("%s", INCORRECT_INPUT_MSG);
        }
    }

    printf("%s", CORRECT_INPUT_MSG);

    return num;
}

int main()
{
    int randomNums[1000];
    int a, b, c;
    srand(time(NULL));

    printf("%s", DESCRIPTION_MSG);

    do
    {
        a = scanInput('a');
        b = scanInput('b');

        if (a > b)
        {
            printf("%s", INVALID_RANGE_MSG);
        }
    } while (a > b);

    c = scanInput('c');

    // It is posible to print the specified amount of numbers without the use of an array
    // for (; c > 0; --c)
    // {
    //     printf("%d ", rand() % (b + 1 - a) + a);
    // }

    for (; c - 1 >= 0; --c)
    {
        randomNums[c - 1] = rand() % (b + 1 - a) + a;
        printf("%d ", randomNums[c - 1]);
    }

    return 0;
}