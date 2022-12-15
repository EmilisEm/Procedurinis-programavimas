#include <stdlib.h>
#include <stdio.h>

typedef struct DoubleLinkedList
{
    void *value;
    size_t valueSize;
    struct DoubleLinkedList *prev;
    struct DoubleLinkedList *next;
} DoubleLinkedList;

//          TO DO
//  1. Refactor so last node search for setValueByIndex(), insertValueAtIndex() is in function

// coppies size number of bytes from one location to another
void coppyBytes(void *destination, void *source, size_t size)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        *(((char *)destination) + i) = *(((char *)source) + i);
    }
}

// Creates double linked list. If fails returns NULL pointer
DoubleLinkedList *initDLList(void *value, size_t valueSize)
{
    void *valueLocation = malloc(valueSize);

    coppyBytes(valueLocation, value, valueSize);

    DoubleLinkedList *newList = (DoubleLinkedList *)malloc(sizeof(DoubleLinkedList));

    if (newList == NULL)
    {
        return NULL;
    }

    newList->value = valueLocation;
    newList->valueSize = valueSize;
    newList->prev = NULL;
    newList->next = NULL;

    return newList;
}

// Takes root of list. Deletes all elements that follow
void deleteDLList(DoubleLinkedList *DLList)
{
    DoubleLinkedList *next;
    next = DLList->next;

    if (next != NULL)
    {
        deleteDLList(next);
    }

    free(DLList->value);
    free(DLList);
}

// Takes start node. Returns the length of list
size_t getDLListLen(DoubleLinkedList *Dll)
{
    size_t length = 0;

    while (Dll != NULL)
    {
        ++length;
        Dll = Dll->next;
    }

    return length;
}

// Reuturns uncast pointer to value at index or NULL on fail
void *getValueByIndex(DoubleLinkedList *Dll, size_t index)
{
    int i;
    for (i = 0; i < index; ++i)
    {
        if (Dll == NULL)
        {
            return NULL;
        }
        Dll = Dll->next;
    }

    return Dll->value;
}

// Sets value of double linked list at index. Reutrns -1 on fail
int setValueAtIndex(DoubleLinkedList *Dll, size_t index, void *newValue, size_t valueSize)
{
    int i;
    for (i = 0; i < index; ++i)
    {
        if (Dll == NULL)
        {
            return -1;
        }
        Dll = Dll->next;
    }

    Dll->value = realloc(Dll->value, valueSize);

    if (Dll->value == NULL)
    {
        return -1;
    }

    coppyBytes(Dll->value, newValue, valueSize);
    return 0;
}

// Returns 0 on successful insertion. -1 if fails
int insertDLLValueAtIndex(DoubleLinkedList *Dll, size_t index, void *newValue, size_t valueSize)
{
    int i;

    for (i = 0; i < index; ++i)
    {
        if (Dll->next == NULL && (i != (index - 1)))
        {
            return -1;
        }
        Dll = Dll->next;
    }

    DoubleLinkedList *newNode = initDLList(newValue, valueSize);
    if (newNode == NULL)
    {
        return -1;
    }

    if (Dll != NULL && Dll->prev != NULL)
    {
        newNode->prev = Dll->prev;
        Dll->prev->next = newNode;
    }

    printf("here");
    newNode->next = Dll;
    Dll->prev = newNode;
    return 0;
}

int main(int argc, char const *argv[])
{
    int value = 123;
    int value2 = 123456;
    DoubleLinkedList *newList = initDLList(&value, sizeof(value));

    int *valuePtr = (int *)newList->value;
    insertDLLValueAtIndex(newList, 1, &value2, sizeof(value2));
    printf("%d %d", *valuePtr, getDLListLen(newList));

    return 0;
}
