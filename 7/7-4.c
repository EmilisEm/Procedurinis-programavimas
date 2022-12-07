#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void generateArray(int data[], int size, int low, int high);

int main()
{
    int arr[15], i;
    generateArray(arr, 15, 10, 20);

    printf("A generated array of values between 10 and 20: ");
    for (i = 0; i < 15; ++i)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void generateArray(int data[], int size, int low, int high)
{
    int i;
    srand(time(NULL));

    for (i = 0; i < size; ++i)
    {
        data[i] = rand() % (high - low + 1) + low;
    }
}