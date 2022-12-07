#include "stdio.h"
#include "math.h"

void getUserInput(int *num, char name)
{
    int incorrectInput = 1;

    printf("Iveskite %c: ", name);

    //              while

    // while (incorrectInput)
    // {
    //     if ((scanf("%d", num) == 1) && (getchar() == '\n'))
    //     {
    //         if (*num > 0)
    //         {
    //             incorrectInput = 0;
    //         }
    //         else
    //         {
    //             printf("Neteisinga ivestis. Is naujo iveskite %c: ", name);
    //         }
    //     }
    //     else
    //     {
    //         scanf("%*[^\n]");
    //         printf("Neteisinga ivestis. Is naujo iveskite %c: ", name);
    //     }
    // }

    //             do while

    // do
    // {
    //     if ((scanf("%d", num) == 1) && (getchar() == '\n'))
    //     {
    //         if (*num > 0)
    //         {
    //             incorrectInput = 0;
    //         }
    //         else
    //         {
    //             printf("Neteisinga ivestis. Is naujo iveskite %c: ", name);
    //         }
    //     }
    //     else
    //     {
    //         scanf("%*[^\n]");
    //         printf("Neteisinga ivestis. Is naujo iveskite %c: ", name);
    //     }
    // } while (incorrectInput);

    //      for

    // for (;incorrectInput;)
    // {
    //     if ((scanf("%d", num) == 1) && (getchar() == '\n'))
    //     {
    //         if (*num > 0)
    //         {
    //             incorrectInput = 0;
    //         }
    //         else
    //         {
    //             printf("Neteisinga ivestis. Is naujo iveskite %c: ", name);
    //         }
    //     }
    //     else
    //     {
    //         scanf("%*[^\n]");
    //         printf("Neteisinga ivestis. Is naujo iveskite %c: ", name);
    //     }
    // }

    //          if goto

check:
    if ((scanf("%d", num) == 1) && (getchar() == '\n'))
    {
        if (*num > 0)
        {
            incorrectInput = 0;
        }
        else
        {
            printf("Neteisinga ivestis. Is naujo iveskite %c: ", name);
            goto check;
        }
    }
    else
    {
        scanf("%*[^\n]");
        printf("Neteisinga ivestis. Is naujo iveskite %c: ", name);
        goto check;
    }

    printf("Skaicius nuskenuotas sekmingai\n");
}

int findLargestCommonFactor(int a, int b, int c)
{
    int i = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);

//      for

// for (; i > 0; --i)
// {
//     if ((a % i == 0) && (b % i == 0) && (c % i == 0))
//     {
//         return i;
//     }
// }

//      while

// while (i > 0)
// {
//     if ((a % i == 0) && (b % i == 0) && (c % i == 0))
//     {
//         return i;
//     }

//     --i;
// }

//      do while

// do
// {
//     if ((a % i == 0) && (b % i == 0) && (c % i == 0))
//     {
//         return i;
//     }

//     --i;
// } while (i > 0);

//      if goto
check:
    if ((a % i == 0) && (b % i == 0) && (c % i == 0))
    {
        return i;
    }

    --i;
    if (i > 0)
    {
        goto check;
    }
}

int findSmallestCommonMultipe(int a, int b, int c)
{
    int aNew = a, bNew = b, cNew = c;

    //          while

    // while (1)
    // {
    //     if ((aNew != bNew) || (bNew != cNew))
    //     {
    //         if (aNew < bNew || aNew < cNew)
    //         {
    //             aNew += a;
    //         }
    //         else if (bNew < aNew || bNew < cNew)
    //         {
    //             bNew += b;
    //         }
    //         else
    //         {
    //             cNew += c;
    //         }
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }

    //          for

    // for (;;)
    // {
    //     if ((aNew != bNew) || (bNew != cNew))
    //     {
    //         if (aNew < bNew || aNew < cNew)
    //         {
    //             aNew += a;
    //         }
    //         else if (bNew < aNew || bNew < cNew)
    //         {
    //             bNew += b;
    //         }
    //         else
    //         {
    //             cNew += c;
    //         }
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }

    //          do while

    // do
    // {
    //     if ((aNew != bNew) || (bNew != cNew))
    //     {
    //         if (aNew < bNew || aNew < cNew)
    //         {
    //             aNew += a;
    //         }
    //         else if (bNew < aNew || bNew < cNew)
    //         {
    //             bNew += b;
    //         }
    //         else
    //         {
    //             cNew += c;
    //         }
    //     }
    //     else
    //     {
    //         break;
    //     }
    // } while (1);

    //          if goto

check:
    if ((aNew != bNew) || (bNew != cNew))
    {
        if (aNew < bNew || aNew < cNew)
        {
            aNew += a;
            goto check;
        }
        else if (bNew < aNew || bNew < cNew)
        {
            bNew += b;
            goto check;
        }
        else
        {
            cNew += c;
            goto check;
        }
    }

    return aNew;
}

int main()
{
    int a, b, c;
    int solutionFound = 0;

    printf("Iveskite 3 naturaliusius skaicius a, b ir c. Programa ras skaiciu maziausia bendra dalikli ir didziausia bendra kartotini\n");

    getUserInput(&a, 'a');
    getUserInput(&b, 'b');
    getUserInput(&c, 'c');

    printf("Maziausias bendras kartotinis: %d\nDidziausias bendras daliklis: %d", findSmallestCommonMultipe(a, b, c), findLargestCommonFactor(a, b, c));

    return 0;
}