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
    while ((scanf("%lf", &input) != 1) || (getchar() != '\n'))
    {
        scanf("%*[^\n]");
        printf("%s%s", INCORRECT_INPUT_MSG, INPUT_NUM_MSG);
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
    while (incorrectInput)
    {
        if ((scanf("%d", &n) == 1) && (getchar() == '\n'))
        {
            if (n >= 0)
            {
                printf("%s", CORRECT_INPUT_MSG);
                incorrectInput = 0;
            }
        }
        else
        {
            scanf("%*[^\n]");
            printf("%s%s", INCORRECT_INPUT_MSG, INPUT_N_MSG);
        }
    }

    // Checks if n != 0. Gets n real numbers
    if (n > 0)
    {
        temp = getUserInput();
        sum += temp;
        minimum = temp;
        maximum = temp;

        for (i = 1; i < n; ++i)
        {
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
        }

        printf("%s%lf\n%s%lf\n%s%lf\n%s%lf", SUM_MSG, sum, AVG_MSG, sum / n, MIN_MSG, minimum, MAX_MSG, maximum);
    }
    else
    {
        printf("%s", NO_INPUT);
    }

    return 0;
}