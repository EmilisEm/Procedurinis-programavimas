#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "doubly_linked_list.h"

typedef struct Student
{
    int courseCount;
    int id;
} Student;

// Callback for printLinkedListFromTail(). Prints Student values
void printStudent(void *value)
{
    Student *student = (Student *)value;
    printf("student id: %d; number of courses: %d\n", student->id, student->courseCount);
}

void initDLListTest(Node **head, Node **tail, Student *s1)
{
    int testPass = initDLList(head, tail, s1, sizeof(Student));
    // Checks if list initialized
    assert(!testPass);

    printf("initDLList(): success\n");
    printLinkedListFromTail(*tail, printStudent);
    printf("\n\n");
}

void addToHeadTest(Node **head, Node **tail, Student *s2)
{
    int testPass = addToHead(head, s2, sizeof(Student));
    // Checks if function failed
    assert(!testPass);
    // Checks if value was added
    assert(*head != NULL);
    // Checks if added at right location
    assert((*head)->next == NULL);
    // Checks if pointer to head was moved
    assert(*head != *tail);

    printf("addToHead(): success\n");
    printLinkedListFromTail(*tail, printStudent);
    printf("\n\n");
}

void addToTailTest(Node **tail, Node **head, Student *s3)
{
    int testPass = addToTail(tail, s3, sizeof(Student));
    // Checks if function failed
    assert(!testPass);
    // Checks if value was added
    assert(*tail != NULL);
    // Checks if added at right location
    assert((*tail)->prev == NULL);
    // Checks if pointer to head was moved
    assert(*head != *tail);

    printf("addToTail(): success\n");
    printLinkedListFromTail(*tail, printStudent);
    printf("\n\n");
}

void getValueByIndexTest(Node **tail, Node **head)
{
    void *value = getValueByIndex(*tail, 100);
    // Checks if function failed
    assert(value == NULL);

    // gets value at head so should have the same values
    value = getValueByIndex(*tail, 2);
    assert(value != NULL);
    Student *s1 = (Student *)value;
    Student *s2 = (Student *)((*head)->value);
    // Checks if value is correct
    assert(s1->id == s2->id);

    // gets value at head so should have the same values
    value = getValueByIndex(*tail, 0);
    assert(value != NULL);
    s1 = (Student *)value;
    s2 = (Student *)((*tail)->value);
    // Checks if value is correct
    assert(s1->id == s2->id);

    // gets value at head so should have the same values
    value = getValueByIndex(*tail, 1);
    assert(value != NULL);
    s1 = (Student *)value;
    s2 = (Student *)((*tail)->next->value);
    // Checks if value is correct
    assert(s1->id == s2->id);

    printf("getValueByIndex(): success\n");
    printLinkedListFromTail(*tail, printStudent);
    printf("\n\n");
}

void insertValueAtIndexTest(Node **tail, Node **head, Student *s4)
{
    s4->id = 77;
    int prevLen = getDLListLen(*tail), newLen;
    int testPass = insertValueAtIndex(tail, head, 1, s4, sizeof(Student));
    // Checks if function failed
    assert(!testPass);
    newLen = getDLListLen(*tail);

    // Check if new item was added at middle
    assert((prevLen - newLen) == -1);
    void *value = getValueByIndex(*tail, 1);
    Student *s1 = (Student *)value;

    // Check if right value was set
    assert(s1->id == s4->id);

    prevLen = newLen;
    testPass = insertValueAtIndex(tail, head, 0, s4, sizeof(Student));

    assert(!testPass);
    newLen = getDLListLen(*tail);

    assert((prevLen - newLen) == -1);

    value = getValueByIndex(*tail, 0);
    s1 = (Student *)value;

    // Check if right value was set
    assert(s1->id == s4->id);

    prevLen = newLen;
    testPass = insertValueAtIndex(tail, head, newLen, s4, sizeof(Student));

    assert(!testPass);
    newLen = getDLListLen(*tail);

    assert((prevLen - newLen) == -1);

    value = getValueByIndex(*tail, prevLen);
    s1 = (Student *)value;

    // Check if right value was set
    assert(s1->id == s4->id);

    printf("insertValueAtIndex(): success\n");
    printLinkedListFromTail(*tail, printStudent);
    printf("\n\n");
}

void setValueByIndexTest(Node **tail, Node **head, Student *s4)
{
    s4->id = 999;
    s4->courseCount = 999;
    int testPass = setValueByIndex(*tail, s4, sizeof(Student), 0);
    // Check if function failed
    assert(!testPass);
    void *value = getValueByIndex(*tail, 0);
    Student *s1 = (Student *)value;
    Student *s2 = (Student *)((*tail)->value);
    // Check if value was set
    assert(s1->id == s4->id);
    // Check if tail was modified
    assert(s2->id == s4->id);

    testPass = setValueByIndex(*tail, s4, sizeof(Student), getDLListLen(*tail) - 1);
    // Check if function failed
    assert(!testPass);
    value = getValueByIndex(*tail, getDLListLen(*tail) - 1);
    s1 = (Student *)value;
    s2 = (Student *)((*head)->value);
    // Check if value was set
    assert(s1->id == s4->id);
    // Check if tail was modified
    assert(s2->id == s4->id);

    testPass = setValueByIndex(*tail, s4, sizeof(Student), getDLListLen(*tail) - 2);
    // Check if function failed
    assert(!testPass);
    value = getValueByIndex(*tail, getDLListLen(*tail) - 2);
    s1 = (Student *)value;
    s2 = (Student *)((*head)->prev->value);
    // Check if value was set
    assert(s1->id == s4->id);
    // Check if tail was modified
    assert(s2->id == s4->id);

    testPass = setValueByIndex(*tail, s4, sizeof(Student), getDLListLen(*tail) + 10);
    // Check if function failed
    assert(testPass == -1);

    printf("setValueByIndex(): success\n");
    printLinkedListFromTail(*tail, printStudent);
    printf("\n\n");
}

void deleteNodeByIndexTest(Node **tail, Node **head)
{
    Node *temp1;
    temp1 = (*head)->prev;

    int prevLen = getDLListLen(*tail);
    int testPass = deleteNodeByIndex(tail, head, getDLListLen(*tail) - 1);
    assert(!testPass);
    int newLen = getDLListLen(*tail);
    assert((prevLen - newLen) == 1);
    assert(*head == temp1);

    temp1 = (*tail)->next;
    prevLen = newLen;
    testPass = deleteNodeByIndex(tail, head, 0);
    assert(!testPass);
    newLen = getDLListLen(*tail);
    assert((prevLen - newLen) == 1);
    assert(*tail == temp1);

    temp1 = (*tail)->next->next;
    prevLen = newLen;
    testPass = deleteNodeByIndex(tail, head, 1);
    assert(!testPass);
    newLen = getDLListLen(*tail);
    assert((prevLen - newLen) == 1);
    assert((*tail)->next == temp1);

    printf("deleteNodeByIndex(): success\n");
    printLinkedListFromTail(*tail, printStudent);
    printf("\n\n");
}

int main()
{
    Node *head, *tail;
    int testPass = 1;

    Student *s1 = (Student *)malloc(sizeof(Student));
    Student *s2 = (Student *)malloc(sizeof(Student));
    Student *s3 = (Student *)malloc(sizeof(Student));
    Student *s4 = (Student *)malloc(sizeof(Student));
    void *value;
    s1->id = 1;
    s1->courseCount = 4;

    s2->id = 2;
    s2->courseCount = 3;

    s3->id = 3;
    s3->courseCount = 2;

    s4->id = 4;
    s4->courseCount = 1;

    initDLListTest(&head, &tail, s1);
    addToHeadTest(&head, &tail, s2);
    addToTailTest(&tail, &head, s3);
    getValueByIndexTest(&tail, &head);
    insertValueAtIndexTest(&tail, &head, s4);
    setValueByIndexTest(&tail, &head, s4);
    deleteNodeByIndexTest(&tail, &head);

    printf("\n\n");
    printf("ALL TEST PASSED");

    free(s1);
    free(s2);
    free(s3);
    free(s4);
    deleteDLList(&tail, &head);
    return 0;
}
