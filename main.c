#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ingresar(char[][25], int[]);
int buscanombre(char[][25], char[25],int);
void ordenar(char[][25], int);
void mostrar(char[][25], int);

int main()
{
    char nombres[50][25],nom[25];
    int dni[50]={0},ingreso,pos,cant;
    cant=ingresar(nombres,dni);

    printf("Ingrese nombre que desea buscar(Termina Digitando NOBUSCARMAS): ");
    gets(nom);
    fflush(stdin);

    while(strcmpi(nom,"NOBUSCARMAS")!=0)
    {
        pos=buscanombre(nombres,nom,cant);
        if(pos!=-1)
        {
            printf("El DNI es :%d\n",dni[pos]);
        }
        else
        {
            printf("No coincide con ningun nombre\n");
        }
    printf("Ingrese nombre que desea buscar(Termina Digitando NOBUSCARMAS): ");
    gets(nom);
    fflush(stdin);
    }
    ordenar(nombres,cant);
    mostrar(nombres,cant);


    return 0;
};
int ingresar(char n[50][25],int d[50])
{
    int x=0;
    printf("Ingrese nombre(Termina Digitando FIN): ");
    gets(n[x]);
    fflush(stdin);
    while(strcmpi(n[x],"FIN")!=0)
    {
        printf("Ingrese DNI: ");
        scanf("%d",&d[x]);
        fflush(stdin);

        x++;

        printf("Ingrese nombre(Termina Digitando FIN): ");
        gets(n[x]);
        fflush(stdin);
    }

    return x;
};
int buscanombre(char nom[][25], char n[25],int can)
{
    int x=0,p=-1;

    while(p==-1&&x<can)
    {
        if(strcmpi(nom[x],n)==0)
        {
            p=x;
        }
        else
        {
            x++;
        }
    }
    return p;
};
void ordenar(char nom[][25],int n)
{
    int sen,x;
    char aux[25];
    sen=0;
    while(sen==0)
    {
        sen=1;
        for(x=0;x<n;x++)
        {
            if(strcmpi(nom[x],nom[x+1])>0)
            {
                strcpy(aux,nom[x]);
                strcpy(nom[x],nom[x+1]);
                strcpy(nom[x+1],aux);
                sen=0;
            }
        }
    }
};
void mostrar(char nom[][25],int n)
{
    int x;

    for(x=0;x<=n;x++)
    {
        printf("%s\n",nom[x]);
    }
};
