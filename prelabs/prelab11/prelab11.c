#include <stdio.h>

#define FILENAME "DnDMonsterScores.csv"


int main(void)
{
    FILE* fp;
    char name[256];
    int monsterCount = 0; 
    float averageAC = 0, averageHP = 0;

    fp = fopen(FILENAME, "r");

    // Only move on if we are able to open the file
    if (NULL != fp)
    {
        // Throw away the first line
        fgets(name, 255, fp);
        printf("\nHeader line was: %s\n", name);

        // Read the important data from the next line

        while (fp && !feof(fp))
        {
            int ac, hp;

            // Only print if we read the 3 fields we expect
            if (fscanf(fp, "%[^,], %d, %d,", name, &ac, &hp) == 3)
            {
                printf("%d) \"%-25s\" : AC = %d, HP = %d\n", ++monsterCount, name, ac, hp);
                averageAC += ac;
                averageHP += hp;

                fgets(name, 255, fp);
            }
        }

        averageAC /= monsterCount;
        averageHP /= monsterCount;

        printf("\n\nTotal monster count = %d\n", monsterCount);
        printf("Average AC = %0.2f\n", averageAC);
        printf("Average HP = %0.2f\n\n", averageHP);
    }

    // If you open a file, you had better close it
    fclose(fp);
}
