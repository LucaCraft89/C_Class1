#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i, q, j, d, n;
    printf("iserisci n \n"); scanf("%d", &n);
    i=0; d=1; q=0;
    do
    {
        q=q+d; 
        d=d+2;
        i=i+1;
    } while (i<n);
    printf("%d \n", q);
    return 0;
}
