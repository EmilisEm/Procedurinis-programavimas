#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char *str = "Lab"; // dydis 4

    int *num = (int *)str;

    *num = 80;

    printf("%s", str);
}
