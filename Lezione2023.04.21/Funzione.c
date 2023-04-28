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
float divv(a,b){
    float ris;
    ris=(float)a/b;
    return ris;
}
int main()
{
    int a, b, somm, sotr, molt;
    float div;
    printf("inserire a: ");
    scanf("%d", &a); 
    printf("Inserire b: ");
    scanf("%d", &b); 
    printf("\n");
    molt=tim(a,b);
    somm=sum(a,b);
    div=divv(a,b);
    sotr=diff(a,b);
    printf("Addizione: %d \nSottrazione: %d \nMoltiplicazione: %d \nDivisione: %.2f \n", somm, sotr, molt, div);
    return 0;
}