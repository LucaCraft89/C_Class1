#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b, c, d;
    printf("Iserire a \n");
    scanf("%f", &a);
    printf("Iserire b \n");
    scanf("%f", &b);
    printf("Iserire c \n");
    scanf("%f", &c);
    printf("Iserire d \n");
    scanf("%f", &d);
    if (a>b && a>c && a>d){
        printf("Il numero maggiore è: "); printf("%f", a); printf("\n");
    }
    else{
        if (b>c  && b>d){
            printf("Il numero maggiore è: "); printf("%f", b); printf("\n");
        }
        else{
            if (c>d){
                printf("Il numero maggiore è: "); printf("%f", c); printf("\n");
            }
            else{
                printf("Il numero maggiore è: "); printf("%f", d); printf("\n");
            }
        }
    }
    return 0;
}