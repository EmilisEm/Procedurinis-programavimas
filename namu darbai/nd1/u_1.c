// Emilis Kleinas 6 uzduotis
// Programa nuskaito sveiku skaiciu eilute ir isspausdina kiek lyginiu sekos elementu buvo teigiami

#include <stdio.h>

// Function reads input and checks if the entered value is a whole number
int readNumber(int count)
{
    int num;
    while (1)
    {
        printf("Please enter the %d whole number: ", count);
        if (scanf("%d", &num) == 1 && getchar() == '\n')
        {
            printf("Data entered correctly\n\n");
            return num;
        }
        else
        {
            // Cleans buffer and askt to reapeat input
            printf("Entered value is not of specified format\n\n");
            scanf("%*[^\n]");
        }
    }
}

int main()
{
    int num, index = 1, evenPositiveCount = 0;

    printf("Enter a sequence of whole numbers terminated by a 0 and the program will output how many of the even numbered elements (2nd, 4th, 6th...) were positive.\n\n");

    // Scans numbers untill the input is 0
    while (1)
    {
        num = readNumber(index);

        if (num > 0 && (index % 2 == 0))
        {
            ++evenPositiveCount;
        }
        else if (!num)
        {
            break;
        }

        ++index;
    }

    // Prints results
    printf("There were %d entered positive numbers which were of an even count", evenPositiveCount);

    return 0;
}