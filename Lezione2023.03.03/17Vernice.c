#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, v, ad;
    printf("Inserisci i Kg di vernice: \n"); scanf("%f", &v);
    while (v<0)
    {
        printf("Non puoi avere Kg di vernice negativi \n");
        printf("Inserisci i Kg di vernice: \n"); scanf("%f", &v);
    }
    if (v<=10){
        a=(float)v*10;
        printf("I grammi di additivo da aggiungere sono: %.2f \n", a);
    }
    else{
        a=100+((v-10)*5);   
        printf("I grammi di additivo da aggiungere sono: %.2f \n", a);
    }
    return 0;
}