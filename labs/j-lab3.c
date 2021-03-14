/************************
 * Course:   CS 1050
 * Semester: Fall 2020
 * Lab:      Lab 3
 * Author:   Evan Dobson
 * Pawprint: ejdwcf
 * *********************/

#include <stdio.h>

int main(void)
{
    for (int i = 26; i >= 4; i--) {
        if (i % 5 == 0) {
            printf("%d $$$\n", i);

        } else if (i == 17) {
            printf("%d this goes to SEVENTEEN\n", i);

        } else {
            printf("%d\n", i);
        }
    }

}
