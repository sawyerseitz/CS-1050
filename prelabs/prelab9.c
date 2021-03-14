#include <stdio.h>

void getUserString(char* userString);
int  getNumCharacters(char* userString);
void reverseString(char* userString, short* numCharacters);

int main(void)
{
    char userString[256];
    short numCharacters;

    printf("\n*** Welcome to Prelab 9! ***\n");

    getUserString(userString);
    numCharacters = getNumCharacters(userString);

    printf("You entered: %s\n", userString);
    printf("%p\n", &userString);
    printf("That string is %d in length\n", numCharacters);
    printf("The reversed string is: ");
    reverseString(userString, &numCharacters);

    printf("\n*** Thanks for doing Prelab 9 ***\n\n");
}

void getUserString(char *userString)
{
    printf("Please enter a string: ");
    scanf("%s", userString);
}

int getNumCharacters(char* userString)
{
    int totalChar = 0;

    for (char* ptr = userString; *ptr != '\0'; ++ptr) 
        totalChar++;

    return totalChar;
}

void reverseString(char* userString, short* numCharacters)
{
    for (char* lastChar = userString + *numCharacters; lastChar != userString - 1; --lastChar) 
        printf("%c", *lastChar);

    printf("\n%p", userString);
}
