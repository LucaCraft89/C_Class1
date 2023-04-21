#include <stdio.h>
#include <stdlib.h>

int a, b, c;

int sum(){
    int ris;
    ris=a+b;
    return ris;
}
int diff(){
    int ris;
    ris=a-b;
    return ris;
}
int main()
{
    a=3;
    b=4;
    c=diff();
    printf("%d \n", c);
    return 0;
}