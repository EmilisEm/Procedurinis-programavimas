#include "stdio.h"

#define INCORRECT_INPUT_MSG "Ivesti neteisingi duomenys\n"
#define CORRECT_INPUT_MSG "Duomenys nuskenuoti sekmingai\n"
#define INPUT_N_MSG "Iveskite n reiksme: "
#define INPUT_NUM_MSG "Iveskite realaus skaiciaus reiksme: "
#define NO_INPUT "Duomenys nebuvo ivesti"
#define SUM_MSG "Ivestu skaicu suma: "
#define AVG_MSG "Ivestu skaiciu vidurkis: "
#define MIN_MSG "Ivestu skaiciu minimali reiksme: "
#define MAX_MSG "Ivestu skaiciu maksimali reiksme: "

// Function reads one real number
double getUserInput()
{
    double input;
    printf("%s", INPUT_NUM_MSG);

    //          while

    // while ((scanf("%lf", &input) != 1) || (getchar() != '\n'))
    // {
    //     scanf("%*[^\n]");
    //     printf("%s%s", INCORRECT_INPUT_MSG, INPUT_NUM_MSG);
    // }

    //          for

    // for (;(scanf("%lf", &input) != 1) || (getchar() != '\n');)
    // {
    //     scanf("%*[^\n]");
    //     printf("%s%s", INCORRECT_INPUT_MSG, INPUT_NUM_MSG);
    // }

    //          do while

    // int correctInput = 0;
    // do
    // {
    //     if ((scanf("%lf", &input) == 1) && (getchar() == '\n'))
    //     {
    //         correctInput = 1;
    //     }
    //     else
    //     {
    //         scanf("%*[^\n]");
    //         printf("%s%s", INCORRECT_INPUT_MSG, INPUT_NUM_MSG);
    //     }
    // } while (!correctInput);

    //         if goto

    int correctInput = 0;
check:

    if ((scanf("%lf", &input) == 1) && (getchar() == '\n'))
    {
        correctInput = 1;
    }
    else
    {
        scanf("%*[^\n]");
        printf("%s%s", INCORRECT_INPUT_MSG, INPUT_NUM_MSG);
        goto check;
    }

    printf("%s", CORRECT_INPUT_MSG);
    return input;
}

int main()
{
    printf("Iveskite neneigiama sveikaji skaiciu n, o po to n realiuju skaiciu. Programa paskaiciuos ivestu skaiciu suma, vidurki, minimalia bei maksimalia reiksmias\n");

    int n, i;
    double temp, sum = 0, minimum, maximum;
    int incorrectInput = 1;

    // Scans value of n
    printf("%s", INPUT_N_MSG);

//          while

// while (incorrectInput)
// {
//     if ((scanf("%d", &n) == 1) && (getchar() == '\n'))
//     {
//         if (n >= 0)
//         {
//             printf("%s", CORRECT_INPUT_MSG);
//             incorrectInput = 0;
//         }
//     }
//     else
//     {
//         scanf("%*[^\n]");
//         printf("%s%s", INCORRECT_INPUT_MSG, INPUT_N_MSG);
//     }
// }

//          for

// for (;incorrectInput;)
// {
//     if ((scanf("%d", &n) == 1) && (getchar() == '\n'))
//     {
//         if (n >= 0)
//         {
//             printf("%s", CORRECT_INPUT_MSG);
//             incorrectInput = 0;
//         }
//     }
//     else
//     {
//         scanf("%*[^\n]");
//         printf("%s%s", INCORRECT_INPUT_MSG, INPUT_N_MSG);
//     }
// }

//              do while

// do
// {
//     if ((scanf("%d", &n) == 1) && (getchar() == '\n'))
//     {
//         if (n >= 0)
//         {
//             printf("%s", CORRECT_INPUT_MSG);
//             incorrectInput = 0;
//         }
//     }
//     else
//     {
//         scanf("%*[^\n]");
//         printf("%s%s", INCORRECT_INPUT_MSG, INPUT_N_MSG);
//     }
// } while (incorrectInput);

//          if goto
check:
    if ((scanf("%d", &n) == 1) && (getchar() == '\n'))
    {
        if (n >= 0)
        {
            printf("%s", CORRECT_INPUT_MSG);
        }
    }
    else
    {
        scanf("%*[^\n]");
        printf("%s%s", INCORRECT_INPUT_MSG, INPUT_N_MSG);
        goto check;
    }

    // Checks if n != 0. Gets n real numbers
    if (n > 0)
    {
        temp = getUserInput();
        sum += temp;
        minimum = temp;
        maximum = temp;

        //          for

        // for (i = 1; i < n; ++i)
        // {
        //     temp = getUserInput();
        //     sum += temp;
        //     if (temp < minimum)
        //     {
        //         minimum = temp;
        //     }
        //     else if (temp > maximum)
        //     {
        //         maximum = temp;
        //     }
        // }

        //      while

        // i = 1;
        // while (i < n)
        // {
        //     temp = getUserInput();
        //     sum += temp;
        //     if (temp < minimum)
        //     {
        //         minimum = temp;
        //     }
        //     else if (temp > maximum)
        //     {
        //         maximum = temp;
        //     }
        //     ++i;
        // }

        //      do while

        // if (n > 1)
        // {
        //     i = 1;
        //     do
        //     {
        //         temp = getUserInput();
        //         sum += temp;
        //         if (temp < minimum)
        //         {
        //             minimum = temp;
        //         }
        //         else if (temp > maximum)
        //         {
        //             maximum = temp;
        //         }
        //         ++i;
        //     } while (i < n);
        // }

        //      if goto

        i = 1;

        if (n > 1)
        {
        foo:

            temp = getUserInput();
            sum += temp;

            if (temp < minimum)
            {
                minimum = temp;
            }
            else if (temp > maximum)
            {
                maximum = temp;
            }

            if (i < n)
            {
                ++i;
                goto foo;
            }
        }

        printf("%s%lf\n%s%lf\n%s%lf\n%s%lf", SUM_MSG, sum, AVG_MSG, sum / n, MIN_MSG, minimum, MAX_MSG, maximum);
    }
    else
    {
        printf("%s", NO_INPUT);
    }

    return 0;
}