#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i, n, p;
    printf("Inserisci il nu7mero di numeri dácui fare il quadrato \n"); scanf("%d", &n);
    for ( i = 1; i < n+1; i++)
    {
        p=pow(i,2);
        printf("%d ^ 2 = %d \n", i, p);
    }
    
    return 0;
}
