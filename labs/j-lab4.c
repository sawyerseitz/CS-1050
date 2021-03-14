/***********************
 * Course:   CS1050
 * Semester: Fall 2020
 * Lab:      Lab J
 * Author:   Evan Dobson
 * Pawprint: ejdwcf
 ***********************/

#include <stdio.h>

int main(void) {
    // The useless variable is just so I can have an operation to do if one of the ternary operators is true,
    // it doesn't do anything practical
    int start, limit, i, useless;

    // Prompts the user to enter in a value and stores that value into the start variable
    printf("Enter a start: ");
    scanf("%d", &start); 
    
    for (i = 0; i > -1; i++) {
        // If the start value is in bounds, set i = -2, otherwise prompt the user again
        (start < 4 || start > 96) ? printf("Enter a start: ") : (i = -2);

        // If i was set to -2 in the previous statement, set the useless variable to 1, 
        // otherwise put the users value into start and restart the for loop
        (i < -1) ? (useless = 1) : scanf("%d", &start);
    }


    for (i = 0; i > -1; i++) {
        // If the limit value is in bounds, set i = -2, otherwise ask the user for  
        (limit < 4 || limit > 96) ? printf("Enter a limit: ") : (i = -2);
        
        // If i was set to -2 in the previous statement, print the start value,
        // otherwise store the store the user entered variable into limit and restart the loop
        (i < -1) ? (printf("%d", start)) : scanf("%d", &limit);
    }

    // Sets i to start + 3 because start was already printed, increments i by 3 everytime
    for (i = start + 3; i <= limit; i += 3) {
        printf("%d ", i);
    }

}
