#include<stdio.h>

int main(void)
{
    int x, y, product, quotient, sum;

    printf("Enter the first integer:\n");
    scanf("%d", &x);

    printf("Enter the second integer:\n");
    scanf("%d", &y);

    printf("*** Initial values ***\n");
    printf("X = %d\n", x);
    printf("Y = %d\n ", y);

    product = x * y;
    quotient = x / y;
    sum = (x + 1) * y;

    printf("\n*** Calculated values ***\n");
    printf("X times Y %d\n", product);
    printf("X divided by Y %d\n", quotient);
    printf("X plus 1, quantity times Y %d\n", sum);

    printf("\n*** Final Values ***\n");
    printf("X = %d\n", x);
    printf("Y = %d\n", y);

    return 0;
}
