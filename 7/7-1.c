#include <stdio.h>

int isInRange(int number, int low, int high);

int main()
{
    printf("Number = 6, low = 6, high = 7 | output: %d\n", isInRange(6, 6, 7));
    printf("Number = 9, low = 6, high = 7 | output: %d\n", isInRange(9, 6, 7));
    printf("Number = 7, low = 6, high = 8 | output: %d\n", isInRange(7, 6, 8));
    printf("Number = 7, low = 6, high = 7 | output: %d\n", isInRange(7, 6, 7));
    printf("Number = 5, low = 6, high = 7 | output: %d\n", isInRange(5, 6, 7));
    return 0;
}

int isInRange(int number, int low, int high)
{
    if (number <= high && number >= low)
    {
        return 1;
    }

    return 0;
}
