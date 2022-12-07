/**
Autorius:
Emilis Kleinas

Veikimas:
Įvedus sveikų desimtainiu skaičių seką suskaičiuoja lyginių (antro, ketvirto, šešto...) teigiamų narių skaičių.
Skaičius reikia įvesti po vieną. Jei bus bandomą įvesti du skaičius vienu metu programa jų nepriims.
Sekos pabaigą žymi skaičius 0. Jis nėra laikomas sekos nariu.
**/
#include "stdio.h"

int main()
{
    // Skaicius teigiamu lyginiu nariu
    int numOfEven = 0;
    // Kintamasis skenuojamu skaiciu reiksmei laikyti
    int temp = -1;
    // Sekos nariu skaicius
    int count = 0;

    printf("Ivedus sveiku desimtainiu skaiciu seka programa suskaiciuoja lyginiu (antro, ketvirto, sesto...) teigiamu nariu skaiciu. Skaicius reikia ivesti po viena. Jei bus bandoma ivesti du skaicius vienu metu programa ju nepriims. Sekos pabaiga zymi skaicius 0. Jis nera laikomas sekos nariu.\n\n");

    while (temp != 0)
    {
        printf("Iveskite %d skaiciu: ", count + 1);

        if ((scanf("%d", &temp) == 1) && (getchar() == '\n'))
        {
            if (temp == 0)
            {
                printf("Skaiciu seka uzbaigta\n\n");
            }
            else
            {
                printf("Skaicius nuskenuotas sekmingai\n\n");
                count++;
                if ((count % 2 == 0) && (temp > 0))
                {
                    numOfEven++;
                }
            }
        }
        else
        {
            printf("Prasau ivesti viena sveikaji desimtaini skaiciu\n");

            // Jei input butų simbolių kratinys, kuris prasideda 0, jį nuskenuotų
            // į kintamąjį temp ir būtų užbaigtas ciklas
            temp = -1;

            // Išvalomas stream buffer
            scanf("%*[^\n]");
        }
    }
    printf("Is viso rasta teigiamu lyginiu nariu: %d", numOfEven);

    return 0;
}