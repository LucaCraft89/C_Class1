#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b, c;
    printf("Iserire a \n");
    scanf("%f", &a);
    printf("Iserire b \n");
    scanf("%f", &b);
    printf("Iserire c \n");
    scanf("%f", &c);
    if (a>b && a>c){
        printf("Il numero maggiore è: "); printf("%f", a); printf("\n");
    }
    else{
        if (b>c){
            printf("Il numero maggiore è: "); printf("%f", b); printf("\n");
        }
        else{
            printf("Il numero maggiore è: "); printf("%f", c); printf("\n");
        }
    }
    return 0;
}