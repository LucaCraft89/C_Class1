#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Includo la libreria per la matematica avanzata


/* Titolo
    Risoluzione per x di un'equazione di secondo grado
*/

/* Descrizione
    Il programma deve calcolare le 2 x per l'equazione di secondo grado i quali 
    coefficienti forniti i n input dall'utente
*/


// Creo una funzione che mi dice se il coefficiente a è minore a 0
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

// dichiaro una funzione che calcola il delta restituendo un numero di tipo float
float delta(float a, float b, float c){
    float delta, bsq;
    bsq=pow(b, 2);
    delta = bsq - (4*a*c);
    return delta;
}

// creo 2 fonzioni che mi calcolano le soluzioni per x
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

// dichiaro una funzione che inverti il simbolo in input
float invertisimbolo(float n){
    float mn;
    mn = -n;
    return mn;
}

// creo una funzione che stampa a schermo le soluzioni date come parametri
void stampasol(float x, float xx){
    printf("------- Soluzioni -------- \n\n       x_1 = %.2f       \n       x_2 = %.2f      \n\n--------------------------", x, xx);
}

// dichiaro una funzione che mi permette di stampare a schermo "Equazione Impossibile" se necessario
void impossibile(){
    printf("\n Delta minore di 0: \n ------------------------- \n | Equazione Impossibile | \n -------------------------");
}

int main()
{
    float a, b, c, dlt, x, xx; //dichiaro le variabili necessarie

    /* Variabili
        a = coefficiente di x^2
        b = coefficiente di x
        c = termine noto
        dlt = delta
        x = prima soluzione
        xx = seconda soluzione
    */

    // chiedo in input i coefficienti fornendo una equazione di esempio e modificandola ogni volta che veiene inserito un coefficiente
    printf("Prrendi di Riferimento la seguente equazione di secondo grado \n \n   ax^2 + bx + c = 0 \n \nInserisci il coefficiente a: ");
    scanf("%f",  &a);
    printf(" \nEquazione attuale: \n \n   %.2fx^2 + bx + c = 0 \n \nInserisci il coefficiente b: ", a);
    scanf("%f",  &b);
    printf(" \nEquazione attuale: \n \n   %.2fx^2 + %.2fx + c = 0 \n \nInserisci il coefficiente c: ", a, b);
    scanf("%f",  &c);
    printf(" \nEquazione attuale: \n \n   %.2fx^2 + %.2fx + %.2f = 0 \n \n ", a, b, c);

    // controllo se a è maggiore di 0 tramite la funzione aneg()
    if (aneg(a)==1)
    {
        // se a è minore di 0 inverto i simboli di tutti i coefficienti avvertendo l'utente stampando un messaggio a schermo
        printf("Coefficiente a è minore di zero: \n \n inverto i segni dell'equazione...\n");
        a=invertisimbolo(a);
        b=invertisimbolo(b);
        c=invertisimbolo(c);

        // fornisco a schermo la nuova quazione dopo in cambio di segni
        printf("Equazione attuale: \n \n %.2fx^2 + %.2fx + %.2f = 0 \n", a, b, c);
    }
    
    // eseguo il calcolo del Delta inserendolo nella variabile
    dlt=delta(a, b, c);

    // controllo se il delta è minore di 0
    if (dlt<0)
    {
        // se il delta è minore di 0 comunico all'utente 
        // che l'equazione è impossibile richiamando la funzione che stampa il messaggio a schermo
        impossibile();
    }
    else
    { 
        // se il delta è maggiore di 0 continuo con il calcolo delle soluzioni stampando a schermo anche le formule
        printf("\nCalcolo il delta; \n \n   b^2 - 4ac = %.2f - 4(%.2f)(%.2f) = %.2f \n \n", b, a, c, dlt);   
        x=sol(a, b, dlt);
        printf("Calcolo possibili soluzioni: \n \n   x_1= (-b + sqrt(delta))/(2*a) = (-%.2f + sqrt(%.2f))/(2*%.2f) = %.2f \n ", b, dlt, a, x);
        xx=soll(a, b, dlt);
        printf("\n   x_2= (-b - sqrt(delta))/(2*a) = (-%.2f - sqrt(%.2f))/(2*%.2f) = %.2f \n \n", b, dlt, a, xx);

        // stampo a schermo le soluzioni tramite la funzione che ho dichiarato in precedenza
        stampasol(x, xx);
    }
    return 0;
}