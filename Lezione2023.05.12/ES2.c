#include <stdio.h>
#include <stdlib.h>

int i;

void stampa(int n){
    for ( i = 0; i < n; i++)
    {
        printf("*");
    }
}

int main()
{
    int n;
    printf("Inserire il numero di aterischi \n-: ");
    scanf("%d", &n);
    while (n>10)
    {
        printf("in numero non può superare 10 \n");
        printf("Inserire il numero di aterischi \n-: ");
        scanf("%d", &n);
    }
    stampa(n);
    return 0;
}