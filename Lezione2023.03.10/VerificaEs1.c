#include <stdio.h>
#include <stdlib.h>

//Esercizio 1

/* Titolo
    Gradi, Primi, Secondi in secondi
*/
/* Breve Descrizione
    Scrivi un algoritmo che, data in input la misura di un angolo in gradi (G), primi (P) e secondi (S), determini la sua ampiezza espressa in secondi.
*/
/* Input richiesti
    Gradi, primi, secondi di un angolo
*/
/* Output richiesti
    secondi totali dell'angolo
*/

int main()
{
    int g, p, s; //g=gradi, p=primi, s=secondi

    // Chiedo in imput i gradi, primi e secondi dell'angolo
    printf("Inserisci i Gradi dell'angolo: \n"); scanf("%d", &g);
    printf("Inserisci i Primi dell'angolo: \n"); scanf("%d", &p);
    printf("Inserisci i Secondi dell'angolo: \n"); scanf("%d", &s);

    // Calcolo i seocndi totali Sapendo che:
    /*
        1 grado = 60 primi
        1 primo = 60 secondi  
    */
    s=((g*60)*60)+(p*60)+s;

    // Stampo a schermo i secondi totali
    printf("I secondi totali sono: %d \n", s);
    return 0;
}