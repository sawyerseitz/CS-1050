#include <stdio.h>

#define ROWS 12
#define COLS 3

void print2DArray(int array[][COLS]);
void printRowAverage(int array[][COLS]);
void printColAverage(int array[][COLS]);

int main(void)
{
    int array[ROWS][COLS] = {{ 72, 68, 62 },
                             { 95, 88, 95 },
                             { 93, 97, 86 },
                             { 98, 77, 98 }, 
                             { 99, 92, 90 },
                             { 47, 32, 27 },
                             { 97, 99, 85 },
                             { 85, 95, 91 },
                             { 96, 91, 99 },
                             { 94, 90, 85 },
                             { 98, 98, 90 },
                             { 76, 82, 98 }};
    print2DArray(array);
    printRowAverage(array);
    printColAverage(array);
}

void print2DArray(int array[][COLS])
{
    printf ("Heres the matrix:\n");

    for (int i = 0; i < ROWS; i++)
    {
        printf("\tRow %d: ", i);

        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", array[i][j]);
        }

        printf("\n");
    }

}

void printRowAverage(int array[][COLS])
{
    int rowTotal = 0;
    double rowAverage;

    printf("\nHere are the row averages:\n");

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            rowTotal += array[i][j];
        }

        rowAverage = (double)rowTotal / (double)COLS;

        printf("\tAverage of row %d = %f\n", i, rowAverage);
        rowTotal = 0;
    }

}

void printColAverage(int array[][COLS])
{
    int colTotal = 0;
    double colAverage;

    printf("\nHere are the column averages:\n");

    for (int i = 0; i < COLS; i++)
    {
        colTotal += array[j][i];

            colTotal += array[j][i];
        }
    }
        colAverage = (double)colTotal / (double)ROWS;
    return colAverage;
}
