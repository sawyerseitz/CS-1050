/***********************
 * Course:   CS 1050
 * Semester: Fall 2020
 * Lab:      Lab 2
 * Author:   Evan Dobson
 * Pawprint: ejdwcf
***********************/

// Includes the standard c library
#include <stdio.h>

int main(void)
{
    // Declares the variables a, b, c, and d
   int a, b, c, d;

    // Asks the user for input and stores the input in the declared variables
   printf("Enter 4 numbers (a, b, c, d) separated by spaces: ");
   scanf( "%d %d %d %d", &a, &b, &c, &d);

    // Prints the values stored in the variables on screen
   printf("*** Initial Values ***");
   printf("\na = %d", a);
   printf("\nb = %d", b);
   printf("\nc = %d", c);
   printf("\nd = %d", d);

    /* Uses algebra to calculate different values and prints them 
     * on screen with explanations about what got calculated. 
     * The original values did not change */
   printf("\n\n*** Calculated values ***");
   printf("\nThe sum of a and d = %d ", a + d);
   printf("\nThe product of b and d = %d", b * d);
   printf("\nThe integer quotient of a divided by b = %d", a / b);
   printf("\nThe integer remainder of c divided by d = %d", c % d);
   printf("\nThe product of a and c divided by the quantity b minus d = %d\n", (a * c) / (b - d));

}
