#include <stdio.h>

int getValue(FILE *file, int index);
int remValue(int index, char *fileName);
int setValue(FILE *file, int index, int value);
int addValue(FILE *file, int index, int value);

long getFileSize(FILE *fp);
int inFileRange(FILE *fp, int index);
void printFile(FILE *file);

int main()
{
    FILE *bp;
    bp = fopen("file.bin", "r+b");

    if (bp == NULL)
    {
        printf("File 'file.bin' does not exist. Quiting");
        return 0;
    }

    printf("number of ints in file: %d\n", getFileSize(bp));
    printf("value at index 2: %d\n", getValue(bp, 2));

    printf("file contents: ");
    printFile(bp);

    addValue(bp, 2, 8);
    printf("\n\nnumber of ints in file after insertion: %d\n", getFileSize(bp));

    printf("file contents after insertion: ");
    printFile(bp);

    setValue(bp, 0, 67);
    printf("\n\nvalue at 0 after value is set to 67: %d\n", getValue(bp, 0));

    fclose(bp);

    remValue(0, "file.bin");

    bp = fopen("file.bin", "r+b");

    if (bp == NULL)
    {
        printf("File 'file.bin' does not exist. Quiting");
        return 0;
    }

    printf("File after removing 0 index element: ");
    printFile(bp);
    fclose(bp);

    return 0;
}

// Returns value at given index
int getValue(FILE *file, int index)
{
    if (index < 0 || index >= getFileSize(file))
    {
        return -1;
    }

    int value;

    fseek(file, sizeof(int) * index, SEEK_SET);
    fread(&value, sizeof(int), 1, file);

    return value;
}

// Removes value from binary file
int remValue(int index, char *fileName)
{
    int fileSize, temp, i;
    FILE *tempP = NULL;
    FILE *file = NULL;

    file = fopen(fileName, "rb");
    tempP = fopen("temp.bin", "wb");

    if (tempP == NULL || file == NULL)
    {
        return -1;
    }

    if (!inFileRange(file, index))
    {
        return -1;
    }

    fileSize = getFileSize(file);
    fseek(file, 0, SEEK_SET);

    // Writes remaining values to new temp file
    for (i = 0; i < fileSize; ++i)
    {
        fread(&temp, sizeof(int), 1, file);

        if (i != index)
        {
            fwrite(&temp, sizeof(int), 1, tempP);
        }
    }

    fclose(file);
    fclose(tempP);

    // Renames files
    remove(fileName);
    rename("temp.bin", fileName);

    return 0;
}

// Sets value in binary file position index to param value
int setValue(FILE *file, int index, int value)
{
    int fileSize, temp, i;

    if (!inFileRange(file, index))
    {
        return -1;
    }
    fseek(file, sizeof(int) * index, SEEK_SET);
    fwrite(&value, sizeof(int), 1, file);
    return 0;
}

// Inserts value at index in binary file. Must be opened in r+b mode
int addValue(FILE *file, int index, int value)
{
    if (!inFileRange(file, index))
    {
        return -1;
    }

    int fileSize = getFileSize(file), temp1, i;

    for (i = fileSize; i > index; --i)
    {
        fseek(file, (i - 1) * sizeof(int), SEEK_SET);
        fread(&temp1, sizeof(int), 1, file);
        fseek(file, i * sizeof(int), SEEK_SET);
        fwrite(&temp1, sizeof(int), 1, file);
    }

    fseek(file, index * sizeof(int), SEEK_SET);
    fwrite(&value, sizeof(int), 1, file);
    return 0;
}

// Returns the number of elements of type in in binary file
long getFileSize(FILE *fp)
{
    if (fp == NULL)
    {
        return -1;
    }

    fseek(fp, 0, SEEK_END);

    return ftell(fp) / sizeof(int);
}

// Checks if index is non-negative and less than file size. Returns true if so and false if else
int inFileRange(FILE *fp, int index)
{
    return (index < 0 || index >= getFileSize(fp)) ? 0 : 1;
}

void printFile(FILE *file)
{
    int size = getFileSize(file), i;

    for (i = 0; i < size; ++i)
    {
        printf("%d ", getValue(file, i));
    }
}