#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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

int checkIfLanguageRepeats(char languages[])
{
    char splitLanguages[100][100];
    int i = 0, j = 0, k;

    for (k = 0; languages[k] != '\0'; ++k)
    {
        if (isalpha(languages[k]))
        {
            splitLanguages[i][j++] = languages[k];
        }

        else
        {
            splitLanguages[i][j] = '\0';
            ++i;
            j = 0;
        }
    }

    splitLanguages[i][j] = '\0';

    int l;

    for (k = 0; k < i + 1; ++k)
    {
        for (l = 0; l < k; ++l)
        {
            if (strcmp(splitLanguages[l], splitLanguages[k]) == 0)
            {
                return 1;
            }
        }
    }

    return 0;
}

int checkIfCourseRepeats(char courses[10][30], int courseCount)
{
    int i, n;
    for (i = 0; i < courseCount; ++i)
    {
        for (n = 0; n < i; ++n)
        {
            if (strcmp(courses[i], courses[n]) == 0)
            {
                return 1;
            }
        }
    }
    return 0;
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
        {                                                                                         // process all the student records in database
            Student s = students[i];                                                              // store data for each student in s
            if (!checkIfLanguageRepeats(s.languages) && !checkIfCourseRepeats(s.courses, s.load)) // *** third filter, various other conditions
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
        printf("Filter applied, %d students found\n", counterDemo); // how many passed the filters
        fclose(db);
    }
    else
    {
        printf("File db.bin not found, check current folder\n");
    }
    return 0;
}
