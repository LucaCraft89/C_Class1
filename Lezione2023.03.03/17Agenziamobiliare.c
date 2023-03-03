#include <stdio.h>
#include <stdlib.h>

int main()
{
    float mq, we, pr;
    int a, z;
    printf("Inserisci la zone (1, 2, 3, 4, 5): \n"); scanf("%d", &z);
    printf("Inserisci i mq: \n"); scanf("%f", &mq);
    printf("Inserisci la percentuale: \n"); scanf("%f", &we);
    switch (z)
    {
    case 1:
        pr=(float)1500*mq;
        pr=(float)pr+((pr/100)*we);
        printf("il prezzo finale è: %.2f \n", pr);
        break;

    case 2:
        pr=(float)1200*mq;
        pr=(float)pr+((pr/100)*we);
        printf("il prezzo finale è: %.2f \n", pr);
        break;

    case 3:
        pr=(float)1400*mq;
        pr=(float)pr+((pr/100)*we);
        printf("il prezzo finale è: %.2f \n", pr);
        break;

    case 4:
        pr=(float)1300*mq;
        pr=(float)pr+((pr/100)*we);
        printf("il prezzo finale è: %.2f \n", pr);
        break;

    case 5:
        pr=(float)1000*mq;
        pr=(float)pr+((pr/100)*we);
        printf("il prezzo finale è: %.2f \n", pr);
        break;

    default:
        break;
    }
    return 0;
}