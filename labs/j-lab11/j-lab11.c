/***********************
* Course:    CS 1050
* Semester:  Fall 2020
* Lab:       Lab J
* Author:    Evan Dobson
* Pawprint:  ejdwcf
***********************/

#include <stdio.h>
#include <string.h>
#include "fight.h"

int main(int argc, char * argv[])
{
    FILE* fp;
    char header[256];

    char name1[32];
    char name2[32];

    int foundName1 = 0, foundName2 = 0;

    // Checks to see if the user has inputed the correct number of arguments
    if (argc > 4) 
    {
        printf("*** Error: Too many arguments\n");
        return 0;

    } else if (argc < 4)
    {
        printf("*** Error: Too few arguments\n");
        return 0;
    }

    fp = fopen(argv[1], "r"); // Open the file that the user enters

    if (fp != NULL)
    {
        fgets(header, 255, fp); // Throw away the header line

        int ac1, hp1, hitBonus1, ac2, hp2, hitBonus2;
        char attack1Damage1[8], attack2Damage1[8], attack1Damage2[8], attack2Damage2[8];

        // Loops over the file and tests each monster against what the user inputed.
        // Two while loops are needed (at least in how I set this up) to account for when the first monster the user inputs is 
        // further down in the file than the second.
        while (fp && !feof(fp))
        {
            fscanf(fp, "%[^,], %d, %d, %d, %[^,], %s", name1, &ac1, &hp1, &hitBonus1, attack1Damage1, attack2Damage1);
            
            if (strcmp(name1, argv[2]) == 0)
                break;
            else
                fgets(header, 255, fp);
        }

        rewind(fp); // Makes the file pointer start back at the top

        while (fp && !feof(fp))
        {
             fscanf(fp, "%[^,], %d, %d, %d, %[^,], %s", name2, &ac2, &hp2, &hitBonus2, attack1Damage2, attack2Damage2);

             if (strcmp(name2, argv[3]) == 0)
                break;
            else
                fgets(header, 255, fp);
        }

        // Error checking, if the monster the user inputed was not found in the file, print the statment and return
        if (strcmp(name1, argv[2]) != 0)
        {
            printf("*** Error: Could not find combatant %s\n", argv[2]);
            return 0;
        } 
        
        if (strcmp(name2, argv[3]) != 0)
        {
            printf("*** Error: Could not find combatant %s\n", argv[3]);
            return 0;
        }

        // Since the program will return before this function call if any of the required arguments are wrong,
        // there's no need to check if any of these parameters exist or not
        Fight(name1, ac1, hp1, hitBonus1, attack1Damage1, attack2Damage1, name2, ac2, hp2, hitBonus2, attack1Damage2, attack2Damage2);

        fclose(fp);
    
    } else
        printf("*** Error: Could not open %s\n", argv[1]);
}
