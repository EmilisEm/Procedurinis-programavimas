#include <stdio.h>
#include <string.h>

// Finds the largest file entered in command line while compiling
const char *largestFile(int fileCount, const char **fileNames);
// Gets file titled fileName file size in bytes
long getFileSize(const char *fileName);

int main(int argc, char const *argv[])
{
    printf("%s", largestFile(argc, argv));
    return 0;
}

long getFileSize(const char *fileName)
{
    FILE *fp = NULL;
    fp = fopen(fileName, "rb");

    if (fp == NULL)
    {
        return -1;
    }

    fseek(fp, 0, SEEK_END);

    int fileSize = ftell(fp);
    fclose(fp);

    return fileSize;
}

const char *largestFile(int fileCount, const char **fileNames)
{
    int largest = -1, i;

    // First argumant is program name. Skips it
    for (i = 1; i < fileCount; ++i)
    {
        if (getFileSize(fileNames[i]) > largest)
        {
            largest = i;
        }
    }

    return fileNames[largest];
}
