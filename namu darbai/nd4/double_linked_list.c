#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    void *value;
    size_t valueSize;
    struct Node *prev;
    struct Node *next;
} Node;

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
int initDLList(Node **head, Node **tail, void *value, size_t valueSize)
{
    void *valueLocation = malloc(valueSize);

    coppyBytes(valueLocation, value, valueSize);

    Node *newList = (Node *)malloc(sizeof(Node));

    if (newList == NULL)
    {
        return -1;
    }

    newList->value = valueLocation;
    newList->valueSize = valueSize;
    newList->prev = NULL;
    newList->next = NULL;

    *head = newList;
    *tail = newList;
    return 0;
}

// Takes tail of list. Deletes all elements that follow
void deleteDLList(Node *DLList)
{
    Node *next;
    next = DLList->next;

    if (next != NULL)
    {
        deleteDLList(next);
    }

    free(DLList->value);
    free(DLList);

    DLList = NULL;
}

// Takes start node. Returns the length of list
size_t getDLListLen(Node *Dll)
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
void *getValueByIndex(Node *Dll, size_t index)
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

    if (Dll == NULL)
    {
        return NULL;
    }

    return Dll->value;
}

int addToTail(Node **tail, void *value, size_t valueSize)
{
    if (*tail == NULL)
    {
        return -1;
    }
    void *nodeValue = malloc(valueSize);
    coppyBytes(nodeValue, value, valueSize);

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return -1;
    }

    newNode->next = *tail;
    newNode->prev = NULL;
    newNode->value = nodeValue;
    (*tail)->prev = newNode;
    *tail = newNode;

    return 0;
}

int addToHead(Node **head, void *value, size_t valueSize)
{
    if (*head == NULL)
    {
        return -1;
    }
    void *nodeValue = malloc(valueSize);
    coppyBytes(nodeValue, value, valueSize);

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return -1;
    }

    newNode->prev = *head;
    newNode->next = NULL;
    newNode->value = nodeValue;
    (*head)->next = newNode;
    *head = newNode;

    return 0;
}

// Returns 0 on successful insertion. -1 if fails
int insertValueAtIndex(Node **Dll, size_t index, void *newValue, size_t valueSize)
{
    int i;
    Node *ref = *Dll;
    if (ref == NULL)
    {
        return -1;
    }
    for (i = 0; i < index; ++i)
    {
        if (ref->next == NULL && (i != (index - 1)))
        {
            return -1;
        }
        else if (ref->next == NULL && (i == (index - 1)))
        {
            break;
        }
        ref = ref->next;
    }

    if (index == 0)
    {
        addToTail(Dll, newValue, valueSize);
        return 0;
    }
    else if (i == (index - 1))
    {
        addToHead(Dll, newValue, valueSize);
        return 0;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    void *nodeValue = malloc(valueSize);
    coppyBytes(nodeValue, newValue, valueSize);

    if (newNode == NULL || nodeValue == NULL)
    {
        return -1;
    }

    if (ref != NULL && ref->prev != NULL)
    {
        newNode->prev = ref->prev;
        ref->prev->next = newNode;
        newNode->next = ref;
        ref->prev = newNode;
    }

    newNode->value = nodeValue;
    return 0;
}

int setValueByNode(Node *node, void *newValue, size_t valueSize)
{
    if (node == NULL)
    {
        return -1;
    }
    node->value = realloc(node->value, valueSize);
    if (node->value == NULL)
    {
        return -1;
    }
    coppyBytes(node->value, newValue, valueSize);
    return 0;
}

int setListValueByIndex(Node *head, void *newValue, size_t valueSize, size_t index)
{
    for (; index > 0; --index)
    {
        if (head == NULL)
        {
            return -1;
        }
        head = head->next;
    }
    if (head == NULL)
    {
        return -1;
    }
    head->value = realloc(head->value, valueSize);
    if (head->value != NULL)
    {
        coppyBytes(head->value, newValue, valueSize);
        return 0;
    }
    return -1;
}

// To do. Refactor function deleteNodeByIndex
int deleteNodeByIndex(Node **tail, Node **head, int index)
{
    Node *node = *tail;

    for (; index > 0; --index)
    {
        if (node == NULL)
        {
            return -1;
        }
        node = node->next;
    }

    if (node == NULL)
    {
        return -1;
    }

    if (node->prev != NULL && node->next != NULL)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    else if (node->prev == NULL && node->next == NULL)
    {
        *tail = NULL;
        *head = NULL;
    }
    else if (node->next == NULL)
    {
        *head = node->prev;
        node->prev->next = NULL;
    }
    else if (node->prev == NULL)
    {
        *tail = node->next;
        node->next->prev = NULL;
    }

    free(node->value);
    free(node);
    return 0;
}

void printLinkedListFromTail(Node *tail, void (*printFunction)(void *value))
{
    while (tail != NULL)
    {
        printFunction(tail->value);
        tail = tail->next;
    }
}

void printInt(void *value)
{
    int num = *((int *)value);
    printf("%d ", num);
}

int main(int argc, char const *argv[])
{
    int value = 0;

    Node *head, *tail;

    if (initDLList(&head, &tail, &value, sizeof(value)))
    {
        printf("Failed to initialize list\n");
    }
    else
    {
        printf("Successfuly initialised list\n");
    }
    ++value;
    printf("%d add 1 to tail\n", addToTail(&tail, &value, sizeof(value)));
    ++value;
    printf("%d add 2 to tail\n", addToTail(&tail, &value, sizeof(value)));
    ++value;
    printf("%d add 3 to head\n", addToHead(&head, &value, sizeof(value)));
    ++value;
    printf("%d insert 4 at index 2\n", insertValueAtIndex(&tail, 2, &value, sizeof(value)));

    printf("%d set value at index 0 to value 4\n", setListValueByIndex(tail, &value, sizeof(value), 0));

    printf("%d delete value at index 1\n", deleteNodeByIndex(&tail, &head, 1));
    value = 99;
    printf("%d set tail value to 99\n", setValueByNode(tail, &value, sizeof(value)));
    printLinkedListFromTail(tail, printInt);

    printf("\n%d is value at index 2\n", *((int *)getValueByIndex(tail, 3)));
    int *valuePtr = (int *)tail->value;
    printf("value at tail: %d; List length: %d\n", *valuePtr, getDLListLen(tail));

    deleteDLList(tail);

    return 0;
}
