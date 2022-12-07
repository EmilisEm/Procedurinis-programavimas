#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateArray(int data[], int size, int low, int high);

int *createArray(int size, int low, int high);

void printArr(int *arr, int arrSize);

int main()
{
    int *arr = createArray(10, 10, 20);

    if (arr == NULL)
    {
        printf("is null");
    }

    printArr(arr, 10);
    return 0;
}

void generateArray(int *data, int size, int low, int high)
{
    int i;
    srand(time(NULL));

    for (i = 0; i < size; ++i)
    {
        *(data + i) = rand() % (high - low + 1) + low;
    }
}

int *createArray(int size, int low, int high)
{

    int *arr = calloc(size, sizeof(int));
    generateArray(arr, size, low, high);

    return arr;
}

void printArr(int *arr, int arrSize)
{
    int i;
    for (i = 0; i < arrSize; ++i)
    {
        printf("%d ", arr[i]);
    }
}