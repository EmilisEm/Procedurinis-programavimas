#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALIDATION_ATTEMPTS 5
#define LINE_MAX_LENGTH 2000
#define WORD_MAX_LENGTH 1000
#define DICTIONARY_NAME "dict.txt"
#define MISTAKES_NAME "mistakes.txt"
#define TEXT_FILE_NAME "text.txt"

void handleLine(char[], int);
void handleWord(char *, int, int);
int wordInDict(char *);
void addToDict(char *);
void addMistake(char *, int, int);

char getUserInput(void);

int main()
{
    char *line = malloc(LINE_MAX_LENGTH);
    int i = 1;
    FILE *fp;
    fp = fopen(TEXT_FILE_NAME, "r");

    if (fp == NULL)
    {
        return 1;
    }

    while (fgets(line, LINE_MAX_LENGTH, fp))
    {
        if (line[strlen(line) - 1] == '\n')
        {
            line[strlen(line) - 1] = '\0';
        }
        handleLine(line, 1);

        ++i;
        if (feof(fp))
        {
            break;
        }
    }
    fclose(fp);
    return 0;
}
// Scans either 'y' or 'n'
char getUserInput()
{
    char value;
    while (1)
    {
        printf("Enter the specified value: ");
        if (scanf("%c", &value) == 1 && getchar() == '\n')
        {
            if (value == 'y' || value == 'n')
            {
                printf("Data entered correctly\n\n");
                return value;
            }
            else
            {
                printf("Entered letter is not 'y' or 'n'\n\n");
            }
        }
        else
        {
            printf("Entered letter is not 'y' or 'n'\n\n");
            scanf("%*[^\n]");
        }
    }
}

// Goes through every word in line, checks if in dictionary and takes appropriate action
void handleLine(char str[], int lineNum)
{
    int numCount = 1;
    char *token;
    token = strtok(str, " ");

    while (token != 0)
    {
        if (!wordInDict(token))
        {
            handleWord(token, lineNum, numCount);
        }
        ++numCount;
        token = strtok(NULL, " ");
    }
}

// Checks if passed word is in dictionary file
int wordInDict(char word[])
{
    FILE *fp = NULL;
    char dictWord[WORD_MAX_LENGTH];

    fp = fopen(DICTIONARY_NAME, "a+");

    if (fp == NULL)
    {
        printf("Error opening dictionary file!\n\n");
        return 0;
    }

    while (fscanf(fp, "%s", dictWord) == 1)
    {
        if (!strcmp(word, dictWord))
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    return 0;
}

// Adds word to dictionary file
void addToDict(char word[])
{
    FILE *fp = NULL;
    fp = fopen(DICTIONARY_NAME, "a");

    if (fp == NULL)
    {
        printf("Error opening dictionary file!\n\n");
        return;
    }

    fprintf(fp, "%s\n", word);
    fclose(fp);
}

// Adds word and word location(line and word) to mistake file
void addMistake(char word[], int line, int wordCount)
{
    FILE *fp = NULL;
    fp = fopen(MISTAKES_NAME, "a");

    if (fp == NULL)
    {
        printf("Error opening mistake file!\n\n");
        return;
    }

    fprintf(fp, "%s %d %d\n", word, line, wordCount);

    fclose(fp);
}

void handleWord(char word[], int lineNum, int wordNum)
{
    char input;
    printf("Type 'y' if you want to add the word '%s' to the dictionary file or type 'n' if you want to add it to the mistakes file\n\n", word);
    input = getUserInput();

    if (input == 'y')
    {
        addToDict(word);
    }
    else
    {
        addMistake(word, lineNum, wordNum);
    }
}