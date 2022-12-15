#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int studId;
    void *value;
};

void valueCallback(const void *value)
{
    struct Student *s = (struct Student *)(value);

    printf("%d ", s->studId);
}

int main()
{
    struct Student stud1;
    struct Student stud2;
    struct Student stud3;

    stud1.studId = 1212;
    stud2.studId = 1313;
    stud1.value = &stud2;
    // stud1->value = stud2;

    valueCallback(stud1.value);
    printf("K");

    return 0;
}
