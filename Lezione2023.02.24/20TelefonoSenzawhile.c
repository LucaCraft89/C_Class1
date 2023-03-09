#include <stdio.h>
#include <stdlib.h>

int main()
{
    char n[100];
    int cf, cs, ba, bp, paga;
    printf("inserire il proprio nome \n"); scanf("%s", &n);
    printf("inserire gli scatti della bollte precedente \n"); scanf("%d", &bp);
    printf("inserire gli scatti della bollte precedente \n"); scanf("%d", &bp);
    printf("inserire gli scatti della bollte attual \n"); scanf("%d", &ba);
    printf("inserire canone fisso \n"); scanf("%d", &cf);
    printf("inserire costo di ogni sactto \n"); scanf("%d", &cs);
    paga=((ba-bp)*cs)+cf;
    printf("%s", n); printf(" hai da pagare: %d \n", paga);
    return 0;
}