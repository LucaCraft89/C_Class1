#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a, b, ris;

int tim(){
    ris=a*b;
    return ris;
}
int sum(){
    ris=a+b;
    return ris;
}
int diff(){
    ris=a-b;
    return ris;
}
int divv(){
    ris=a/b;
    return ris;
}
int main()
{
    int sw=5;
    char choice;
    short plus = {'+', 0}, minus = {'-',0 }, times = {'*',0 }, divide = {'/',0 };
    char *plusp = &plus, minusp = &minus, timesp = &times, dividep = &divide;
    printf("inserire a: ");
    scanf("%d", &a); 
    printf("Inserire b: ");
    scanf("%d", &b); 
    printf("Inserire il simbolo della operazione desiderata: ");
    scanf("%s", &choice);
    printf("\n");
    int molt=tim(), somm=sum(), div=divv(), sotr=diff();
    if (choice==plus)
    {
        sw=1;
    }
    else if (choice==minus)
    {
        sw=2;
    }
    else if (choice==times)
    {
        sw=3;
    }
    else if (choice==divide)
    {
        sw=4;
    }
    else
    {
        sw=5;
    }
    /*while (sw=5)
        {
            printf("Selezione non valida (+,-,*,/) ");
            printf("Inserire il simbolo della operazione desiderata: ");
            scanf("%s", &choice);
            printf("\n");
            if (choice==plus)
            {
                sw=1;
            }
            else if (choice==minus)
            {
                sw=2;
            }
            else if (choice==times)
            {
                sw=3;
            }
            else if (choice==divide)
            {
                sw=4;
            }
            else
            {
                sw=5;
            }
        } */
    switch (sw)
    {
    case 1:
        printf("Addizione: %d \n", somm);
        break;
    
    case 2:
        printf("Sottrazione: %d \n", sotr);
        break;
    
    case 3:
        printf("Moltiplicazione: %d \n", molt);
        break;
    
    case 4:
        printf("Divisione: %d \n", div);
        break;
    
    default:
        printf("Fallback \n");
        break;
    }
    //printf("Addizione: %d \nSottrazione: %d \nMoltiplicazione: %d \nDivisione: %.2f \n", somm, sotr, molt, div);
    return 0;
}