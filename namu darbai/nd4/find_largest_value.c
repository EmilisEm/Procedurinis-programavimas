#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"
#include "largest_val_func.h"

typedef struct Student
{
    int courseCount;
    int id;
} Student;

int compare(void *value1, void *value2)
{
    Student *s1, *s2;

    s1 = (Student *)value1;
    s2 = (Student *)value2;

    return s1->id - s2->id;
}

int getDigitFromUser(char *promptRequest, char *promptCorrect, char *promptIncorrect, int min, int max)
{
    int rValue;

    while (1)
    {
        printf("%s", promptRequest);
        if (scanf("%d", &rValue) == 1 && getchar() == '\n')
        {
            if (rValue >= min && rValue <= max)
            {
                return rValue;
            }
            printf("%s", promptIncorrect);
        }
        else
        {
            scanf("%*[^\n]");
            printf("%s", promptIncorrect);
        }
    }
}

void printStudent(void *value)
{
    Student *student = (Student *)value;
    printf("%d ", student->id);
}

// Refactor into reuseable functions
void generateUi(Node **tail, Node **head)
{
    int num, inputIndex, inputValue;
    Student *student = (Student *)malloc(sizeof(Student));
    system("cls");
    while (1)
    {
        printf("List of student IDs: ");
        printLinkedListFromTail(*tail, printStudent);
        printf("\n\n");

        printf("Type the number of the command to excecute it:\n");
        printf("1. Add value to start of list\n");
        printf("2. Add value to end of list\n");
        printf("3. Add value at index of list\n");
        printf("4. Set value at index of list\n");
        printf("5. Remove value at index of list\n");
        printf("6. Get value at index of list\n");
        printf("7. Get list length\n");
        printf("8. Remove student with largest ID\n");
        printf("0. End program\n\n");

        num = getDigitFromUser("Enter command number: ", "Command number excepted\n\n", "Incorrect input. Please repeat\n\n", 0, 8);

        switch (num)
        {
        case 1:
            inputValue = getDigitFromUser("Enter student ID at new first node (must be intiger in range [1;999999]): ", "User added at tail\n", "Incorrect input\n", 1, 999999);
            student->id = inputValue;
            addToTail(tail, student, sizeof(Student));
            break;
        case 2:
            inputValue = getDigitFromUser("Enter student ID at new last node (must be intiger in range [1;999999]): ", "User added at head\n", "Incorrect input\n", 1, 999999);
            student->id = inputValue;
            addToHead(head, student, sizeof(Student));
            break;
        case 3:
            inputIndex = getDigitFromUser("Enter index to insert at: ", "Input accepted\n", "Index larger than list\n", 0, getDLListLen(*tail));
            inputValue = getDigitFromUser("Enter student ID at new location (must be intiger in range [1;999999]): ", "User added at index\n", "Incorrect input\n", 1, 999999);
            student->id = inputValue;
            insertValueAtIndex(tail, head, inputIndex, student, sizeof(Student));
            break;
        case 4:
            inputIndex = getDigitFromUser("Enter index to change at: ", "Input accepted\n", "Index larger than list\n", 0, getDLListLen(*tail) - 1);
            inputValue = getDigitFromUser("Enter new student ID at location (must be intiger in range [1;999999]): ", "User ID changed at index\n", "Incorrect input\n", 1, 999999);
            student->id = inputValue;
            setValueByIndex(*tail, student, sizeof(Student), inputIndex);
            break;
        case 5:
            inputIndex = getDigitFromUser("Enter index to delete: ", "Value at index deleted\n", "Index larger than list\n", 0, getDLListLen(*tail) - 1);
            deleteNodeByIndex(tail, head, inputIndex);
            break;
        case 6:
            inputIndex = getDigitFromUser("Enter index to get student ID from: ", "Value at index extractec\n", "Index larger than list\n", 0, getDLListLen(*tail) - 1);
            student = (Student *)getValueByIndex(*tail, inputIndex);
            break;
        case 7:
            break;
        case 8:
            removeLargest(head, tail, compare);
            break;
        case 0:
            printf("Quiting program");
            return;
            break;

        default:
            printf("Something went wrong!");
            return;
            break;
        }
        system("cls");
        if (num == 6)
        {
            printf("Student ID at index %d: %d\n", inputIndex, student->id);
        }
        else if (num == 7)
        {
            printf("Length of list: %d\n", getDLListLen(*tail));
        }
    }
}

int main()
{
    Node *head, *tail;
    Student *value = (Student *)malloc(sizeof(Student));
    value->id = 11535;

    initDLList(&head, &tail, value, sizeof(Student));
    generateUi(&tail, &head);
    deleteDLList(tail);
    return 0;
}
