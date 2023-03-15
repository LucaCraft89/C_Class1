#include <stdio.h>
#include <stdlib.h>

// Includo la libreria per la matematica in C
#include <math.h>

// Esercizio 3

/* Titolo
    Equazione di secondo grado
*/
/* Breve Descrizione
    Scrivere un programma in C che discuta e risolva un'equazione di secondo grado del tipo ax^2+bx+c=0, calcolando le eventuali soluzioni (radici) della stessa.
*/
/* Input richiesti
    Coefficienti di x^2 e x, termine noto
*/
/* Output richiesti
    Se l'equazione è possibile i 2 risultati altrimenti comunicare che è impossibile
*/

int main()
{
    int a, b, c; //a=coefficiente di x^2, b=coefficiente di x, c=termine noto
    float dl, x1, x2; //dl=discriminante, x1=primo risultato, x2=secondo risultato

    // fornisco a schermo un'equazione di secondo grado di riferimento
    printf("Dato come riferimento l'equazione di secondo grado: ax^2 + bx + c = 0\n");

    // Chiedo in imput i coefficienti e il termine noto
    printf("Inserisci a: \n"); scanf("%d", &a);
    printf("Inserisci b: \n"); scanf("%d", &b);
    printf("Inserisci c: \n"); scanf("%d", &c);

    // Calcolo la discriminante
    dl=(float)(b*b)-(4*(a*c)); // Discriminante= b^2 - 4ac

    // Controllo se l'quazione è impossibile o indeterminata sapendo che lo è quando la descriminante è minore di 0
    if (dl<0)
    {
        // Cumunico all'utente che l'equazione è impossibile o indeterminata
        printf("L'equazione è inderminata o impssibile \n");
    }

    // In caso fosse possibile procedo
    else{
        
        // Calcolo le soluzioni
        x1=(float)((-1*b)+(sqrt(dl)))/(2*a); // x1 = (-b + sqrt(discriminante))/(2a)
        x2=(float)((-1*b)-(sqrt(dl)))/(2*a); // x2 = (-b - sqrt(discriminante))/(2a)

        // Stampo a schermo le soluzioni
        printf("x1=%.2f \n", x1);
        printf("x2=%.2f \n", x2);
    }
    
    return 0;
}