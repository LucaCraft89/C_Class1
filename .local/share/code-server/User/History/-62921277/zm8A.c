#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float ab, bc, x, y, A, p;
    printf("inserisci le misure der triangulu: \n");
    scanf("%f%f", &ab, &bc);
    p=(2*ab+bc)/2;
    x=p-ab;
    x=pow(x,2);
    y=p-bc;
    A=sqrt(p*x*y);
    printf("Il perimetro è: %.2f; l'area è: %.2f\n", 2*p, A);
    return 0;
}