#include <stdio.h>

int getFactorial(int number);
int getFactorialNoRec(int number);

int main()
{
    printf("getFactorial(9) = %d\n", getFactorial(9));
    printf("getFactorial(1) = %d\n", getFactorial(1));
    printf("getFactorial(-7) = %d\n", getFactorial(-7));
    return 0;
}

int getFactorial(int number)
{
    if (number == 2)
    {
        return 2;
    }
    else if (number == 1)
    {
        return 1;
    }
    else if (number <= 0)
    {
        return 0;
    }
    else
    {
        return number * getFactorial(number - 1);
    }
}

int getFactorialNoRec(int number)
{
    int product = 1, i;

    if (number < 1)
    {
        return 0;
    }

    for (i = 2; i <= number; ++i)
    {
        product *= i;
    }

    return product;
}