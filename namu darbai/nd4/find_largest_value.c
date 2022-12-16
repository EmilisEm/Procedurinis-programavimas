#include <stdio.h>
#include "doubly_linked_list.h"

int removeLargest(Node **head, Node **tail, int (*compare)(void *, void *))
{
    if (*tail == NULL)
    {
        return -1;
    }

    Node *toRemove = *tail;
    Node *ref = *tail;

    while (ref->next != NULL)
    {
        ref = ref->next;

        if (compare(ref->value, toRemove->value) > 0)
        {
            toRemove = ref;
        }
    }
    ref = *tail;

    while (ref != NULL)
    {
        if (compare(toRemove, ref) == 0)
        {
            deleteNodeByRef(head, tail, toRemove);
        }
        ref = ref->next;
    }
}

int compare(void *value1, void *value2)
{
    int *num1, *num2;

    num1 = (int *)value1;
    num2 = (int *)value2;

    return *num1 - *num2;
}

int main()
{
    Node *head, *tail;
    int value = 0;

    initDLList(&head, &tail, &value, sizeof(int));
    ++value;
    addToHead(&head, &value, sizeof(value));
    ++value;
    addToHead(&head, &value, sizeof(value));
    ++value;
    addToHead(&head, &value, sizeof(value));
    ++value;
    addToHead(&head, &value, sizeof(value));
    ++value;
    addToHead(&head, &value, sizeof(value));
    value = 123;
    setValueByIndex(tail, &value, sizeof(value), 2);

    printLinkedListFromTail(tail, printInt);
    printf("\n");
    removeLargest(&head, &tail, compare);
    printLinkedListFromTail(tail, printInt);

    return 0;
}
