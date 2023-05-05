#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int selection(int n, int sel){
    int ris;
    switch (sel)
    {
    case 1:
        ris = square(n);
        printf("Quadrato di %d : %d\n", n, ris);
        break;

    case 2:
        ris = cube(n);
        printf("Cubo di %d : %d\n", n, ris);
        break;

    case 3:
        ris = mysqrt(n);
        printf("Radice di %d : %d\n", n, ris);
        break;
    
    default:
        printf("Selezione invalida\n");
        main();
        break;
    }
    return ris;
}

int square(int n){
    int ris;
    ris = pow(n, 2);
    return ris;
}

int cube(int n){
    int ris;
    ris = pow(n, 3);
    return ris;
}

int mysqrt(int n){
    int ris;
    ris = sqrt(n);
    return ris;
}

int main()
{
    int n, ris, sel;
    printf("inserire il numero: ");
    scanf("%d", &n);
    printf("Inserire cosa si desidera fare \n1=quadrato, \n2=cubo, \n3=radice \n: ");
    scanf("%d", &sel);
    selection(n, sel);
    return 0;
}