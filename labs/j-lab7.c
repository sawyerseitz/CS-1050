/********************************
 * Course:    CS 1050
 * Semester:  Fall2020
 * Lab:       Lab J
 * Author:    Evan Dobson
 * Pawprint:  ejdwcf
********************************/

#include <stdio.h>

// Defines a few constants
#define SCORESROWS 3
#define SCORESCOLS 12

#define CUTOFFROWS 4
#define CUTOFFCOLS 3

// Print function prototypes
void printScoresArray(int studentArray[][SCORESCOLS]);
void printCutoffArray(int cutoffArray[][CUTOFFCOLS]);
void printGradesArray(char gradesArray[][SCORESCOLS]);

// Conversion function prototypes
void convertGradeToLetter(int scoresArray[][SCORESCOLS], int cutoffArray[][CUTOFFCOLS], char gradesArray[][SCORESCOLS]);

void convertCS1050ToLetter(int scoresArray[][SCORESCOLS], int cutoffArray[][CUTOFFCOLS], char gradesArray[][SCORESCOLS]);
void convertMath1500ToLetter(int scoresArray[][SCORESCOLS], int cutoffArray[][CUTOFFCOLS], char gradesArray[][SCORESCOLS]);
void convertEnglish1000ToLetter(int scoresArray[][SCORESCOLS], int cutoffArray[][CUTOFFCOLS], char gradesArray[][SCORESCOLS]);

int main(void)
{
    // Initialize the arrays how they are in the specifications
    int scoresArray[SCORESROWS][SCORESCOLS] = {{ 86, 95, 93, 98, 99, 76, 97, 85, 96, 94, 98, 78 },
                                               { 68, 88, 97, 67, 92, 52, 99, 95, 91, 90, 98, 73 },
                                               { 77, 95, 86, 88, 83, 37, 85, 91, 78, 85, 90, 93 }};

    int cutoffArray[CUTOFFROWS][CUTOFFCOLS] = {{ 85, 90, 85 },
                                               { 75, 80, 70 },
                                               { 65, 75, 55 },
                                               { 55, 60, 50 }};
    char gradesArray[SCORESROWS][SCORESCOLS];

    // Prints all the arrays
    printf("Here are the scores: \n");
    printScoresArray(scoresArray);

    printf("\nHere are the grade cutoffs: \n");
    printCutoffArray(cutoffArray);

    printf("\nHere are the grades: \n");
    convertGradeToLetter(scoresArray, cutoffArray, gradesArray);
    printGradesArray(gradesArray);

}

// All of the print arrays loop through the columns in the outside for loop and the
// rows in the inside loop to make them display how they're supposed to
void printScoresArray(int scoresArray[][SCORESCOLS])
{
    for (int col = 0; col < SCORESCOLS; col++)
    {
        printf("Row %d: ", col);

        for (int row = 0; row < SCORESROWS; row++)
        {
            printf("%d ", scoresArray[row][col]);
        }
        
        printf("\n");
    }
}

void printCutoffArray(int cutoffArray[][CUTOFFCOLS])
{
    for (int col = 0; col < CUTOFFCOLS; col++)
    {
        printf("Row %d: ", col);

        for (int row = 0; row < CUTOFFROWS; row++)
        {
            printf("%d ", cutoffArray[row][col]);
        }
    
        printf("\n");
    }
}

void printGradesArray(char gradesArray[][SCORESCOLS])
{
   for (int col = 0; col < SCORESCOLS; col++)
   {
       printf("Student %d: ", col);

       for (int row = 0; row < SCORESROWS; row++)
       {
           printf("%c ", gradesArray[row][col]);
       }

       printf("\n");
   }
}

// Loops through the scores array and calls different functions depending on what row, therefore class, the loop is on
void convertGradeToLetter(int scoresArray[][SCORESCOLS], int cutoffArray[][CUTOFFCOLS], char gradesArray[][SCORESCOLS])
{
    for (int row = 0; row < SCORESROWS; row++)
    {
        if ( row == 0)
        {
            convertCS1050ToLetter(scoresArray, cutoffArray, gradesArray);

        } else if (row == 1)
        {  
            convertMath1500ToLetter(scoresArray, cutoffArray, gradesArray);

        } else if (row == 2)
        {
            convertEnglish1000ToLetter(scoresArray, cutoffArray, gradesArray);
        }
    }
}

// All the conversion functions checks the values of the scores array against the cutoffs corresponding to its specific
// cutoff grades, then inputs a letter into the grades array based on the outcome of that comparison
void convertCS1050ToLetter(int scoresArray[][SCORESCOLS], int cutoffArray[][CUTOFFCOLS], char gradesArray[][SCORESCOLS])
{
    for (int col = 0; col < SCORESCOLS; col++)
    {
        if (scoresArray[0][col] >= cutoffArray[0][0])
        {
            gradesArray[0][col] = 'A';

        } else if (scoresArray[0][col] < cutoffArray[0][0] && scoresArray[0][col] >= cutoffArray[1][0])
        {
            gradesArray[0][col] = 'B';

        } else if (scoresArray[0][col] < cutoffArray[1][0] && scoresArray[0][col] >= cutoffArray[2][0])
        {
            gradesArray[0][col] = 'C';

        } else if (scoresArray[0][col] < cutoffArray[2][0] && scoresArray[0][col] >= cutoffArray[3][0])
        {
            gradesArray[0][col] = 'D';

        } else if (scoresArray[0][col] < cutoffArray[3][0])
        {
            gradesArray[0][col] = 'F';
        }
    }
}

void convertMath1500ToLetter(int scoresArray[][SCORESCOLS], int cutoffArray[][CUTOFFCOLS], char gradesArray[][SCORESCOLS])
{
    for (int col = 0; col < SCORESCOLS; col++)
    {
        if (scoresArray[1][col] >= cutoffArray[0][1])
        {
            gradesArray[1][col] = 'A';

        } else if (scoresArray[1][col] < cutoffArray[0][1] && scoresArray[1][col] >= cutoffArray[1][1])
        {
            gradesArray[1][col] = 'B';

        } else if (scoresArray[1][col] < cutoffArray[1][1] && scoresArray[1][col] >= cutoffArray[2][1])
        {
            gradesArray[1][col] = 'C';

        } else if (scoresArray[1][col] < cutoffArray[2][1] && scoresArray[1][col] >= cutoffArray[3][1])
        {
            gradesArray[1][col] = 'D';

        } else if (scoresArray[1][col] < cutoffArray[3][1])
        {
            gradesArray[1][col] = 'F';
        }
    }
}

void convertEnglish1000ToLetter(int scoresArray[][SCORESCOLS], int cutoffArray[][CUTOFFCOLS], char gradesArray[][SCORESCOLS])
{
    for (int col = 0; col < SCORESCOLS; col++)
    {
        if (scoresArray[2][col] >= cutoffArray[0][2])
        {
            gradesArray[2][col] = 'A';

        } else if (scoresArray[2][col] < cutoffArray[0][2] && scoresArray[2][col] >= cutoffArray[1][2])
        {
            gradesArray[2][col] = 'B';

        } else if (scoresArray[2][col] < cutoffArray[1][2] && scoresArray[2][col] >= cutoffArray[2][2])
        {
            gradesArray[2][col] = 'C';

        } else if (scoresArray[2][col] < cutoffArray[2][2] && scoresArray[2][col] >= cutoffArray[3][2])
        {
            gradesArray[2][col] = 'D';

        } else if (scoresArray[2][col] < cutoffArray[3][2])
        {
            gradesArray[2][col] = 'F';
        }
    }
}
