#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a1, a2;
    float a, b, f;
    while(a1){
        printf("Inserisci la selezione (1, 2, 3): \n"); scanf("%d", &a1);
        switch (a1)
        {
        case 1:
            printf("Inserisci lato a: \n"); scanf("%f", &a);
            printf("Inserisci lato b: \n"); scanf("%f", &b);
            printf("Perimetro: %.2f \n", ((a*2)+(2*b)));
            a2=5;
            break;
        
        case 2:
            printf("Inserisci lato a: \n"); scanf("%f", &a);
            printf("Inserisci lato b: \n"); scanf("%f", &b);
            printf("Area: %.2f \n", a*b);
            a2=8;
            break;

        case 3:
            printf("Inserisci lato a: \n"); scanf("%f", &a);
            printf("Inserisci lato b: \n"); scanf("%f", &b);
            printf("Diagonale: %.2f \n", sqrt((a*a)+(b*b)));
            a2=9;
            break;

        default:
            printf("Selezione errata \n");
            a2=100;
            break;
        }
        if (a2!=100)
        {
            break;
        }
    }
    return 0;
}