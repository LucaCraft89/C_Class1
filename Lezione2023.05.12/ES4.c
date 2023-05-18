#include <stdio.h>
#include <stdlib.h>

int i;

int moltt(int a, int b){
    int aa=a;
    for ( i = 1; i < b; i++)
    {
        a=a+(i+1);
    }
    return a;
}z

int divv(int a, int b){
    int c=0, v=b;
    while (v<12)
    {
        c=c+1;
        v=v+v;
    }
    return c;
}

int main()
{
    int sel, molt, div, a, b;
    printf("Cosa si vuole fare: \n   1= moltiplicazionio\n   2=divisione \n-: ");
    scanf("%d", &sel);
    printf("Inserire il primo numero\n-: ");
    scanf("%d", &a);
    printf("Inserire il secondo numero\n-: ");
    scanf("%d", &b);
    switch (sel)
    {
    case 1:
        molt=moltt(a,b);
        printf("Moltiplicazione: %d\n", molt);
        break;

    case 2:
        div=divv(a,b);
        printf("Divisione: %d \n", div);
        break;
    
    default:
        break;
    }
    return 0;
}