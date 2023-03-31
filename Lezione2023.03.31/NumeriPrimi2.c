#include <stdio.h>
#include <stdlib.h>

int main() {
    int i,j,n,counter;
    printf("inserire un numero:\n");
    scanf("%d",&n);

    for(i=2;i<=n;i++){
        counter=0;
        for(j=1;j<=i;j++){
            if(i%j==0 && j!=1 && j!=i)
                counter++;
        }
        if(counter==0)
            printf("%d\n",i);
    }
    return 0;
}