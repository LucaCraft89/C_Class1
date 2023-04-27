#include <stdio.h>
#include <stdlib.h>


int tim(a,b){
    int ris;
    ris=a*b;
    return ris;
}
int sum(a,b){
    int ris;
    ris=a+b;
    return ris;
}
int diff(a,b){
    int ris;
    ris=a-b;
    return ris;
}
int main()
{
    int a, b, c;
    a=3;
    b=4;
    c=tim(a,b);
    printf("%d \n", c);
    return 0;
}