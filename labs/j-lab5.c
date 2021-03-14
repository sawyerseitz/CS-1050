/************************
 * Course:   CS 1050
 * Semester: Fall 2020
 * Lab:      Lab 5
 * Author:   Evan Dobson
 * Pawprint: ejdwcf
 * *********************/

#include <stdio.h>
#include <math.h>

double getLog(double x, double base);

int main(void)
{
    double x, base;

    for (x = 8; x <= 16384; x *= 2) {
        printf("Number %d:\n", (int)x);

        for (base = 4; base <= 64; base *= 2) {
            printf("\tlog base %d = %f\n", (int)base, getLog(x, base));

        }

        printf("\n");
    }

}

double getLog(double x, double base)
{
    return (log10(x)/log10(base));
}
