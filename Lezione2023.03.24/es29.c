#include <stdio.h>
#include <float.h>

int main() {
    int N;
    printf("Inserisci il numero di valori: ");
    scanf("%d", &N);
    
    double valore, somma = 0.0, minimo = DBL_MAX, massimo = -DBL_MAX;
    // DBL_MAX e -DBL_MAX sono costanti definite in float.h
    
    for (int i = 0; i < N; i++) {
        printf("Inserisci il valore %d: ", i+1);
        scanf("%lf", &valore);
        somma += valore;
        if (valore > massimo) {
            massimo = valore;
        }
        if (valore < minimo) {
            minimo = valore;
        }
    }
    
    double media = somma / N;
    printf("Media: %.2f\n", media);
    printf("Massimo: %.2f\n", massimo);
    printf("Minimo: %.2f\n", minimo);
    
    return 0;
}
