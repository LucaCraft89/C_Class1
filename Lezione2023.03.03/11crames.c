#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, a1, b, b1, c, c1, s, sx, sy, x, y;
    int d;
    printf("Inserisci a: \n"); scanf("%f", &a);
    printf("Inserisci b: \n"); scanf("%f", &b);
    printf("Inserisci c: \n"); scanf("%f", &c);
    printf("Inserisci a': \n"); scanf("%f", &a1);
    printf("Inserisci b': \n"); scanf("%f", &b1);
    printf("Inserisci c': \n"); scanf("%f", &c1);
    s=(float)(a*b1)-(a1*b);
    sx=(float)(c*b1)-(c1*b);
    sy=(float)(a*c1)-(a*c1);
    if (s==0 && sx==0)
    {
        printf("Sistema indeterminato \n");
    }
    else if (s==0 && sx!=0)
    {
        printf("Sistema impossibile \n");
    }
    else
    {
        x=(float)sx/s; y=(float)sy/s;
        printf("x=%.2f, y=%.2f \n", x, y);
    }
    
    
    


    return 0;
}