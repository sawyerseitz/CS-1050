#include <stdio.h>


int main(void)
{
    int limit;

    printf("Enter a limit: ");
    scanf("%d", &limit);

    for (int i = 0; i * i <= limit; i++) {
        ((i * i + 3) == 52) ? printf("Dabo!\n%d\n", i * i) : printf("%d\n", i * i);
    
    }
    
    return 0;
}
