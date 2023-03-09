#include <stdio.h>
#include <stdlib.h>

/*
    Programma per la soluzione di un sistema binario con metodo di cramer
*/

int main()
{
    float a, a1, b, b1, c, c1, d, dx, dy, x, y; //a, a1, b, b1, c, c1 Coefficienti // d, dx, dy Cefficienti di calcolo // x, y Soluzioni
    /* Sistema:
    ax + by = c
    a1x + b1y = c1
    */

    /* Calcolo dei coefficient di calcolo
    d = (a*b1) - (a1*b)
    dx = (c*b1) - (c1*b)
    dy = (a*c1) - (a1*c)
    */

    /* Calcolo soluzione 
    x = dx/d
    y = dy/d    
    */
   
    /* Condizioni
    d = 0 e dx = 0 = Imposssibile
    solo d = 0 = indeterminata
    */

    // Stampo a schermo il sistema di riferimanto
    printf("Prendendo di riferimento il seguente sistema: \n ax + by = c \n a1x + b1y = c1 \n");

    // Chiedo in input i ceafficienti e le variabili necessarie per il calcolo
    printf("Inserire il coefficiente a: \n"); scanf("%f", &a);
    printf("Inserire il coefficiente b: \n"); scanf("%f", &b);
    printf("Inserire c: \n"); scanf("%f", &c);
    printf("Inserire il coefficiente a1: \n"); scanf("%f", &a1);
    printf("Inserire il coefficiente b1: \n"); scanf("%f", &b1);
    printf("Inserire c1: \n"); scanf("%f", &c1);

    // Calcolo i coefficienti di calcolo d, dx, dy
    d=(a*b1)-(a1*b);
    dx=(c*b1)-(c1*b);
    dy=(a*c1)-(a1*c);

    // Controllo se l'equazione è possibile, impossibile, indeterminata e procedo di conseguenza
    if (d==0 && dx==0){
        // d = 0 e dx = 0 quindi è inpossibile
        printf("L'equazione è impossibile \n");
    }
    else if (d==0 && d!=0)
    {
        //solo d = 0 quindi è indeterminata
        printf("L'equazione è indeterminata \n");
    }
    else
    {
        // sono entrambe diverse da 0 quindi procedo col calcolo di x e y
        x=dx/d;
        y=dy/d;
    }
    
    // Stampo a schermo le soluzioni
    printf("X=%.2f, Y=%.2f \n", x, y);
    
    return 0;
}