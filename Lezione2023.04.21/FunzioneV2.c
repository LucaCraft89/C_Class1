#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int divv(a,b){
    int ris;
    ris=(float)a/b;
    return ris;
}
int main()
{
    int a, b, somm, sotr, molt, sw=5;
    int div;
    char choice;
    char *plus = "+" , minus = "-", times = "*" , divide = "/";
    printf("inserire a: ");
    scanf("%d", &a); 
    printf("Inserire b: ");
    scanf("%d", &b); 
    printf("Inserire il simbolo della operazione desiderata: ");
    scanf("%s", &choice);
    printf("\n");
    molt=tim(a,b); somm=sum(a,b); div=divv(a,b); sotr=diff(a,b);
    while (sw=5)
        {
            printf("Selezione non valida (+,-,*,/): ");
            scanf("%c", &choice);
            printf("%c", choice);
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
        }
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