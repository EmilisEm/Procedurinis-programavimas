#include "stdio.h"
#include "math.h"

void getUserInput(int *num, char name)
{
    printf("Iveskite %c: ", name);
    while ((scanf("%d", num) != 1) || (getchar() != '\n'))
    {
        scanf("%*[^\n]");
        printf("Neteisinga ivestis. Is naujo iveskite %c: ", name);
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
    for (++a; a <= b; ++a)
    {
        if (a % c == 1)
        {
            solutionFound = 1;
            printf("%d\n", a);
        }
    }

    if (!solutionFound)
    {
        printf("Nera");
    }

    return 0;
}