#include <stdio.h>
#include <stdlib.h>

float sqq(float);

int main()
{
    float a, ss;
    printf("Iserire num: \n");
    scanf("%f", &a);
    ss = sqq(a);
    printf("%f", ss);
    return 0;
}

float sqq(float a) 
{
    float q;
    q=a*a;
    return q;
}