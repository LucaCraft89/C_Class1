#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int name1[200], name2[200], name3[200], ages[2];

int agein(){
    int age;
    printf("Inserire età: ");
    scanf("%d", &age);
    return age;
}

void namein(int i){
    switch (i)
    {
    case 0:
        printf("Inserire nome: ");
        scanf("%s", &name1);
        break;

    case 1:
        printf("Inserire nome: ");
        scanf("%s", &name2);
        break;

    case 2:
        printf("Inserire nome: ");
        scanf("%s", &name3);
        break;    
    default:
        break;
    }
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
    if (((name1[0] - 'a' + 1) - 'a' + 1)>((name2[0] - 'a' + 1) - 'a' + 1) && ((name1[0] - 'a' + 1) - 'a' + 1)>((name3[0] - 'a' + 1) - 'a' + 1))
    {
        printf("Nome: %s, Età: %d \n", name1, ages[0]);
        ages[0]=0;
    }
    else if ((name2[0] - 'a' + 1)>(name3[0] - 'a' + 1) && (name2[0] - 'a' + 1)>(name1[0] - 'a' + 1))
    {
        printf("Nome: %s, Età: %d \n", name2, ages[0]);
        ages[1]=0;
    }
    else if ((name3[0] - 'a' + 1)>(name1[0] - 'a' + 1) && (name3[0] - 'a' + 1)>(name2[0] - 'a' + 1))
    {
        printf("Nome: %s, Età: %d \n", name3, ages[1]);
        ages[2]=0;
    }

    if ((name1[0] - 'a' + 1)>(name2[0] - 'a' + 1) && (name1[0] - 'a' + 1)>(name3[0] - 'a' + 1) && ages[0]!=0)
    {
        printf("Nome: %s, Età: %d \n", name1, ages[0]);
        ages[0]=0;
    }
    else if ((name2[0] - 'a' + 1)>(name3[0] - 'a' + 1) && (name2[0] - 'a' + 1)>(name1[0] - 'a' + 1) && ages[1]!=0)
    {
        printf("Nome: %s, Età: %d \n", name2, ages[0]);
        ages[1]=0;
    }
    else if ((name3[0] - 'a' + 1)>(name1[0] - 'a' + 1) && (name3[0] - 'a' + 1)>(name2[0] - 'a' + 1) && ages[2]!=0)
    {
        printf("Nome: %s, Età: %d \n", name3, ages[1]);
        ages[2]=0;
    }

    if ((name1[0] - 'a' + 1)>(name2[0] - 'a' + 1) && (name1[0] - 'a' + 1)>(name3[0] - 'a' + 1) && ages[0]!=0)
    {
        printf("Nome: %s, Età: %d \n", name1, ages[0]);
        ages[0]=0;
    }
    else if ((name2[0] - 'a' + 1)>(name3[0] - 'a' + 1) && (name2[0] - 'a' + 1)>(name1[0] - 'a' + 1) && ages[1]!=0)
    {
        printf("Nome: %s, Età: %d \n", name2, ages[1]);
        ages[1]=0;
    }
    else if ((name3[0] - 'a' + 1)>(name1[0] - 'a' + 1) && (name3[0] - 'a' + 1)>(name2[0] - 'a' + 1) && ages[2]!=0)
    {
        printf("Nome: %s, Età: %d \n", name3, ages[2]);
        ages[2]=0;
    }
}

void numorder(){
    if (ages[0]>ages[1] && ages[0]>ages[2])
    {
        printf("Nome: %s, Età: %d \n", name1, ages[0]);
        ages[0]=0;
    }
    else if (ages[1]>ages[0] && ages[1]>ages[2])
    {
        printf("Nome: %s, Età: %d \n", name2, ages[1]);
        ages[1]=0;
    }
    else if (ages[2]>ages[0] && ages[2]>ages[1])
    {
        printf("Nome: %s, Età: %d \n", name3, ages[2]);
        ages[2]=0;
    }

    if (ages[0]>ages[1] && ages[0]>ages[2] && ages[0]!=0)
    {
        printf("Nome: %s, Età: %d \n", name1, ages[0]);
            ages[0]=0;
    }
    else if (ages[1]>ages[0] && ages[1]>ages[2] && ages[1]!=0)
    {
            printf("Nome: %s, Età: %d \n", name2, ages[1]);
            ages[1]=0;
    }
    else if (ages[2]>ages[0] && ages[2]>ages[1] && ages[2]!=0)
    {
            printf("Nome: %s, Età: %d \n", name3, ages[2]);
            ages[2]=0;
    }

    if (ages[0]>ages[1] && ages[0]>ages[2] && ages[0]!=0)
    {
        printf("Nome: %s, Età: %d \n", name1, ages[0]);
            ages[0]=0;
    }
    else if (ages[1]>ages[0] && ages[1]>ages[2] && ages[1]!=0)
    {
            printf("Nome: %s, Età: %d \n", name2, ages[1]);
            ages[1]=0;
    }
    else if (ages[2]>ages[0] && ages[2]>ages[1] && ages[2]!=0)
    {
            printf("Nome: %s, Età: %d \n", name3, ages[2]);
            ages[2]=0;
    }
}
int main()
{
    int i;
    for (i = 0; i < 3; i++)
    {
        ages[i]=agein();
        namein(i);
    }
    menu();
    return 0;
}