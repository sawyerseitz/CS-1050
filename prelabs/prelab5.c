#include <stdio.h>
#include <math.h>

double log16(double x);

int main(void)
{
    int a;
    double b;

    for (int i = 0; pow(2, i) <= 4096; i++)
    {
        a = pow(2, i);
        b = log16(a);
        printf("Log base 16 of %d = %lf\n", a, b);
    }
    
    
    return 0;
}

double log16(double x)
{
    return log10(x)/log10(16);
}
