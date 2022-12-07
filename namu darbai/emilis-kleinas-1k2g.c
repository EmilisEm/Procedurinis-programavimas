// Emilis Kleinas. 1 kursas. 2 grupe
// 4. Parašyti funkciją, kuri iš duoto teksto išmeta žodžius,
// vienodai skaitomus iš pradžios ir iš galo(tarpų skaičius turi likti nepakitęs).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VALIDATION_ERROR "Ivyko klaida validacijoje!"
#define BAD_FILE_NAMES "Neteisingas duomenu arba isvesties failo vardas. Arba ivyko klaida atidarime"
#define INPUT_FILE_MESSAGE "Iveskite duomenu failo varda: "
#define INPUT_FILE_ERROR "Ivyko klaida ivedant failo varda.\n\n"
#define INPUT_FILE_SUCCESS "Sekmingai ivestas failo vardas.\n\n"

#define BUFFER_SIZE 1024
#define MAX_LINE_LENGTH 255

// Grazina input ir output failus per argumentus.
// Per varda grazina 0 jei ivestas input ir output. 1 jei tik input. 2 jei input ivedamas ranka
// argc - cmd eilutes arg skaicius, argv - cmd eilutes argumentai
int getFiles(char *inputFile, char *outputFile, int argc, char const **argv);

// Reads file mane and returns through argument
void getFileName(char *fileName, char *inputMessage, char *failedInput, char *successfulInput);

// Returns 1 if string is palndrome. Else returns 0
int isPalindrome(char *str, int strLen);

// Removes all palindromes from file inputName and writes the new results in file outputName (if it exists. Else to screen)
int removePalindromeFromFile(char *inputName, char *outputName, int status);

int handleBuffer(char *buffer, int trueBufferLen, FILE *outputFp, int isLastChunk);

void handleLine(char *line, FILE *outputFp);

void setToZero(char *buffer, int bufferLen);

int main(int argc, char const *argv[])
{
    char *input, *output;
    input = malloc(255);
    output = malloc(255);

    getFiles(input, output, argc, argv);

    printf("%s\n%s", input, output);

    removePalindromeFromFile(input, output, 0);

    return 0;
}

int getFiles(char *inputFile, char *outputFile, int argc, char const **argv)
{
    if (argc >= 3)
    {
        strcpy(inputFile, argv[1]);
        strcpy(outputFile, argv[2]);

        return 0;
    }
    else if (argc == 2)
    {
        strcpy(inputFile, argv[1]);

        return 1;
    }
    else if (argc == 1)
    {
        getFileName(inputFile, INPUT_FILE_MESSAGE, INPUT_FILE_ERROR, INPUT_FILE_SUCCESS);
        outputFile[0] = 0;

        return 2;
    }
    else
    {
        printf(VALIDATION_ERROR);
        return -1;
    }
}

void getFileName(char *fileName, char *inputMessage, char *failedInput, char *successfulInput)
{
    int fileRead = 0;
    FILE *fp = NULL;

    while (!fileRead)
    {
        printf("%s", inputMessage);
        if (scanf("%s", fileName) != 1 || getchar() != '\n')
        {
            scanf("%*[\n]");
            printf("%s", failedInput);
        }
        else
        {

            fp = fopen(fileName, "r");

            if (fp)
            {
                printf("%s", successfulInput);
                fileRead = 1;
                fclose(fp);
            }
            else
            {
                printf("%s", failedInput);
            }
        }
    }
}

int isPalindrome(char *str, int strLen)
{
    int i;

    for (i = 0; i < strLen / 2; ++i)
    {
        if (str[i] != str[strLen - i - 1])
        {
            return 0;
        }
    }

    return 1;
}

int removePalindromeFromFile(char *inputName, char *outputName, int status)
{
    FILE *inputFp = fopen(inputName, "r");
    FILE *outputFp = fopen(outputName, "w");
    // trueBufferLen - buffer length after reading. BufferOfset - file ofset from prev '\n' char
    int trueBufferLen, bufferOfset;

    if (inputFp == NULL || outputFp == NULL)
    {
        printf("%s", BAD_FILE_NAMES);
        return -1;
    }

    // If for some reason char isnt 1 bite
    char *buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));

    while (1)
    {
        setToZero(buffer, BUFFER_SIZE);
        trueBufferLen = fread(buffer, sizeof(char), BUFFER_SIZE, inputFp);
        printf("\n\n%s\n\n", buffer);

        if (trueBufferLen < BUFFER_SIZE && trueBufferLen > 0)
        {
            bufferOfset = handleBuffer(buffer, trueBufferLen, outputFp, 1);
            free(buffer);
            fclose(inputFp);
            fclose(outputFp);
            return 0;
        }
        else if (trueBufferLen == BUFFER_SIZE)
        {
            bufferOfset = handleBuffer(buffer, trueBufferLen, outputFp, 0);
        }

        fseek(inputFp, -bufferOfset, SEEK_CUR);
    }
}

// Do strtok check if error
int handleBuffer(char *buffer, int trueBufferLen, FILE *outputFp, int isLastChunk)
{
    int bufferOfset = 0;
    char prevString[MAX_LINE_LENGTH + 1];
    // printf("%s", buffer);
    char *token = strtok(buffer, "\n");
    printf("%s", token);
    bufferOfset = trueBufferLen - (token - buffer);

    strcpy(prevString, token);

    while (token != NULL)
    {
        printf("\n --- %s --\n", token);
        printf("here");

        token = strtok(NULL, "\n");
        printf("\n--- %s --\n", token);

        if (token == NULL)
        {
            if (isLastChunk)
            {
                printf("here end");
                // handleLine(prevString, outputFp);
                bufferOfset = 0;
            }
            // printf("%d", bufferOfset);
            return bufferOfset;
        }

        bufferOfset = trueBufferLen - (token - buffer);
        printf("\nbuff affter: %d\n", bufferOfset);

        handleLine(prevString, outputFp);
        strcpy(prevString, token);
    }
}

// Do strtok check if error
void handleLine(char *line, FILE *outputFp)
{
    int ofset;
    char word[MAX_LINE_LENGTH] = {0};
    while (sscanf(line, "%s%n", word, &ofset) == 1)
    {
        line += ofset;
        if (isPalindrome(word, strlen(word)))
        {
            ;
        }
        else
        {
            fputs(word, outputFp);
        }
        fputc(' ', outputFp);
    }
    fseek(outputFp, -1, SEEK_CUR);
    fputc('\n', outputFp);
}

void setToZero(char *buffer, int bufferLen)
{
    int i;
    for (i = 0; i < bufferLen; ++i)
    {
        buffer[i] = '\0';
    }
}