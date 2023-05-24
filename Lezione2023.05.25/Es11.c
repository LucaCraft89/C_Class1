#include <stdio.h>

float saldo = 0;
int numVersamenti = 0;
float sommaVersamenti = 0;
int numPrelevamenti = 0;
float sommaPrelevamenti = 0;
int numAssegni = 0;
float sommaAssegni = 0;

void effettuaVersamento(float importo) {
    saldo += importo;
    numVersamenti++;
    sommaVersamenti += importo;
}

void effettuaPrelevamento(float importo) {
    saldo -= importo;
    numPrelevamenti++;
    sommaPrelevamenti += importo;
}

void emettiAssegno(float importo) {
    saldo -= importo;
    numAssegni++;
    sommaAssegni += importo;
}

void mostraDatiConto() {
    printf(" - Numero di versamenti effettuati: %d\n\n", numVersamenti);
    printf(" - Somma totale versata: %.2f\n\n", sommaVersamenti);
    printf(" - Numero di prelevamenti effettuati: %d\n\n", numPrelevamenti);
    printf(" - Somma totale prelevata: %.2f\n\n", sommaPrelevamenti);
    printf(" - Numero di assegni emessi: %d\n\n", numAssegni);
    printf(" - Somma totale prelevata con gli assegni: %.2f\n\n", sommaAssegni);
    printf(" - ||Saldo finale||: %.2f\n\n", saldo);
}

int main() {
    float saldoIniziale;
    printf("Inserisci il saldo iniziale: ");
    scanf("%f", &saldoIniziale);
    
    saldo = saldoIniziale;

    int scelta;
    float importo;
    
    do {
        printf("\nOperazioni disponibili:\n");
        printf("1. Versamento\n");
        printf("2. Prelevamento\n");
        printf("3. Emissione di assegno\n");
        printf("0. Esci\n");
        printf("~: ");
        scanf("%d", &scelta);
        
        switch (scelta) {
            case 1:
                printf("Inserisci l'importo del versamento: ");
                scanf("%f", &importo);
                effettuaVersamento(importo);
                break;
            case 2:
                printf("Inserisci l'importo del prelevamento: ");
                scanf("%f", &importo);
                effettuaPrelevamento(importo);
                break;
            case 3:
                printf("Inserisci l'importo dell'assegno: ");
                scanf("%f", &importo);
                emettiAssegno(importo);
                break;
            case 0:
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
                break;
        }
    } while (scelta != 0);

    mostraDatiConto();

    return 0;
}
