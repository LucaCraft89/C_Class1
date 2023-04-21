#include <stdio.h>
#include <stdlib.h>

int me(int);

int main()
{
    int a, b, c;
    printf("Inserire numero: \n");
    scanf("%d", &a);
    if (me(a)==1){
        printf("minore uguale a 0");
    }
    else
    {
        printf("maggiore di 0");
    }
    
    return 0;
}

int me(int a)
{
    int f;
    if (a<=0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}