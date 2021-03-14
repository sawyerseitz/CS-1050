#include <stdio.h>

int main(void) {
    int num = 1;
    int oddOrEven;

    while(num <= 20) {
        oddOrEven = num % 2;
        printf("%d ", num);

        if(oddOrEven == 0) {
            printf("- even\n");

        } else {
            printf("- odd\n");

        }

        num++;
    }


    return 0;
}
