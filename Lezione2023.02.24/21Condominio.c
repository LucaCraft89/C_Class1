#include <stdio.h>
#include <stdlib.h>

int main()
{
    float mq, k, x, t, audittsposrt;
    printf("inserire i metri quadri \n"); scanf("%f", &mq);
    while (mq<0){
        printf("non può essere minore di 0 \n");
        printf("inserire i metri quadri \n"); scanf("%f", &mq);
    }
    printf("inserire la tassa \n"); scanf("%f", &k);
    while (k<0){
        printf("non può essere minore di 0 \n");
        printf("inserire la tassa \n"); scanf("%f", &k);
    }
    printf("inserire la percentiaòe \n"); scanf("%f", &t);
    while (t<0){
        printf("non può essere minore di 0 \n");
        printf("inserire la percentiaòe \n"); scanf("%f", &t);
    }
    printf("inserire il canono efisso \n"); scanf("%f", &x);
    while (x<0){
        printf("non può essere minore di 0 \n");
        printf("inserire il canono efisso \n"); scanf("%f", &x);
    }
    audittsposrt=(x+(k*mq))*(t/100);
    printf("Devi pagare: %.2f \n", audittsposrt);
    return 0;
}