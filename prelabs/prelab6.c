#include <stdio.h>

int initializeArray(int array[], int begin, int end, int increment);
void printArray(int array[], int size);


int main(void) {
    int array[256], size;

    size = initializeArray(array, 2, 20, 2);
    printf("First Array: \n");

    printArray(array, size);

    size = initializeArray(array, 1, 97, 3);
    printf("\nSecond Array: \n");

    printArray(array, size);
}


int initializeArray(int array[], int begin, int end, int increment) {
    int i, a = begin;
    
    for (i = 0; a <= end; i++) {
        array[i] = a;
        a += increment;
    }
    
    return i;
}


void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("\tElement %d = %d\n", i, array[i]);
    }
}



