#include <stdio.h>
#include <stdlib.h>

int array[200];

void add(int a){
    int ce, co;
    for ( co = 0; co < 199; co++)
    {
        if (array[co-1]==102)
        {
            break;
        }
    }
    array[co] = a;
    printf("Array now:  \n");
    for ( ce = 0; ce < 199; ce++)
    {
        if (array[ce]==102)
        {
            break;
        }
        
        printf("%d", array[ce]);
        
    }
    
}

int main()
{
    int i, a, ii;
    for ( i = 0; i < 200; i++)
    {
        array[i] = 102;
    }
    printf("input what to add: \n");
    scanf("%d", &a);
    add(a);
    for ( ii = 0; ii < 200; ii++)
    {
        printf("input what to add: \n");
        scanf("%d", &a);
        add(a);
    } 
    return 0;
}