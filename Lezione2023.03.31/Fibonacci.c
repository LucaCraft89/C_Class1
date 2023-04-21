#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, c=0, c2=1;
    printf("INserire n \n");
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        c2=c+c2;
        if (c>=n)
        {

            n=-1;
        }
        else
        {
            printf("%d  %d  ", c, c2);
        }
        c=c2+c;
    }
    return 0;
}