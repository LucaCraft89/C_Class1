#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h, m, i, a, ht, mt, hu, mu; ht=0; mt=0;
    for ( i = 0; i < 4; i++)
    {
        printf("Isersci ore e minuti di entrata spaziti da un invio \n"); scanf("%d %d", &h, &m);
        printf("Isersci ore e minuti di uscita spaziti da un invio \n"); scanf("%d %d", &hu, &mu);
        ht=ht+(hu-h); mt=mt+(mu-m);
    }
    printf("Ore e min totali da retrivuire: %d:%d \n", ht, mt);
    
    return 0;
}