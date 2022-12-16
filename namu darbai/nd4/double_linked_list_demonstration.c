#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

typedef struct Student
{
    int courseCount;
    int id;
} Student;

void printStudent(void *value)
{
    Student *student = (Student *)value;
    printf("student id: %d; number of courses: %d\n", student->id, student->courseCount);
}

int main()
{
    Node *head, *tail;

    Student *s1 = (Student *)malloc(sizeof(Student));
    Student *s2 = (Student *)malloc(sizeof(Student));
    Student *s3 = (Student *)malloc(sizeof(Student));
    Student *s4 = (Student *)malloc(sizeof(Student));

    s1->id = 1;
    s1->courseCount = 4;

    s2->id = 2;
    s2->courseCount = 3;

    s3->id = 3;
    s3->courseCount = 2;

    s4->id = 4;
    s4->courseCount = 1;

    if (initDLList(&head, &tail, s1, sizeof(Student)))
    {
        printf("Failed to init doubly linked list. Quiting\n");
    }
    else
    {
        printf("Double linked list initialized\n");
        printLinkedListFromTail(tail, printStudent);
        printf("\n\n");
    }

    if (addToHead(&head, s2, sizeof(Student)))
    {
        printf("failed to add to head s2");
    }
    else
    {
        printf("made s2 new head\n");
        printLinkedListFromTail(tail, printStudent);
        printf("\n\n");
    }

    if (addToTail(&tail, s3, sizeof(Student)))
    {
        printf("failed to add to tail s3");
    }
    else
    {
        printf("made s3 new tail\n");
        printLinkedListFromTail(tail, printStudent);
        printf("\n\n");
    }

    if (insertValueAtIndex(&tail, 1, s4, sizeof(Student)))
    {
        printf("failed to add to s4 as index 1");
    }
    else
    {
        printf("made s4 new index 1\n");
        printLinkedListFromTail(tail, printStudent);
        printf("\n\n");
    }

    s4->id = 999;
    s4->courseCount = 99999;
    if (setListValueByIndex(tail, s4, sizeof(Student), 0))
    {
        printf("failed to reset heads velue");
    }
    else
    {
        printf("reset heads value\n");
        printLinkedListFromTail(tail, printStudent);
        printf("\n\n");
    }

    if (deleteNodeByIndex(&tail, &head, 2))
    {
        printf("failed to delete node at index 2");
    }
    else
    {
        printf("deleted node at index 2\n");
        printLinkedListFromTail(tail, printStudent);
        printf("\n\n");
    }

    void *value = getValueByIndex(tail, 2);
    if (value == NULL)
    {
        printf("failed to get item at index 2");
    }
    else
    {
        s1 = (Student *)value;
        printf("getValueByIndex() at index 2 id:%d; courseCount:%d\n", s1->id, s1->courseCount);
        printLinkedListFromTail(tail, printStudent);
        printf("\n\n");
    }

    return 0;
}
