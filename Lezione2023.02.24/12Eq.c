#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b, x;
    printf("inserire il coefficiente a (ax=b)\n"); scanf("%f", &a);
    while (a==0){
        printf("a non può essere 0\n");
        printf("inserire il coefficiente a (ax=b)\n"); scanf("%f", &a);
    }
    printf("inserire il coefficiente b (ax=b)\n"); scanf("%f", &b);
    x=b/a;
    printf("X è pari a: %.2f \n", x);
    return 0;
}