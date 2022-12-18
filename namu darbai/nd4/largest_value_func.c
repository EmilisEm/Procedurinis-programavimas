#include <stdlib.h>
#include "doubly_linked_list.h"

int removeSmallest(Node **tail, Node **head, int (*compare)(void *, void *))
{
    if (*tail == NULL)
    {
        return -1;
    }

    Node *toRemove = *tail;
    Node *ref = *tail;
    Node *tempRef;

    while (ref->next != NULL)
    {
        ref = ref->next;

        if (compare(ref->value, toRemove->value) <= 0)
        {
            toRemove = ref;
        }
    }
    ref = *tail;
    int lastInteration = 0;

    while (ref != NULL)
    {
        // Works on gcc but looks sketchy. In itterations after removal of last larges value is comparing to random memory
        // Could be fixed by creating a copy of largest element and using copy in compare
        if (compare(toRemove->value, ref->value) == 0)
        {
            if (toRemove == ref)
            {
                lastInteration = 1;
            }
            tempRef = ref;
            ref = ref->next;
            deleteNodeByRef(tail, head, tempRef);
            if (lastInteration)
            {
                break;
            }
        }
        else
        {
            ref = ref->next;
        }
    }

    return 0;
}