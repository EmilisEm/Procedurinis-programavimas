#include <stdio.h>

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg, void (*callbacks[])(int));
int getMenuOption(char *msg, int maxNum);
void printOption(int option);

int main()
{
    char *strArr[] = {"One", "Two", "Three"};
    void (*callbacks[])(int) = {printOption, printOption, printOption};

    showMenu("TEST MENU", strArr, 3, "Please enter the number of the menu you want to open: ", callbacks);

    return 0;
}

// Function displays menu untill user enters a valid menu option number
int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg, void (*callbacks[])(int))
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
            callbacks[option - 1](option);
            return option;
        }
    }
}

// Reads user input for menu option
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

// Prints option
void printOption(int option)
{
    printf("%d\n", option);
}