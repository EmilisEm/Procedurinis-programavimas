#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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

void valueToStudent(void *value, Student *student)
{
    student = (Student *)value;
}

int main()
{
    Node *head, *tail;
    int testPass = 1;

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

    testPass = initDLList(&head, &tail, s1, sizeof(Student));
    // Checks if list initialized
    assert(!testPass);

    printf("Double linked list initialized\n");
    printLinkedListFromTail(tail, printStudent);
    printf("\n\n");

    testPass = addToHead(&head, s2, sizeof(Student));
    // Checks if function failed
    assert(!testPass);
    // Checks if value was added
    assert(head != NULL);
    // Checks if added at right location
    assert(head->next == NULL);
    // Checks if pointer to head was moved
    assert(head != tail);

    printf("made new head\n");
    printLinkedListFromTail(tail, printStudent);
    printf("\n\n");

    testPass = addToTail(&tail, s3, sizeof(Student));
    // Checks if function failed
    assert(!testPass);
    // Checks if was added
    assert(tail != NULL);
    // Checks if added at right location
    assert(tail->prev == NULL);
    // Checks if pointer to tail was moved
    assert(tail != head);

    printf("made s3 new tail\n");
    printLinkedListFromTail(tail, printStudent);
    printf("\n\n");

    void *value = getValueByIndex(tail, 2);
    // Checks if function failed
    assert(value != NULL);
    // gets value at head so should have the same values
    s1 = (Student *)value;
    s2 = (Student *)(head->value);
    // Checks if value is correct
    assert(s1->id == s2->id);

    printf("Got value with getValueByIndex() at index 2\n");
    printLinkedListFromTail(tail, printStudent);
    printf("\n\n");

    int prevLen = getDLListLen(tail), newLen;
    testPass = insertValueAtIndex(&tail, &head, 1, s4, sizeof(Student));
    // Checks if function failed
    assert(!testPass);
    newLen = getDLListLen(tail);

    // Check if new item was added
    assert((prevLen - newLen) == -1);

    value = getValueByIndex(tail, 1);
    s1 = (Student *)value;

    // Check if right value was set
    assert(s1->id == s4->id);

    printf("made s4 new index 1\n");
    printLinkedListFromTail(tail, printStudent);
    printf("\n\n");

    s4->id = 999;
    s4->courseCount = 99999;
    testPass = setValueByIndex(tail, s4, sizeof(Student), 0);
    // Check if function failed
    assert(!testPass);
    value = getValueByIndex(tail, 0);
    s1 = (Student *)value;
    s2 = (Student *)(tail->value);
    // Check if value was set
    assert(s1->id == s4->id);
    // Check if tail was modified
    assert(s2->id == s1->id);

    printf("reset heads value\n");
    printLinkedListFromTail(tail, printStudent);
    printf("\n\n");

    prevLen = getDLListLen(tail);
    testPass = deleteNodeByIndex(&tail, &head, 2);
    newLen = getDLListLen(tail);
    assert(!testPass);
    assert((prevLen - newLen) == 1);

    printf("deleted node at index 2\n");
    printLinkedListFromTail(tail, printStudent);
    printf("\n\n");
    printf("ALL TEST PASSED");

    free(s1);
    free(s2);
    free(s3);
    free(s4);
    deleteDLList(&tail, &head);
    return 0;
}
