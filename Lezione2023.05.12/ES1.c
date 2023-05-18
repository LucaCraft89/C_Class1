#include <stdio.h>
#include <stdlib.h>

int i;

int menu(){
    int sel, i;
    printf("Seleziona cosa si desidera visualizzare: \n1= Numeri da 1 a 20\t2= numeri pari fino a 20\t3= numeri dispari fino a 20\n-: ");
    scanf("%d", &sel);
    return sel;
}

void alln(){
    for ( i = 0; i < 20; i++)
        {
            printf("%d\t", i+1);
        }
}

void even(){
    for ( i = 0; i < 20; i++)
        {
            if (i%2!=0)
            {
                printf("%d\t", i+1);
            }
        }
}

void odd(){
    for ( i = 0; i < 20; i++)
        {
            if (i%2==0)
            {
                printf("%d\t", i+1);
            }
        }
}

int main()
{
    int sel, i , n, nn, ii;
    sel = menu();
    do
    {
        if (sel==1)
        {
            alln();
            break;
        }
        else if (sel==2)
        {
            even();
            break;
        }
        else if (sel==3)    
        {
            odd();
            break;
        }
        else
        {
            printf("Selezione non valida \n");
            sel = menu();
        }
    } while (sel>=4 || sel <=0);
    return 0;
}