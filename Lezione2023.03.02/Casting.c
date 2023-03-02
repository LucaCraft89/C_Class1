#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    float c;
    printf("inerisci a: \n"); scanf("%d", &a);
    printf("inerisci b: \n"); scanf("%d", &b);
    c=(float)a/b;
    printf("c vale: %.1f \n", c);
    return 0;
}