#include <stdlib.h>
#include "doubly_linked_list.h"

int removeLargest(Node **head, Node **tail, int (*compare)(void *, void *))
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

        if (compare(ref->value, toRemove->value) >= 0)
        {
            toRemove = ref;
        }
    }
    ref = *tail;
    while (ref != NULL)
    {
        // Works on gcc but looks sketchy. In itterations after removal of last larges value is comparing to random memory
        // Could be fixed by creating a copy of largest element and using copy in compare
        if (compare(toRemove->value, ref->value) == 0)
        {
            tempRef = ref;
            ref = ref->next;
            deleteNodeByRef(head, tail, tempRef);
        }
        else
        {
            ref = ref->next;
        }
    }
}