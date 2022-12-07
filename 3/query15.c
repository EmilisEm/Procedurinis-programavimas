#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LANG_LENGTH 100

typedef struct Student
{
    char name[30];
    char surname[30];
    int course;     // year of study
    double average; // average grade

    int load;             // number of courses
    char courses[10][30]; // course names
    int grades[10];       // course grades

    char languages[100]; // spoken languages

} Student;

float findMaxGrade(Student students[], int studentCount)
{
    if (studentCount == 0)
    {
        return -1;
    }

    float maxGrade = students[0].average;

    for (int i = 0; i < studentCount; ++i)
    {
        if (students[i].average > maxGrade)
        {
            maxGrade = students[i].average;
        }
    }

    return maxGrade;
}

int main(int argc, char *argv[])
{
    FILE *db = NULL;
    // open database file for reading, provide a parameter or use default "db.bin"
    if (argc > 1)
        db = fopen(argv[1], "rb");
    else
        db = fopen("db.bin", "rb");

    if (db)
    {
        Student students[1000]; // all the data goes here
        int size = 0;           // how many students in database

        // reading data from file
        fread(&size, sizeof(int), 1, db);

        for (int i = 0; i < size; i++)
        {
            fread(&students[i], sizeof(Student), 1, db);
        }
        printf("%d records loaded succesfully\n", size);

        // MODIFY CODE BELOW

        int counterDemo = 0; // for counting students

        for (int i = 0; i < size; ++i)
        {                            // process all the student records in database
            Student s = students[i]; // store data for each student in s
            float maxGrade = findMaxGrade(students, size);

            if (1)
            {                                    // *** first filter, conditions on the student
                if (s.average >= (maxGrade - 1)) // *** third filter, various other conditions
                {
                    printf("%s %s %3d %4f %3d ", s.name, s.surname, s.course, s.average, s.load); // print student data
                    for (int i = 0; i < s.load; ++i)
                    {
                        printf("%30s %4d ", s.courses[i], s.grades[i]);
                    }
                    printf("%s\n", s.languages);
                    ++counterDemo; // counting students
                }
            }
        }
        printf("Filter applied, %d students found\n", counterDemo); // how many passed the filters
        fclose(db);
    }
    else
    {
        printf("File db.bin not found, check current folder\n");
    }

    return 0;
}
