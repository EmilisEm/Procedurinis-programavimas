#include "stdio.h"
#include "string.h"

#define CORRECT_INPUT "Data accepted\n\n"
#define INCORRECT_INPUT "Data rejected\n"
#define REQUEST_INPUT "Please enter a whole number "
#define MSG_EXPLINATION "This program will make modifications to an array and allow you to do so as well. Initial array:\n"
#define MSG_PRINT_ARRAY "Array after modifications:\n"
#define MSG_ASIGNMENT "Please enter the index(x) of an array item and the value(y) to be asigned:\n"
#define MSG_DELETE "Please enter the index(x) of an array item to be deleted:\n"
#define MSG_INSERT "Please enter the index(x) of an array item and the value(y) to be inserted at the index:\n"

#define ARRAY_CAPACITY 10

int getInput(char msg)
{
    int num;
    while (1)
    {
        printf("%s%c :", REQUEST_INPUT, msg);
        if ((scanf("%d", &num) == 1) && (getchar() == '\n'))
        {
            if (((msg == 'x') && (num >= 0) && (num <= 9)) || (msg == 'y'))
            {
                printf("%s", CORRECT_INPUT);
                break;
            }
            else
            {
                printf("%s", INCORRECT_INPUT);
            }
        }

        else
        {
            printf("%s", INCORRECT_INPUT);
            scanf("%*[^\n]");
        }
    }

    return num;
}

void printArray(int array[], int arraySize)
{
    int i;

    printf("Array elements: ");
    for (i = 0; i < arraySize; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

void deleteArrayItem(int array[], int *arraySize, int index)
{
    int i;
    for (i = index; i < *arraySize; ++i)
    {
        array[i] = array[i + 1];
    }

    --(*arraySize);
}

void insertArrayItem(int array[], int *arraySize, int index, int value)
{
    int i;
    for (i = *arraySize; i > index; --i)
    {
        array[i] = array[i - 1];
    }

    array[index] = value;
    ++(*arraySize);
}

int main()
{
    int x, y;
    int array[ARRAY_CAPACITY] = {0};
    int arraySize = sizeof(array) / sizeof(*array);

    printf("%s", MSG_EXPLINATION);
    printArray(array, arraySize);

    array[0] = 1;
    array[3] = 2;
    array[9] = 3;

    deleteArrayItem(array, &arraySize, 2);
    insertArrayItem(array, &arraySize, 6, 4);

    printf("%s", MSG_PRINT_ARRAY);
    printArray(array, arraySize);

    printf("%s", MSG_ASIGNMENT);
    x = getInput('x');
    y = getInput('y');
    array[x] = y;

    printf("%s", MSG_DELETE);
    x = getInput('x');
    deleteArrayItem(array, &arraySize, x);

    printf("%s", MSG_INSERT);
    x = getInput('x');
    y = getInput('y');
    insertArrayItem(array, &arraySize, x, y);

    printArray(array, arraySize);

    return 0;
}