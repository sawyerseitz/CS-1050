#include <stdio.h>

void initArrays(int array1[], int array2[], int numElements);
void printArrays(const int array1[], const int array2[], const int array3[], int numElements);
void subtractArrays(int array1[], int array2[], int array3[], int numElements);

void initBonusArrays(int array1[], int array2[]);
void subtractBonusArrays(int array1[], int array2[], int array3[]);
void printBonusArrays(int array1[], int array2[], int array3[]);


int main(void)
{
    // Initialize arrays and the number of the elements of array1
    int array1[256], array2[256], array3[256];
    int numElements = 9;
    
    // Initializes the arrays then subtracts them
    initArrays(array1, array2, numElements);
    subtractArrays(array1, array2, array3, numElements);

    // Prints the first set of arrays
    printf("First arrays:\n");
    printArrays(array1, array2, array3, numElements);

    // Changes the number of elements to be initialized
    numElements = 10;

    // Initializes the second set of arrays then subtracts them
    initArrays(array1, array2, numElements);
    subtractArrays(array1, array2, array3, numElements);

    // Prints the second set of arrays
    printf("\nSecond arrays:\n");
    printArrays(array1, array2, array3, numElements);

    // Changes the number of elements to be initialized
    numElements = 14;

    // Initializes the bonus set of arrays then subtracts them
    printf("\n*** BONUS ***\n");
    initBonusArrays(array1, array2);
    subtractBonusArrays(array1, array2, array3);

    // Prints the bonus set of arrays
    printf("Third arrays:\n");
    printBonusArrays(array1, array2, array3);
    
}


void initArrays(int array1[], int array2[], int numElements)
{
    int cnt = 0;

    // Checks the number of elements to be initialized
    if (numElements == 9)
    {
        // Initialize set 1 array 1
        for (int i = 0; i <= 9; i++)
        {
            cnt += 7;
            array1[i] = cnt;
        }

        cnt = 0;
    
        // Initialize set 1 array 2
        for (int i = 0; i <= 9; i++)
        {
            cnt += 5;
            array2[i] = cnt;
        }

    } else
    {
        cnt = 88;

        // Initializes set 2 array 1
        for (int i = 0; i <= 10; i++)
        {
            array1[i] = cnt;
            cnt -= 8;
        }

        cnt = 60;

        // Initializes set 2 array 2
        for (int i = 0; i <= 10; i++)
        {
            array2[i] = cnt;
            cnt -= 6;
        }
    }
}

void initBonusArrays(int array1[], int array2[])
{
    int bonusCnt = 15;

    // Initializes the arrays for the bonus set
    for (int i = 0; i <= 14; i++)
    {
        array1[i] = bonusCnt;
        bonusCnt -= 1;
    }

    bonusCnt = 9;

    for (int i = 0; i <= 9; i++)
    {
        array2[i] = bonusCnt;
        bonusCnt += 9;
    }

}

void printArrays(const int array1[], const int array2[], const int array3[], int numElements)
{
    // Prints the first and second set of arrays
    for (int i = 0; i <= numElements; i++)
    {   
        printf("\tArray 1 element %d = %d", i, array1[i]);
        printf("\t\tArray 2 element %d = %d", i, array2[i]);
        printf("\t\tArray 3 element %d = %d\n", i, array3[i]);
    }
}

void printBonusArrays(int array1[], int array2[], int array3[])
{
    // Prints the bonus set of arrays
    for (int i = 0; i <= 14; i++)
    {
        printf("\tArray 1 element %d = %d", i , array1[i]);
        // If the number of elements is more than 9, dont print the rest of the second and third arrays
        if (i <= 9)
        {
            printf("\t\tArray 2 elements %d = %d", i, array2[i]);
            printf("\t\tArray 3 elements %d = %d\n", i, array3[i]);
        
        } else
        {
            // Keeps the format good
            printf("\n");
        }
    }

}

void subtractArrays(int array1[], int array2[], int array3[], int numElements)
{
    // Subtracts array 2 from array 1 and inputs the outcome into array 3
    for (int i = 0; i <= numElements; i++)
    {
        array3[i] = array1[i] - array2[i];
    }
}

void subtractBonusArrays(int array1[], int array2[], int array3[])
{
    // Subtracts bonus array 2 from bonus array 1 and inputs the outcome into bonus array 3
    for (int i = 0; i <= 9; i++)
    {
        array3[i] = array1[i] - array2[i];
    }

}

