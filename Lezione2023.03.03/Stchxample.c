#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    while(a){
        printf("inserisci il numero: "); scanf("%d", &a);
        switch (a)
        {
        case 1: a==1;
            printf("Lunedì \n");
            break;
        
        case 2: a==2;
            printf("Martedì \n");
            break;
        
        case 3: a==3;
            printf("Mercoledì \n");
            break;

        case 4: a==4;
            printf("Giovedì \n");
            break;

        case 5: a==5;
            printf("Venerdì \n");
            break;

        case 6: a==6;
            printf("Sabato \n");
            break;

        case 7: a==7;
            printf("Domenica \n");
            break;

        default:
            printf("Selezione errata \n");
            a=100;
            break;
        }
        if (a!=100)
        {
            break;
        }
    }
    return 0;
}