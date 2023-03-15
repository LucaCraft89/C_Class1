#include <stdio.h>
#include <stdlib.h>

// Includo La libreria per la matematica in C
#include <math.h>

// Esercizio 2

/* Titolo
    Calcolo perimetro e area di un pentagono
*/
/* Breve Descrizione
    Scrivi un programma che, dato in input la misura del lato di un pentagono, visualizzi in output il perimetro e l'area.
*/
/* Input richiesti
    Il lato del pentagono
*/
/* Output richiesti
    Il primetro e l'ara del pentagono
*/

// Definisco la costante dell'area del pentagono
#define fi 1.72

int main()
{
    int l; //l=lato
    float a, p; //a=area, p=perimetro

    // Chiedo in input il lato del pentagono
    printf("Inserisci il lato del pentagono: \n"); scanf("%d", &l);

    // Calcolo il perimetro e area del pentagono
    p=(float)l*5;
    a=(float)(l*l)*fi; // Area pentagono = (lato^2) * costante

    // Stampo a schermo il perimetro e l'area
    printf(" Perimetro: %.2f \n Area: %.2f \n", p, a);
    return 0;
}