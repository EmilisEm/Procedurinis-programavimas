#include <stdio.h>

void quickSort(int arr[], int low, int high);
void quickSortNoRec(int arr[], int low, int high);
int partition(int arr[], int low, int high);
int medianOfThree(int arr[], int a, int b, int c);
void swap(int *a, int *b);

void printArr(int arr[], int len)
{
    int i;
    for (i = 0; i < len; ++i)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{

    // Recursive function
    int arr[] = {8, 7, 79, 2, 8, 12, 2, 7, 4}, i;
    printArr(arr, sizeof(arr) / sizeof(int));
    printf("\n");

    quickSortNoRec(arr, 0, sizeof(arr) / sizeof(int) - 1);

    printArr(arr, sizeof(arr) / sizeof(int));

    // Non recursive
    return 0;
}

// Main quicksort function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void quickSortNoRec(int arr[], int low, int high)
{
    int stack[high - low + 1];
    int p;
    int top = -1;

    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0)
    {
        high = stack[top--];
        low = stack[top--];

        p = partition(arr, low, high);

        if (low < p - 1)
        {
            stack[++top] = low;
            stack[++top] = p - 1;
        }
        if (p + 1 < high)
        {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }
}

// Sets median value to its correct position
int partition(int arr[], int low, int high)
{
    int pivot = medianOfThree(arr, low, high, (low + high) / 2);
    swap(arr + pivot, arr + high);
    pivot = arr[high];
    int pi = low - 1, i;

    for (i = low; i < high; ++i)
    {

        if (arr[i] < pivot)
        {
            ++pi;
            swap(arr + pi, arr + i);
        }
    }

    swap(arr + pi + 1, arr + high);

    return pi + 1;
}

// Returns the median of the three ints
int medianOfThree(int arr[], int a, int b, int c)
{
    if ((arr[a] >= arr[b] && arr[a] <= arr[c]) || (arr[a] >= arr[c] && arr[a] <= arr[b]))
    {
        return a;
    }
    else if ((arr[c] >= arr[b] && arr[c] <= arr[a]) || (arr[c] >= arr[a] && arr[c] <= arr[b]))
    {
        return c;
    }
    else
    {
        return b;
    }
}

// Swaps two ints i
void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
