#include <stdio.h>

long getFileSize(char *fileName);

int main()
{
    printf("size in bites of 'file.bin': %d\n", getFileSize("file.bin"));
    printf("size in bites of 'file2.bin': %d\n", getFileSize("file2.bin"));
    return 0;
}

long getFileSize(char *fileName)
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
