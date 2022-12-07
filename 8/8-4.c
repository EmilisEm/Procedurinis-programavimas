#include <stdio.h>
#include <stdlib.h>

int splitData(int *arr, int arrSize, int pivot, int **arr1, int **arr2);

void printArr(int *arr, int arrSize);

int main()
{
    int *a, *b;
    int arr[] = {
        1,
        2,
        3,
        4,
        6,
        8,
        7,
        5,
        9,
    };

    if (splitData(arr, 9, 5, &a, &b))
    {
        printf("error in split data. quiting");
        return 0;
    }
    printArr(a, 5);
    printf("\n");
    printArr(b, 4);
    return 0;
}

int splitData(int *arr, int arrSize, int pivot, int **arr1, int **arr2)
{
    // Validates that all params ar valid
    if (arrSize >= 0 && arr != NULL && pivot < arrSize && pivot >= 0)
    {
        int *a = malloc(pivot * sizeof(int));
        int *b = malloc((arrSize - pivot) * sizeof(int));

        if (a == NULL || b == NULL)
        {
            return -1;
        }

        int i;

        for (i = 0; i < arrSize; ++i)
        {
            if (i < pivot)
            {
                a[i] = arr[i];
            }
            else
            {
                b[i - pivot] = arr[i];
            }
        }

        *arr1 = a;
        *arr2 = b;

        return 0;
    }
    return -1;
}

void printArr(int *arr, int arrSize)
{
    int i;
    for (i = 0; i < arrSize; ++i)
    {
        printf("%d ", arr[i]);
    }
}