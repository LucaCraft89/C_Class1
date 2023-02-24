#include <stdio.h>
#include <stdlib.h>

int main()
{
    int g, h, m, s, tt;
    printf("inserire il numero di giorni: \n"); scanf("%d", &g);
    while (g<0){
        printf("I giorn non possono essere negativi: \n");
        printf("inserire il numero di giorni: \n"); scanf("%d", &g);
    }
    printf("inserire il numero di ore: \n"); scanf("%d", &h);
    while (h<0){
        printf("I ore non possono essere negativi: \n");
        printf("inserire il numero di giorni: \n"); scanf("%d", &h);
    }
    printf("inserire il numero di minuti: \n"); scanf("%d", &m);
    while (m<0){
        printf("I minuti non possono essere negativi: \n");
        printf("inserire il numero di giorni: \n"); scanf("%d", &m);
    }
    printf("inserire il numero di secondi: \n"); scanf("%d", &s);
    while (s<0){
        printf("I secondi non possono essere negativi: \n");
        printf("inserire il numero di giorni: \n"); scanf("%d", &s);
    }
    tt=(((g*24)*60)*60)+((h*60)*60)+(m*60)+s;
    printf("I secondi totali sono: %d \n", tt);
    return 0;
}