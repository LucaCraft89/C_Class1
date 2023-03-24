#include <stdio.h>

int main() {
   int n, i;
   long long fattoriale = 1;

   printf("Inserisci il numero di elementi: ");
   scanf("%d", &n);

   int numeri[n];
   printf("Inserisci %d numeri:\n", n);

   for(i = 0; i < n; i++) {
      scanf("%d", &numeri[i]);
   }

   for(i = 0; i < n; i++) {
      int j;
      fattoriale = 1;
      for(j = 1; j <= numeri[i]; j++) {
         fattoriale *= j;
      }
      printf("Il fattoriale di %d è: %lld\n", numeri[i], fattoriale);
   }
   
   return 0;
}
