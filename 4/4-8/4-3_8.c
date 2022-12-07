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
//         if (*num >= 0)
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

//          for

// for (;incorrectInput;)
// {
//     if ((scanf("%d", num) == 1) && (getchar() == '\n'))
//     {
//         if (*num >= 0)
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

//          do while

// do
// {
//     if ((scanf("%d", num) == 1) && (getchar() == '\n'))
//     {
//         if (*num >= 0)
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

//      if goto
check:
    if ((scanf("%d", num) == 1) && (getchar() == '\n'))
    {
        if (*num >= 0)
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

int getSequence(int element1, int element2, int elementCount)
{
    int element = 0;

    if (elementCount == 0)
    {
        return element1;
    }
    else if (elementCount == 1)
    {
        return element2;
    }
    else
    {
        element += getSequence(element1, element2, elementCount - 1) + getSequence(element1, element2, elementCount - 2);
    }

    return element;
}

int main()
{
    int a, b, c;
    int solutionFound = 0;

    printf("Iveskite 3 sveikus skaicius a, b ir c. Programa ras c-aji sekos d(c) = d(c-1) + d(c-2) nari, kai a = d(1), o b = d(2)\n");

    getUserInput(&a, 'a');
    getUserInput(&b, 'b');
    getUserInput(&c, 'c');

    if (c > 0)
    {
        printf("Sekos %d narys: %d", c, getSequence(a, b, c - 1));
    }

    else
    {
        printf("Prastas sekos nariu skaicus");
    }

    return 0;
}