/*******************************
 * Course:    CS 1050
 * Semester:  Fall 2020
 * Lab:       Lab J
 * Author:    Evan Dobson
 * Pawprint:  ejdwcf
*******************************/


#include <stdio.h>

void inputTwoStrings(char *userString1, char *userString2);
void inputIntArray(int *userIntArray);
void printOutput(char *userString1, char *userString2, int *userIntArray);

// Main 
//-----------------------------------------------------------------------------
int main()
{
    char userString1[128];
    char userString2[128];
    int  userIntArray[128];

    printf("***********************\n");
    printf("* Welcome to Prelab 8 *\n");
    printf("***********************\n");

    inputTwoStrings(userString1, userString2);
    inputIntArray(userIntArray);
    printOutput(userString1, userString2, userIntArray);
}
//-----------------------------------------------------------------------------

// Input Functions
//-----------------------------------------------------------------------------
void inputTwoStrings(char *userString1, char *userString2)
{
    printf("Please enter a string: \n");
    scanf("%s", userString1);

    printf("Please enter another string: \n");
    scanf("%s", userString2);
}

void inputIntArray(int *userIntArray)
{
    int i = 0;

    printf("Please enter positive integers, and -1 to end\n");

    while(1)
    {
        printf("Element #%d: ", i);
        scanf("%d", &userIntArray[i]);
        
        if (userIntArray[i] == -1)
        {
            break;
        }

        i++;
    }
}
//-----------------------------------------------------------------------------

// Output Function
//-----------------------------------------------------------------------------
void printOutput(char *userString1, char *userString2, int *userIntArray)
{
    printf("\n\n***********************\n");
    
    printf("The first string you entered:\n");
    printf("%s\n", userString1);

    printf("The second string you entered:\n");
    printf("%s\n", userString2);

    printf("Array elements you entered:\n");

    for (int i = 0; userIntArray[i] != -1; ++i)
    {
        printf("Array[%d] = %d\n", i, userIntArray[i]);
    }
}
