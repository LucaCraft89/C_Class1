#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i=0, a;
    printf("Iserisci il numero: \n"); scanf("%d", &a);
    while (a<=0)
    {
        printf("il numero non può essere minore o uguale a 0 \n");
        printf("Iserisci il numero: \n"); scanf("%d", &a);
    }
    printf("I numeri che vengono prima di %d sono: \n", a);
    while (i<a)
    {
        printf("%d \t", i);
        i=i+1;
    }
    
    return 0;
}  