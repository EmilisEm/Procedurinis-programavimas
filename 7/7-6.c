#include <stdio.h>

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg);
int getMenuOption(char *msg, int maxNum);

int main()
{
    char *strArr[] = {"One", "Two", "Three"};
    printf("%d", showMenu("TEST MENU", strArr, 3, "Please enter the number of the menu you want to open: "));
    return 0;
}

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg)
{
    while (1)
    {
        int i, option;
        printf("%s\n", menuTitle);

        for (i = 0; i < menuSize; ++i)
        {
            printf("%d. %s\n", i + 1, menuOptions[i]);
        }

        option = getMenuOption(inputMsg, menuSize);

        if (option)
        {

            return option;
        }
    }
}

int getMenuOption(char *msg, int maxNum)
{
    int num;
    printf("%s", msg);
    if (scanf("%d", &num) == 1 && getchar() == '\n')
    {
        if (num > 0 && num <= maxNum)
        {
            return num;
        }
        return 0;
    }
    else
    {
        scanf("%*[^\n]");
        return 0;
    }
}
