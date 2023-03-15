#include <stdio.h>
#include <stdlib.h>

// Esercizio 4

/* Titolo
    Operazioni di base
*/
/* Breve Descrizione
    Scrivi un programma che, dato in input due numeri interi, visualizzi, a scelta dell'utente, il risultato di una delle quattro operazioni fondamentali (addizione, sottrazione, moltiplicazione, divisione)
*/
/* Input richiesti
    2 numeri a e b, come li vuole trattare l'utente
*/
/* Output richiesti
    il risultato dell'operazioni richiesta dall'utente
*/

int main()
{
    int a, b, s; //a=il primo numero, b=il secondo numero, s=selezione ddell'utente
    float o; //o=risultato dell'operazione richesta dall'utente

    // Chiedo in imput i 2 numero
    printf("Iserisci un numero a: \n"); scanf("%d", &a);
    printf("Iserisci un numero b: \n"); scanf("%d", &b);

    // Chiedo all'utente come vuole trattare i 2 numeri
    printf("Scegli cosa fare: \n1=addizione\n2=sottrazione\n3=moltiplicazione\n4=divisione\nSelezione: \n"); scanf("%d", &s);

    //Controllo che la selezione inserita dall'utente si avalida
    while (s<1 || s>4)
    {
        // Comunico all'utente che la selezione inserita non è valida
        printf("Selezione invalida \n");

        // Chiedo nuovamente la selezione all'utente
        printf("Scegli cosa fare: \n1=addizione\n2=sottrazione\n3=moltiplicazione\n4=divisione\nSelezione: \n"); scanf("%d", &s);
    }
    
     // Decido come trattare i 2 numeri in base alla selezione dell'utente
    switch (s)
    {
    case 1:
        // Caso 1: L'utente vuole visualizzare l'addizione fra i 2 numeri
        
        // Eseguo l'operazione richiesta dall'utente
        o=(float)a+b;

        // Stampo a schermo il risultato dell'operazione richieta dall'utente
        printf("a+b=%.0f \n", o);

        // Continuo con il programma
        break;
    
    case 2:
        // Caso 2: L'utente vuole visualizzare la sottrazione fra i 2 numeri

        // Eseguo l'operazione richiesta dall'utente
        o=(float)a-b;

        // Stampo a schermo il risultato dell'operazione richieta dall'utente
        printf("a-b=%.0f \n", o);

        // Continuo con il programma
        break;

    case 3:
        // Caso 3: L'utente vuole visualizzare la moltiplicazione fra i 2 numeri

        // Eseguo l'operazione richiesta dall'utente
        o=(float)a*b;

        // Stampo a schermo il risultato dell'operazione richieta dall'utente
        printf("a*b=%.2f \n", o);

        // Continuo con il programma
        break;

    case 4:
        // Caso 4: L'utente vuole visualizzare la divizione fra i 2 numeri

        // Eseguo l'operazione richiesta dall'utente (Che in questo caso deve essere eseguita con un casting esplicito)
        o=(float)a/b;

        // Stampo a schermo il risultato dell'operazione richieta dall'utente
        printf("a/b=%.2f \n", o);

        // Continuo con il programma
        break;
    
    default:
        // In caso il controllo di prma fallisse comunico all'utente che la selezione è  invalida
        printf("Selezione invalida \n");

        // Continuo con il programma
        break;
    }
    return 0;
}