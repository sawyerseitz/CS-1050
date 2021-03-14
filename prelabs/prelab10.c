#include <stdio.h>
#include <ctype.h>

#define S1 "Once there was a way to get back homeward"
#define S2 "\n\n\tYou get killed just for      \tlivin' in your\nAmerican skin."
#define S3 "In  these days, you can get no rice.  No razor blades, but you can get knife."
#define S4 "Now some guys they just give up living.  And start dying little by little, piece by piece.      "
#define STRINGCOUNT 4

char * KillWhiteSpace(char *s);

int main(void)
{
    char s[STRINGCOUNT][256]={S1,S2,S3,S4};

    printf("**** Original Strings ****\n");
    for (int i=0;i<STRINGCOUNT;i++)
    {
        printf("#%d: %s\n",i,s[i]);
    }

    printf("\n\n**** Strings without whitespace ****\n");
    for (int i=0;i<STRINGCOUNT;i++)
    {
        printf("#%d: %s\n",i,KillWhiteSpace(s[i]));
    }
}

char* KillWhiteSpace(char *s)
{
    int index = 0;

    for (char* i = s; *i != '\0'; ++i)
    {
        if (!isspace(*i))
            s[index++] = *i;
    }

    s[index] = '\0';

    return s;
}
