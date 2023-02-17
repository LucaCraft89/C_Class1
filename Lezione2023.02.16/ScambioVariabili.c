#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, t;
    printf("Inserisci a: "); scanf("%d",  &a);
    printf("Inserisci b: "); scanf("%d",  &b);
    printf("Before: \n");
    printf("a: "); printf("%d", a); printf("\n");
    printf("b: "); printf("%d", b); printf("\n");
    t=a;
    a=b;
    b=t;
    printf("After: \n");
    printf("a: "); printf("%d", a); printf("\n");
    printf("b: "); printf("%d", b); printf("\n");
    return 0;
}
