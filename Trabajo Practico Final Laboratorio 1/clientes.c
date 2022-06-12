#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "Menu.h"
#include <string.h>


#include "clientes.h"


#define DIM 100





CLI loadOneClient (CLI c)
{
    system("cls");
    printf(">>>Ingrese el apellido....: ");
    fflush(stdin);
    gets(c.apellido);
    system("cls");

    printf(">>>Ingrese el nombre......: ");
    fflush(stdin);
    gets(c.name);
    system("cls");

    printf(">>>Ingrese el genero(M o F): ");
    fflush(stdin);
    scanf("%c", &c.sexo);
    system("cls");
    while (c.sexo != 'm' || c.sexo != 'M' || c.sexo != 'f' || c.sexo != 'F')
        {

        printf(">>>[ERROR]<<< Genero inexistente, ingrese solo F o M: ");
        fflush(stdin);
        scanf("%c", &c.sexo);
        system("cls");
        }

    printf(">>>Ingrese el celular.....: ");
    fflush(stdin);
    gets(c.celular);
    system("cls");

    printf(">>>Ingrese el eMail.......: ");
    fflush(stdin);
    gets(c.email);

    return c;
}


void printOneClient (CLI c)
{
    printf("\n                    Id: %d", c.id);
    printf("\n     Apellido y nombre: %s %s", c.apellido, c.name);
    printf("\n                D.N.I.: %s", c.dni);
if (c.sexo == 'm' || c.sexo == 'M')
    {
    printf("\n                Genero: Masculino");
    }
else
    {
    printf("\n                Genero: Femenino");
    }
    printf("\n               Celular: %s", c.celular);
    printf("\n                 eMail: %s", c.email);
if (!c.baja)
    {
    printf("\n                Estado: ALTA");
    }
else
    {
    printf("\n                Estado: BAJA");
    }
}


int loadClients (CLI c[],int dim, int v)
{
    int i = v;

    char opcion = 0;

    while (i<dim && opcion != 27)
        {
        system("cls");
        c[i] = loadOneClient(c[i]);
        i++;
        printf("\n\nPresione cualquier tecla para ingresar otro cliente o [ESC] para salir ...");
        opcion = getch();
        }

    return i;
}



void printClients (CLI c[], int v)
{
    for (int i=0;i<v;i++)
        {
        printf("\n======================================================");
        printOneClient(c[i]);
        }
}





void intercambioCLI (CLI *a, CLI *b)
{
    CLI aux = *a;
    *a = *b;
    *b = aux;
}



int searchPosMinorDni (CLI c[], int v, int pos)
{
    int posMenor = pos;
    pos++;

    while (pos < v)
        {
        if (c[pos].dni < c[posMenor].dni)
            {
            posMenor = pos;
            }
        pos++;
        }

    return posMenor;
}





void sortSelectDni (CLI c[], int v)
{
    int i;
    int j;


    for (i=0;i<v;i++)
        {
        for (j=i+1;j<v;j++)
            {
            if(c[j].dni < c[i].dni)
                {
                intercambioCLI(&c[i], &c[j]);
                }
            }
        }
}




