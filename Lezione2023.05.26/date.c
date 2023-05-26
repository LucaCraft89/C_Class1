#include <stdio.h>
#include <stdlib.h>

typedef struct mesi
{
    int posizione;
    int giorni;
};
struct mesi gen = {1, 31}; 
struct mesi feb = {2, 28}; 
struct mesi mar = {3, 31};
struct mesi apr = {4, 30};
struct mesi mag = {5, 31};
struct mesi giu = {6, 30};
struct mesi lug = {7, 31};
struct mesi agu = {8, 31};
struct mesi set = {9, 30};
struct mesi ott = {10, 31};
struct mesi nov = {11, 30};
struct mesi dic = {12, 31};

typedef struct data
{
    int anno;
    int mese;
    int giorno;
};
struct data d1;
struct data d2;
struct data differenza;


void febbraiospeciale(int t){
    if (t==1)
    {
        feb.giorni = 29; 
    }
}

int controllogiorni(int mese, int giorni){
    if (giorni>getmese(mese))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void datiin(){
    do
    {
        printf("Inserire prima data (premere invio dopo ogni campo (in sequenza anno, mese, giorno))\nAnno\n-:");
        scanf("%d", &d1.anno);
        printf("Mese\n-:");
        scanf("%d", &d1.mese);
        printf("Giorno\n-:");
        scanf("%d", &d1.giorno);
        if (controllogiorni(d1.mese, d1.giorno)==1)
        {
            printf("il mese %d ha solo %d giorni non %d\n", d1.mese, getmese(d1.mese), d1.giorno);
        }
        if (d1.mese<1)
        {
            printf("Il mese non può essere minore di 1\n");
        }
        if (d1.mese>12)
        {
            printf("Il mese non può essere maggiore di 12\n");
        }
        if (d1.giorno<1)
        {
            printf("Il giorno non può essere minore di 1\n");
        }
    } while (controllogiorni(d1.mese, d1.giorno)==1 || d1.mese<1 || d1.mese>12 || d1.giorno<1);
    do
    {
        printf("Inserire seconda data (premere invio dopo ogni campo (in sequenza anno, mese, giorno))\nAnno\n-:");
        scanf("%d", &d2.anno);
        printf("Mese\n-:");
        scanf("%d", &d2.mese);
        printf("Giorno\n-:");
        scanf("%d", &d2.giorno);
        if (controllogiorni(d2.mese, d2.giorno)==1)
        {
            printf("il mese %d ha solo %d giorni non %d\n", d2.mese, getmese(d2.mese), d2.giorno);
        }
        if (d2.mese<1)
        {
            printf("Il mese non può essere minore di 1\n");
        }
        if (d2.mese>12)
        {
            printf("Il mese non può essere maggiore di 12\n");
        }
        if (d2.giorno<1)
        {
            printf("Il giorno non può essere minore di 1\n");
        }
    } while (controllogiorni(d2.mese, d2.giorno)==1 || d2.mese<1 || d2.mese>12 || d2.giorno<1);
    
    
}

void datadiff(){
    int annod=d2.anno-d1.anno , mesed=d2.mese-d1.mese, giornod=d2.giorno-d1.giorno;
    if (giornod<0)
    {
        giornod=giornod*-1;
    }
    if (mesed<0)
    {
        mesed=mesed*-1;
    }
    if (annod<0)
    {
        annod=annod*-1;
    }
    differenza.anno = annod;
    differenza.mese = mesed;
    differenza.giorno = giornod;
    pdiff();
}

int getmese(int posmese){
    if (gen.posizione==posmese)
    {
        return gen.giorni;
    }
    else if (feb.posizione==posmese)
    {
        return feb.giorni;
    }
    else if (mar.posizione==posmese)
    {
        return mar.giorni;
    }
    else if (apr.posizione==posmese)
    {
        return apr.giorni;
    }
    else if (mag.posizione==posmese)
    {
        return mag.giorni;
    }
    else if (giu.posizione==posmese)
    {
        return giu.giorni;
    }
    else if (lug.posizione==posmese)
    {
        return lug.giorni;
    }
    else if (agu.posizione==posmese)
    {
        return agu.giorni;
    }
    else if (set.posizione==posmese)
    {
        return set.giorni;
    }
    else if (ott.posizione==posmese)
    {
        return ott.giorni;
    }
    else if (nov.posizione==posmese)
    {
        return nov.giorni;
    }
    else if (dic.posizione==posmese)
    {
        return dic.giorni;
    }
}

void pdiff(){
    printf("Sono passati %d anno(i), %d mese(i), %d giorno(i)\n", differenza.anno, differenza.mese, differenza.giorno);
}

int main()
{
    int febb;
    printf("In questo anno Febbraio è bisestile? (1=yes, 0=no) \n-: ");
    scanf("%d", &febb);
    febbraiospeciale(febb);
    datiin();
    datadiff();
    return 0;
}