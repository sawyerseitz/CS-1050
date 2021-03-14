/*************************
 * Course:    CS1050
 * Semester:  Fall 2020
 * Lab:       Lab J
 * Author:    Evan Dobson
 * Pawprint:  ejdwcf
 ************************/

// includes
#include <stdio.h>
#include <ctype.h>

// Symbolic Constants
#define CLEARTEXT \
"It's Christmastime in Washington\a\nThe Democrats rehearsed \b\n"\
"Gettin' into gear for four more years\nThings not gettin' worse"\
"\"\\\?\n\n\t\t- Steve Earle"

// Prototypes
void Encrypt(char *in, int displacement);

// Main
int main(void)
{
    char string[] = CLEARTEXT;

    printf("\n*** Original ***\n");
    printf("%s\n", string);
    
    printf("\n*** Encrypted ***\n");
    Encrypt(string, 2);
    printf("%s\n", string);
    
    printf("\n*** Unencrypted ***\n");
    Encrypt(string, -2);
    printf("%s\n\n", string);
}

// Function implementations
void Encrypt(char *s, int displacement)
{
    int index = 0;

    for (char* i = s; *i != '\0'; ++i)
    {
        if (isspace(*i) || iscntrl(*i))
           s[index++] = *i;
        else
            s[index++] = *i + displacement;
    }
}
