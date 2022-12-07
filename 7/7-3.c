#include <stdio.h>

int getPositiveNumber(char *msg);

int main()
{
    int num = getPositiveNumber("Enter a positive number: ");
    printf("You entered %d", num);
    return 0;
}

int getPositiveNumber(char *msg)
{
    int num;
    while (1)
    {
        printf("%s", msg);
        if (scanf("%d", &num) == 1 && getchar() == '\n')
        {
            if (num > 0)
            {
                return num;
            }
        }
        else
        {
            scanf("%*[^\n]");
        }
    }
}
