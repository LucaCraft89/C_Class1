#include <stdio.h>
#include <stdlib.h>

void swap(int *pa, int *pb){
    int t=*pa;
    *pa=pb;
    *pb=t;
}

int main()
{
    int a=1; 
    int b=2;
    a=1; 
    b=2;
    printf("a=%d \tb=%d \n", a, b);
    swap(&a, &b);
    printf("a=%d \tb=%d \n", a, b);
    return 0;
}