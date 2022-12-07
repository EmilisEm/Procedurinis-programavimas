#ifndef _VALIDATION_H
#define _VALIDATION_H

// Returns amount of digits a number has
int getNumLength(int);

// Checks if a string is a real number and if its whole and decimal part is seperated by a comma. If so returns the amount of digits in the number
int strIsRealNumber(char str[], int strLen);

// Returns true if the number has no more than 3 values after the comma, else false
int checkStrNumPercision(char str[], int strLen);

int doubleInRange(double num, double lower, double upper);

// Returns true if number is positive, else false
int isPositive(int num);

// Checks if number meets conditions specified in array of function pointers
int intigerValidation(int (*functionList[])(int), int, int);

// Checks if number meets conditions specified in array of function pointers
int strValidation(int (*functionList[])(char *, int), int, char *, int);

// Checks if number is in range [10; 1000]
int strInRange(char str[], int strLength);

// Checks if string is is an array of ints seperated by semicolons
int isSemicolonSeperatedInt(char str[], int strLen);

// Checks if string ends with .txt
int isTxtFile(char str[], int strLen);

// Checks if string contains 3 nums
int isThreeNums(char str[], int strLen);

int isDateFormat(char str[], int strLen);

int dateInRange(char str[], int strLen);

int isEmail(char str[], int strLen);
#endif