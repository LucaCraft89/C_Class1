#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, i, x, n, s,x1,x2;
    printf("a: \n"); scanf("%d", &a);
    printf("x: \n"); scanf("%d", &x); x1=x;
    i=0;
    x=a+1;
    x2=x+1;
    do
    {
        x=x+x2;
        x2=x;
        i=i+1;
        
    } while (x<x1);
    printf("Interazioni: %d \n", i+1);
    return 0;
}