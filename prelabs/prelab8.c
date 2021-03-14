#include <stdio.h>


int getIntegerArray(int *outputIntArray, int maxSize);
void getUserNumbers(int *userInt, float *userFloat);
void getUserString(char *userString);
void printIntArray(int d[], int maxSize);

int main(void)
{
    int maxSize = 0;
    int arrSize;

    int userInt;
    int intArray[64];
    float userFloat;
    char userString[64];

    printf("***********************\n");
    printf("* Welcome to Prelab 8 *\n");
    printf("***********************\n");

    getUserNumbers(&userInt, &userFloat);
    getUserString(userString);

    arrSize = getIntegerArray(intArray, maxSize);

    printf("*************************************\n");

    printf("You entered %d, %f, %s\n", userInt, userFloat, userString);
    printIntArray(intArray, arrSize);
}

// Getting Functions
// ***************************************************************************************************

 void getUserNumbers(int *userInt, float *userFloat)
{
    printf("Please enter an integer followed by a space followed by a float and then hit enter:\n");
    scanf("%d %f", userInt, userFloat);
}


void getUserString(char *userString)
{
    printf("Please enter a string without spaces and then hit enter:\n");
    scanf("%s", userString);
}


int getIntegerArray(int *outputIntArray, int maxSize)
{
    printf("How many integers would you like to input? (Max of 64): ");
    scanf("%d", &maxSize);

    for (int i = 1; i <= maxSize; i++)
    {
        printf("\tEnter integer #%d: ", i);
        scanf("%d", &outputIntArray[i]);
    }

    return maxSize;
}
// ***************************************************************************************************

// Printing Functions
// ***************************************************************************************************

void printIntArray(int d[], int arrSize)
{
    printf("Array elements:\n");

    for (int i = 1; i < arrSize; i++)
    {
        printf("\tarray[%d] = %d\n", i, d[i]);
    }
}
// ***************************************************************************************************
