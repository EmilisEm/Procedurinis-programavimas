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

// funkcija kuri padoroja buferi. Skaito eilutes ir imasi atitinkamu veiksmu
int handleBuffer(char *buffer, int trueBufferLen, FILE *outputFp, int isLastChunk, int status);

// Paraso eilute i faila o jei tokio nera paraso i ekrana
void handleLine(char *line, FILE *outputFp, int status);

// Padaro kad visi masyvo elementai butu '\0'
void setToZero(char *buffer, int bufferLen);

int main(int argc, char const *argv[])
{
    char *input, *output;
    input = malloc(255);
    output = malloc(255);

    int option = getFiles(input, output, argc, argv);

    removePalindromeFromFile(input, output, option);

    free(input);
    free(output);
    return 0;
}

// grazina 0 jei pateiktas ir input ir output failas. 1 jei tik input, 2 jei nei vienas ir -1 jie kilo klaida
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
    FILE *outputFp = NULL;

    // Patikrina ar reikia spausdinti ant ekrano ar rasyti i faila. Jei reikia rasyti atidaro faila
    if (status == 0)
    {
        outputFp = fopen(outputName, "w");
    }

    // trueBufferLen - buffer length after reading. BufferOfset - file ofset from prev '\n' char
    int trueBufferLen, bufferOfset;

    if (inputFp == NULL && outputFp == NULL && status != 1)
    {
        printf("%s", BAD_FILE_NAMES);
        return -1;
    }

    // If for some reason char isnt 1 bite
    char *buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));

    // Loopina pro input file iki tol kol nera ka skaityti i bufferi
    while (1)
    {
        setToZero(buffer, BUFFER_SIZE);
        trueBufferLen = fread(buffer, sizeof(char), BUFFER_SIZE, inputFp);

        if (trueBufferLen < BUFFER_SIZE && trueBufferLen > 0)
        {
            bufferOfset = handleBuffer(buffer, trueBufferLen, outputFp, 1, status);
            free(buffer);
            fclose(inputFp);
            fclose(outputFp);
            return 0;
        }
        else if (trueBufferLen == BUFFER_SIZE)
        {
            bufferOfset = handleBuffer(buffer, trueBufferLen, outputFp, 0, status);
        }

        // Pataiso failo nuokrypi jei buvo nukirsta eilute viduryje
        fseek(inputFp, -bufferOfset, SEEK_CUR);
    }
}

int handleBuffer(char *buffer, int trueBufferLen, FILE *outputFp, int isLastChunk, int status)
{
    int bufferOfset = 0;
    char prevString[MAX_LINE_LENGTH + 1];
    char *token = strtok(buffer, "\n");
    bufferOfset = trueBufferLen - (token - buffer);

    strcpy(prevString, token);

    // Tikrina ar paskutine eilute buferi. Jei taip imasi atitinkamu veiksmu
    while (token != NULL)
    {
        token = strtok(NULL, "\n");

        if (token == NULL)
        {
            if (isLastChunk)
            {
                bufferOfset = 0;
            }

            return bufferOfset;
        }

        bufferOfset = trueBufferLen - (token - buffer);

        handleLine(prevString, outputFp, status);
        strcpy(prevString, token);
    }
}

void handleLine(char *line, FILE *outputFp, int status)
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
            if (status == 0)
            {
                fputs(word, outputFp);
            }
            else
            {
                printf("%s", word);
            }
        }
        if (status == 0)
        {
            fputc(' ', outputFp);
        }
        else
        {
            printf(" ");
        }
    }
    if (status == 0)
    {
        fseek(outputFp, -1, SEEK_CUR);
        fputc('\n', outputFp);
    }
    else
    {
        printf("\n");
    }
}

void setToZero(char *buffer, int bufferLen)
{
    int i;
    for (i = 0; i < bufferLen; ++i)
    {
        buffer[i] = '\0';
    }
}