#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, i;
    char c[10];
    printf("Iserisci quante volte vuoi visualizzare la parola  \n");
    scanf("%d", &a);
    printf("Inserire la parola (fino a 10 caratteri) \n");
    scanf("%s", &c);
    for (i = 0; i < a; i++)
    {
        printf("%s", c); printf("\n");
    }
    return 0;
}