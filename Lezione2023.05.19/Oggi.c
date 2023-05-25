#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=5;
    int *p=&x;
    printf("x = %d \n", *p);
    return 0;
}