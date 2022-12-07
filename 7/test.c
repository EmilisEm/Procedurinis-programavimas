#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr[] = {
        564,
        21,
        65,
        849,
        2,
        155,
    };
    FILE *fp;
    fp = fopen("file.bin", "wb");
    fwrite(arr, sizeof(arr), 1, fp);
    fclose(fp);
    return 0;
}
