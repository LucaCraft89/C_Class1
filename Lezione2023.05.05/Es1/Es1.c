#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int controllo(int n){
    int good;
    if (n<0)
    {
        good=0;
    }
    else
    {
        good=1;
    }
    return good;
}

int main()
{
    int n, rad;
    printf("Inserire il numero di cui si desidera visualizzare la radice quedrata: ");
    scanf("%d", &n);
    while (controllo(n)==0)
    {
        printf("Il numero non può essere minore di 0 \n");
        printf("Inserire il numero di cui si desidera visualizzare la radice quedrata: ");
        scanf("%d", &n);
    }
    rad = sqrt(n);
    printf("Radice di %d : %d \n", n, rad);
    return 0;
}