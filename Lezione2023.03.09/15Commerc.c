#include <stdio.h>
#include <stdlib.h>

/* Titolo
    Prezzo scontato in base ai pezzi
*/

/* Breve deccrizione
    Un programma in c per calcolare in prezzo da pagare in base al numero dei pezzi e il prezzo unitario tramite la scelta multipla
*/

/* Input richiesti
    pezzi, prezzo unitario
*/

/* Output richiesti
    prezzo scontato
*/


int main()
{
    int n, s; // n = numero pezzi, p = prezzo unitario, s = sconto, pn = prezzo non scontato
    float ps, p, pn; // ps = presso scontato
    
    /* Calcolo del prezzo scontato
        p = pn * (1 - s)
    */

    // Chiedo in imput il necessario
    printf("Inserire il numero di pezzi: \n "); scanf("%d", &n); // Input del numero di pezzi
    printf("Inserire il Prezzo unitario: \n "); scanf("%f", &p); // input del prezzo unitario

    // Calcolo il prezzo da pagare prima dello sconto
    pn=(float)p*n;

    //scelgo lo sconto da applicare
    switch (n)
    {
    case :
        /* code */
        break;
    
    default:
        break;
    }



    return 0;
}