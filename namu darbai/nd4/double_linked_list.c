#include <stdlib.h>
#include <stdio.h>
#include "doubly_linked_list.h"

//          TO DO
//  1. Refactor so last node search for setValueByIndex(), insertValueAtIndex() is in function

// coppies size number of bytes from one location to another
void coppyBytes(void *destination, void *source, size_t size)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        *((char *)destination + i) = *((char *)source + i);
    }
}

// Creates double linked list. If fails returns NULL pointer
int initDLList(Node **tail, Node **head, void *value, size_t valueSize)
{
    void *valueLocation = malloc(valueSize);

    coppyBytes(valueLocation, value, valueSize);

    Node *newList = (Node *)malloc(sizeof(Node));

    if (newList == NULL)
    {
        return -1;
    }

    newList->value = valueLocation;
    newList->prev = NULL;
    newList->next = NULL;

    *head = newList;
    *tail = newList;
    return 0;
}

// Takes tail of list. Deletes all elements that follow
// Refactor so not recursion
void deleteDLList(Node **tail, Node **head)
{
    Node *next, *curr;

    curr = *tail;
    while (curr != NULL)
    {
        next = curr->next;
        free(curr->value);
        free(curr);
        curr = next;
    }

    *tail = NULL;
    *head = NULL;
}

// Takes start node. Returns the length of list
size_t getDLListLen(Node *tail)
{
    size_t length = 0;

    while (tail != NULL)
    {
        ++length;
        tail = tail->next;
    }

    return length;
}

// Reuturns uncast pointer to value at index or NULL on fail
void *getValueByIndex(Node *tail, size_t index)
{
    int i;
    for (i = 0; i < index; ++i)
    {
        if (tail == NULL)
        {
            return NULL;
        }
        tail = tail->next;
    }

    if (tail == NULL)
    {
        return NULL;
    }

    return tail->value;
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
int insertValueAtIndex(Node **tail, Node **head, size_t index, void *newValue, size_t valueSize)
{
    int i;
    Node *ref = *tail;
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
        addToTail(tail, newValue, valueSize);
        return 0;
    }
    else if (i == (index - 1))
    {
        addToHead(head, newValue, valueSize);
        return 0;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    void *nodeValue = malloc(valueSize);
    coppyBytes(nodeValue, newValue, valueSize);

    if (newNode == NULL || nodeValue == NULL)
    {
        return -1;
    }

    newNode->prev = ref->prev;
    ref->prev->next = newNode;
    newNode->next = ref;
    ref->prev = newNode;
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

int setValueByIndex(Node *tail, void *newValue, size_t valueSize, size_t index)
{
    for (; index > 0; --index)
    {
        if (tail == NULL)
        {
            return -1;
        }
        tail = tail->next;
    }
    if (tail == NULL)
    {
        return -1;
    }
    tail->value = realloc(tail->value, valueSize);
    if (tail->value != NULL)
    {
        coppyBytes(tail->value, newValue, valueSize);
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

int deleteNodeByRef(Node **tail, Node **head, Node *node)
{
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
        (*head)->next = NULL;
    }
    else if (node->prev == NULL)
    {
        *tail = node->next;
        (*tail)->prev = NULL;
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
