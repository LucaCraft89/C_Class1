#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    for (i = 0; i < 100; i++)
    {        
        int con2=1, i2=0;
        while(i2<3 && con2<=i/2)
        {
            if(i%con2==0){  
                i2=i2+1;	
            }
            con2=con2+1;
        }
        if (i2==1){
        printf("%d \t", i);
        }
    }
    return 0;
}