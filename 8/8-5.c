#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 100

char **createStringArray(int len);

char ***create2dArr(int l, int h);

int main()
{

    // char **arr = createStringArray(4);

    char ***arr = create2dArr(4, 4);

    printf("here");

    // for (int i = 0; i < 4; ++i)
    // {
    //     printf("%s ", arr[i]);
    // }

    for (int i = 0; i < 4; ++i)
    {
        printf("here");
        for (int n = 0; n < 4; ++n)
        {
            printf("%c ", arr[i][n][0]);
        }
    }
    return 0;
}

char ***create2dArr(int l, int h)
{
    int i, j;
    char ***arr = malloc(l * sizeof(char **));

    for (i = 0; i < l; ++i)
    {

        arr[i] = createStringArray(h);

        // arr[i] = malloc(h * sizeof(char *));

        // for (j = 0; j < h; ++j)
        // {
        //     arr[i][j] = malloc(STR_LEN);
        //     arr[i][j] = "Hello";
        // }
    }
}

char **createStringArray(int len)
{
    char **strArr = malloc(len * sizeof(char *));

    for (int i = 0; i < len; ++i)
    {
        strArr[i] = malloc(STR_LEN);
        strArr[i] = "Hello";
    }

    return strArr;
}
