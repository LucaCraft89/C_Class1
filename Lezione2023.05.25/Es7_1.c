#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct persons 
{
    char name[200];
    int age;
};

struct persons p1, p2, p3;

void input(){
    printf("Inserire il nome: "); scanf("%s", &p1.name);
    printf("Inserire l'età: "); scanf("%d", &p1.age);
    printf("Inserire il nome: "); scanf("%s", &p2.name);
    printf("Inserire l'età: "); scanf("%d", &p2.age);
    printf("Inserire il nome: "); scanf("%s", &p3.name);
    printf("Inserire l'età: "); scanf("%d", &p3.age);
}

void menu(){
    int sel=0;
    while (sel!=1 && sel!=2)
    {
        printf("Selezionare cosa si vuole visualizzare:\n   1: Ordine Alfabetico\t2: Ordine Numerico\n~: ");
        scanf("%d", &sel);
        if (sel!=1 && sel!=2)
        {
            printf("Selezione non valida\n");
        }       
    }
    switch (sel)
    {
    case 1:
        alfaorder();
        break;
        
    case 2:
        numorder();
        break;
    
    default:
        printf("\n\nHow Tho?\n\n");
        break;
    }
}

void alfaorder(){
    sort(persons, persons = 3, CompareByName);
}

void numorder(){
    if (p1.age>p2.age && p1.age>p3.age)
    {
        printf("Nome: %s, Età: %d \n", p1.name, p1.age);
        p1.age=0;
    }
    else if (p2.age>p1.age && p2.age>p3.age)
    {
        printf("Nome: %s, Età: %d \n", p2.name, p2.age);
        p2.age=0;
    }
    else if (p3.age>p1.age && p3.age>p2.age)
    {
        printf("Nome: %s, Età: %d \n", p3.name, p3.age);
        p3.age=0;
    }

    if (p1.age>p2.age && p1.age>p3.age && p1.age!=0)
    {
        printf("Nome: %s, Età: %d \n", p1.name, p1.age);
            p1.age=0;
    }
    else if (p2.age>p1.age && p2.age>p3.age && p2.age!=0)
    {
            printf("Nome: %s, Età: %d \n", p2.name, p2.age);
            p2.age=0;
    }
    else if (p3.age>p1.age && p3.age>p2.age && p3.age!=0)
    {
            printf("Nome: %s, Età: %d \n", p3.name, p3.age);
            p3.age=0;
    }

    if (p1.age>p2.age && p1.age>p3.age && p1.age!=0)
    {
        printf("Nome: %s, Età: %d \n", p1.name, p1.age);
            p1.age=0;
    }
    else if (p2.age>p1.age && p2.age>p3.age && p2.age!=0)
    {
            printf("Nome: %s, Età: %d \n", p2.name, p2.age);
            p2.age=0;
    }
    else if (p3.age>p1.age && p3.age>p2.age && p3.age!=0)
    {
            printf("Nome: %s, Età: %d \n", p3.name, p3.age);
            p3.age=0;
    }
}

int main()
{
    int i;
    input();
    menu();
    return 0;
}