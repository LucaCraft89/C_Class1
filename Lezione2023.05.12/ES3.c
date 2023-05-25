#include <stdio.h>
#include <stdlib.h>

int agemax, agemin, i=0, ageavr;

void newmax(int age){
    agemax=age;
}

void newmin(int age){
    agemin=age;
}

void newavarage(int age){
    ageavr=(ageavr+age)/i;
}

void vsualizza(int sel){
    switch (sel)
    {
    case 1:
        printf("Età media: %d\n", ageavr);
        break;

    case 2:
        printf("Persona più giovane:\n   %d anno(i)", agemin);
        break;

    case 3:
        printf("Persona più anziana:\n   %d anno(i)", agemax);
        break;
    
    default:
        printf("Selezione non valida!");
        break;
    }
}

void controllo(int age){
    if (age>agemax)
        {
            newmax(age);
        }
        else if (age<agemin)
        {
            newmin(age);
        }
}

int main()
{
    int ch, nm, cont=0, age=0;
    printf("Inserire la propia età\n-: "); scanf("%d", &age);
    agemin=age; agemax=age;
    while (i<=10)
    {
        i=i+1;
        printf("Inserire la propia età\n-: "); scanf("%d", &age);
        printf("Continuare? (1=yes, 0=no) \n-: "); scanf("%d", &cont);
        controllo(age);
        newavarage(age);
        if (cont==0) { break; }
    }
    printf("Visualizzare: \n   1= età media\n   2= persona più giovane\n  3= persona più anziana \n-: ");
    scanf("%d", &ch);
    vsualizza(ch);
    return 0;
}