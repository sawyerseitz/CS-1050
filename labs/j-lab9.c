/***************************
 * Course: CS1050
 * Semester: Fall 2020
 * Autor: Evan Dobson
 * Pawprint: ejdwcf
 * Lab: Lab 9
***************************/


#include <stdio.h>

void getString(char* userString);
int getNumSegments(char* userString);
int getNumCharacters(char* userString);
void reverseSegments(char* userString, int* numSegments, int* numCharacters);

int main(void)
{
    char userString[256];
    int numSegments;
    int numCharacters;

    printf("*** Welcome to Lab 9 ***\n");

    getString(userString);
    printf("You entered: %s\n", userString);

    numCharacters = getNumCharacters(userString);

    numSegments = getNumSegments(userString);
    printf("There are %d segments in the string\n", numSegments);

    reverseSegments(userString, &numSegments, &numCharacters);

    printf("*** Thanks for doing Lab 9 ***\n");
}

void getString(char* userString)
{
    printf("Please enter a string: ");
    scanf("%s", userString);
}

int getNumSegments(char* userString)
{
    int counter = 0;
    int numSegments = 0;

    for (char* i = userString; *i != '\0'; ++i)
    {
        if (counter % 4 == 0)
            numSegments++;

        ++counter;
    }

    return numSegments;
}

int getNumCharacters(char* userString)
{
    int totalChar = 0;

    for (char* i = userString; *i != '\0'; ++i)
    {
        ++totalChar;
    }

    return totalChar;
}

void reverseSegments(char* userString, int* numSegments, int* numCharacters)
{
    char modifiedString[*numSegments * 4];
    char* lastElemPtr = modifiedString + *numSegments * 4; 
    
    int outCounter = 0;
    int inCounter = 0;

    for (char* i = userString; *i != '\0'; ++i)
    {
        if (outCounter % 4 == 0)
        {
            for (int j = 3; j >= 0; --j)
            {
                printf("%c\n", *(i + j));
                *(modifiedString + outCounter + inCounter) = *(i + j);

                //printf("%c", *(modifiedString + outCounter + inCounter));

                ++inCounter;
            }
        }

        ++outCounter;
    }

    //printf("\n");

    outCounter = 0;
    inCounter = 0;

    //int printCounter = sizeof(modifiedString);

    printf("lastElemPtr: %c", *(modifiedString + *numSegments * 4));
/*
    for (char* j = lastElemPtr; j != modifiedString - 1; --j)
    {
        printf("%c", *j);

        --printCounter;
    }*/

    for (char* j = modifiedString; j != lastElemPtr; ++j)
    {
        printf("%c", *j);
    }

    printf("\n");
}


