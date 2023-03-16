#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,x,n,mx,mix,i,ux,MIN,MAX; mx=0; mix=0; ux=0;
    printf("Inserisci quanti numeri devi inserire: \n"); scanf("%d", &N);
    printf("Inserisci il numero di comparazione x: \n"); scanf("%d", &x);
    printf("Inserisci il valore massimo per il n in input: \n"); scanf("%d", &MAX);
    printf("Inserisci il valore Minimo per il n in input: \n"); scanf("%d", &MIN);
    for ( i = 0; i < N; i++)
    {
        printf("Iserisci il numero: \n"); scanf("%d", &n);
        while (n<MIN ||  n>MAX)
        {
            printf("Il numero non deve essere compreso fra %d e %d inclusi \n", MIN, MAX);
            printf("Iserisci il numero: \n"); scanf("%d", &n);
        }
        
        if (n>x)
        {
            mx=mx+1;
        }
        else if (n==x)
        {
            ux=ux+1;
        }
        else
        {
            mix=mix+1;
        }
    }
    printf("Maggiori di x: %d \n", mx);
    printf("Minori di x: %d \n", mix);
    printf("Uguali di x: %d \n", ux);
    return 0;