#include "stdio.h"
#include "math.h"

//              while

// void getUserInput(int *num, char name)
// {
//     printf("Iveskite %c: ", name);
//     while ((scanf("%d", num) != 1) || (getchar() != '\n'))
//     {
//         scanf("%*[^\n]");
//         printf("Neteisinga ivestis. Is naujo iveskite %c: ", name);
//     }
//     printf("Skaicius nuskenuotas sekmingai\n");
// }

//              for

// void getUserInput(int *num, char name)
// {
//     printf("Iveskite %c: ", name);
//     for (; (scanf("%d", num) != 1) || (getchar() != '\n');)
//     {
//         scanf("%*[^\n]");
//         printf("Neteisinga ivestis. Is naujo iveskite %c: ", name);
//     }
//     printf("Skaicius nuskenuotas sekmingai\n");
// }

//              do while

// void getUserInput(int *num, char name)
// {
//     int correctInput = 0;
//     printf("Iveskite %c: ", name);
//
//     do
//     {
//         if ((scanf("%d", num) == 1) && (getchar() == '\n'))
//         {
//             correctInput = 1;
//         }
//         else
//         {
//             scanf("%*[^\n]");
//             printf("Neteisinga ivestis. Is naujo iveskite %c: ", name);
//         }
//     } while (!correctInput);
//     printf("Skaicius nuskenuotas sekmingai\n");
// }

//              if goto

void getUserInput(int *num, char name)
{
    int correctInput = 0;
    printf("Iveskite %c: ", name);
check:
    if ((scanf("%d", num) == 1) && (getchar() == '\n'))
    {
        correctInput = 1;
    }
    else
    {
        scanf("%*[^\n]");
        printf("Neteisinga ivestis. Is naujo iveskite %c: ", name);
        goto check;
    }
    printf("Skaicius nuskenuotas sekmingai\n");
}

int main()
{
    int a, b, c, i;
    int solutionFound = 0;

    printf("Iveskite 3 sveikus skaicius a, b ir c. Programa ras sveikus skaicius intervale (a; b], kurie dalinasi is skaiciaus c su liekana 1\n");

    getUserInput(&a, 'a');
    getUserInput(&b, 'b');
    getUserInput(&c, 'c');

    printf("salyga tenkinantys skaiciai:\n");

    //          while
    // while (++a <= b)
    // {
    //     if (a % c == 1)
    //     {
    //         solutionFound = 1;
    //         printf("%d\n", a);
    //     }
    // }

    //          for
    // for (++a; a <= b; ++a)
    // {
    //     if (a % c == 1)
    //     {
    //         solutionFound = 1;
    //         printf("%d\n", a);
    //     }
    // }

    //             do while

    // if (a < b)
    // {
    //     do
    //     {
    //         ++a;
    //         if (a % c == 1)
    //         {
    //             solutionFound = 1;
    //             printf("%d\n", a);
    //         }
    //     } while (a < b);
    // }

    //          if goto

    // check:
    //     if (++a % c == 1)
    //     {
    //         solutionFound = 1;
    //         printf("%d\n", a);
    //     }

    //     if (a < b)
    //     {
    //         goto check;
    //     }

    if (!solutionFound)
    {
        printf("Nera");
    }

    return 0;
}