#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int aneg(float a){
    int yes;
    if (a<0)
    {
        yes=1;
    }
    else if (a==0)
    {
        yes=2;
    }
    else
    {
        yes=0;
    }
    return yes;    
}

float delta(float a, float b, float c){
    float delta, bsq;
    bsq=pow(b, 2);
    delta = bsq - (4*a*c);
    return delta;
}

float sol(float a, float b, float dlt){
    float x;
    x = ((-b) + sqrt(dlt))/(2*a);
    return x;
}

float soll(float a, float b, float dlt){
    float xx;
    xx = ((-b) - sqrt(dlt))/(2*a);
    return xx;
}

float invertisimbolo(float n){
    float mn;
    mn = -n;
    return mn;
}

void stampasol(float x, float xx){
    printf("------- Soluzioni -------- \n\n       x_1 = %.2f       \n       x_2 = %.2f      \n\n--------------------------", x, xx);
}

void impossibile(){
    printf("\n Delta minore di 0: \n ------------------------- \n | Equazione Impossibile | \n -------------------------");
}

int main()
{
    float a, b, c, dlt, x, xx, i, ii;
    printf("Prrendi di Riferimento la seguente equazione di secondo grado \n \n   ax^2 + bx + c = 0 \n \nInserisci il coefficiente a: ");
    scanf("%f",  &a);
    printf(" \nEquazione attuale: \n \n   %.2fx^2 + bx + c = 0 \n \nInserisci il coefficiente b: ", a);
    scanf("%f",  &b);
    printf(" \nEquazione attuale: \n \n   %.2fx^2 + %.2fx + c = 0 \n \nInserisci il coefficiente c: ", a, b);
    scanf("%f",  &c);
    printf(" \nEquazione attuale: \n \n   %.2fx^2 + %.2fx + %.2f = 0 \n \n ", a, b, c);
    if (aneg(a)==1)
    {
        printf("Coefficiente a è minore di zero: \n \n inverto i segni dell'equazione...\n");
        a=invertisimbolo(a);
        b=invertisimbolo(b);
        c=invertisimbolo(c);
        printf("Equazione attuale: \n \n %.2fx^2 + %.2fx + %.2f = 0 \n", a, b, c);
    }
    dlt=delta(a, b, c);
    if (dlt<0)
    {
        impossibile();
    }
    else
    { 
        printf("\nCalcolo il delta; \n \n   b^2 - 4ac = %.2f - 4(%.2f)(%.2f) = %.2f \n \n", b, a, c, dlt);   
        x=sol(a, b, dlt);
        printf("Calcolo possibili soluzioni: \n \n   x_1= (-b + sqrt(delta))/(2*a) = (-%.2f + sqrt(%.2f))/(2*%.2f) = %.2f \n ", b, dlt, a, x);
        xx=soll(a, b, dlt);
        printf("\n   x_2= (-b - sqrt(delta))/(2*a) = (-%.2f - sqrt(%.2f))/(2*%.2f) = %.2f \n \n", b, dlt, a, xx);
        stampasol(x, xx);
    }
    return 0;
}