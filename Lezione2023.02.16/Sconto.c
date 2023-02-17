#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b, c, d;
    printf("Inserire prezzo \n");
    scanf("%f", &a);
    printf("Inserire Numero prezzi \n");
    scanf("%f", &b);
    printf("Inserire percentuale di sconto \n");
    scanf("%f", &c);
    // Sconto = (prezzo*npezzi)*(1-percsconto/100)
    d=(a*b)*(1-c/100);
    printf("Lo sconto è: "); printf("%f", d); printf("\n");
    return 0;
}