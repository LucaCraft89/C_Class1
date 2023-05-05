#include <stdio.h>
#include <stdlib.h>

int molt(int n, int nn){
    int ris;
    ris=n*nn;
    return ris;
}

int divi(int n, int nn){
    int ris;
    ris=n/nn;
    return ris;
}

int controllo(int nn){
    int good;
    if (nn==0)
    {
        good=0;
    }
    else
    {
        good=1;
    }
    
}

int main()
{
    int n, nn, moltt, divv;
    printf("Inserire primo numero: ");
    scanf("%d", &n);
    printf("Inserire secondo numero: ");
    scanf("%d", &nn);
    while (controllo(nn)==0)
    {
        printf("Il secondo numero non può essere uguale a 0 \n");
        printf("Inserire secondo numero: ");
        scanf("%d", &nn);
    }
    divv=divi(n, nn);
    moltt=molt(n, nn);
    printf("Moltiplicazione %d*%d : %d \t Divisione %d/%d : %d \n", n, nn, moltt, n, nn, divv);
    return 0;
}