#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, t, m, lp;
    srand(time(NULL));
    n = rand()%100+1;
    printf("Cercare di indovinare il numero compreso fra 1 e 100\n");
    printf("%d", n); printf("\n");
    for (lp = 2; lp > -1; lp--)
    {
        if(lp==2){
            scanf("%d", &m);
        }
        else{
            printf("Hai sbagliato, riprova, hai ancora "); printf("%d", lp+1); printf(" tentativi \n");
            if (m>n) {
                printf("il numero è più basso \n");
            }
            else{
                printf("il numero è più alto \n");
            }
        scanf("%d", &m);
        }
        if (m==n) {
            printf("hai vinto \n");
            break;
        }
        else{
            if (lp==0){
                printf("il numero era: "); printf("%d", n); printf("\n");
            }
        }
    }   
    return 0;
}