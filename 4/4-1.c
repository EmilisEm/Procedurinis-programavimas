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
    int a, b, c;
    double dis;
    printf("Iveskite 3 sveikus skaicius a, b ir c. Programa paskaiciuos kiek sprendiniu turi lygits ax^2 + bx + c = 0 ir kokie jie\n");

    getUserInput(&a, 'a');
    getUserInput(&b, 'b');
    getUserInput(&c, 'c');

    if (a == 0)
    {
        printf("Sprendiniu skaicius: 1\nSprendinys: %f", (float)(-c) / b);
    }
    else
    {
        dis = b * b - 4 * a * c;

        if (dis == 0)
        {
            printf("Sprendiniu skaicius: 1\nSprendinys: %f", (float)(-b) / (2 * a));
        }
        else if (dis > 0)
        {
            printf("Sprendiniu skaicius: 2\nSprendinys 1: %lf\nSprendinys 2: %lf", (-b + sqrt(dis)) / (2 * a), (-b - sqrt(dis)) / (2 * a));
        }
        else
        {
            printf("Lygtis neturi sprendiniu");
        }
    }

    return 0;
}