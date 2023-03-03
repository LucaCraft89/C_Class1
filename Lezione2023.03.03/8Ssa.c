#include <stdio.h>
#include <stdlib.h>

int main()
{
    float sp; 
    int a;
    printf("Inserisci la spesa: \n"); scanf("%f", &sp);
    if (sp<50){
        a=50;
    }
    else if (sp>=50 && sp<100)
    {
        a=100;
    }
    else
    {
        a=150;
    }
    
    switch (a)
    {
    case 50:
        sp=(float)sp-((sp/100)*10);
        printf("Il prezzo finale è: %.2f \n", sp);
        break;

    case 100:
        sp=(float)sp-((sp/100)*20);
        printf("Il prezzo finale è: %.2f \n", sp);
        break;
    
    case 150:
        sp=(float)sp-((sp/100)*30);
        printf("Il prezzo finale è: %.2f \n", sp);
        break;

    default:
        break;
    }
    return 0;
}