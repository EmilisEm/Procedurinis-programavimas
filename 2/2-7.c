#include "stdio.h"
#include "math.h"

int getNumber()
{
    int num;

    printf("Iveskite sveika skaiciu: ");
    while ((scanf("%d", &num) != 1) || (getchar() != '\n'))
    {
        scanf("%*[^\n]");
        printf("Iveskite sveika skaiciu: ");
    }

    return num;
}

// Returns number length in digits
int getLength(int num)
{
    if (num == 0)
    {
        return 1;
    }

    int length = 0;

    while (num != 0)
    {
        num /= 10;
        ++length;
    }

    return length;
}

// Returns digit by index rigth to left
int getDigit(int num, int index)
{
    int digit, i;

    for (i = 0; i < index; ++i)
    {
        num /= 10;
    }

    digit = num % 10;

    return digit;
}

// Returns the largest digits index upto a certain length. Length is counted from right to left
int getLargestDigitIndex(int num, int length)
{
    int index = 0, i;

    for (i = 0; i < length; ++i)
    {
        if (getDigit(num, i) > getDigit(num, index))
        {
            index = i;
        }
    }

    return index;
}

// Switches to digits in a number
int switchDigits(int num, int index1, int index2)
{
    int newNum = num;
    newNum -= ceil(getDigit(num, index1) * pow(10, index1));
    newNum += ceil(getDigit(num, index2) * pow(10, index1));

    newNum -= ceil(getDigit(num, index2) * pow(10, index2));
    newNum += ceil(getDigit(num, index1) * pow(10, index2));

    return newNum;
}

int main()
{
    int isPos = 1;
    // int num = getNumber();
    int num = 123456789;
    int length = getLength(num);
    int i, temp;

    if (num < 0)
    {
        isPos = 0;
        num *= -1;
    }

    for (i = length; i > 0; --i)
    {
        temp = getLargestDigitIndex(num, i);
        num = switchDigits(num, i - 1, temp);
    }

    printf("Isrikiuotas skaicius: %d", isPos ? num : num * (-1));

    return 0;
}