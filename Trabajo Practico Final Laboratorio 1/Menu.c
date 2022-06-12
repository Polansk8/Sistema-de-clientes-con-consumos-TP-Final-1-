#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "Menu.h"
#include "clientes.h"
#include "archi.h"

#define AR_CLIENTES "clientes.dat"
#define AR_CLI_DNI "clientes ordenados por dni.dat"

#define AR_CONSUMPTIONS "consumpions.dat"

#define DIM 50

#define CANT_CLIENTS 1000



void recuadro(char cabecera[])
{
    int i;
    printf("%c", 201);
    for (i=0;i<50;i++)
        {
        printf("%c", 205);
        }

    printf("%c\n", 187);
    printf("%c%32s%19c\n", 186, cabecera,186);
    printf("%c", 200);

    for (i=0;i<50;i++)
        {
        printf( "%c", 205);
        }
    printf("%c",188);
}



///Menu principal
void mainMenu()
{
    char opcion = 0;

    while (opcion != 27)
        {
        system("cls");
        recuadro("\tMENU PRINCIPAL");
        printf("\n\t>>>1) Apartado de clientes");
        printf("\n\t>>>2) Apartado de consumos");
        printf("\n\n\t>>>ESC) Salir...");

        opcion = getch();
        system("cls");

        switch (opcion)
            {
            case '1':
                clientMenu();
                break;
            case '2':
                consumMenu();
                break;
            case 27:
                opcion = 27;
                break;
            default:
                printf(">>>ERROR<<< Ingreso una opcion no valida");
                getch();
                break;
            }
        }

    system("cls");
    recuadro("Gracias por usar nuestro programa :D");

    printf("\n\nMiembros del TP final Laboratorio 1");
    printf("\n===========================================");
    printf("\n----------->>>Blanco Mariano<<<------------");
    printf("\n---------->>>Tambascia Jessica<<<----------");
    printf("\n---------->>>Lochocki Gonzalo<<<-----------");
    printf("\n----------->>>Aguera Gonzalo<<<------------");
    printf("\n===========================================");

    getch();

}


///Menu de clientes
void clientMenu ()
{
    char opcion = 0;

    while (opcion != 27)
        {
        system("cls");
        recuadro("\tAPARTADO DE CLIENTES");
        printf("\n\t>>>1) Ingresar un nuevo cliente");
        printf("\n\t>>>2) Mostrar lista de clientes");
        printf("\n\t>>>3) Buscar clientes");
        printf("\n\t>>>4) Dar de alta o baja un cliente");
        printf("\n\t>>>5) Modificar un cliente");
        printf("\n\n\t>>>ESC) Volver al menu anterior");

        opcion = getch();
        system("cls");
        switch (opcion)
            {
            case '1':
                loadArchivoClient(AR_CLIENTES);
                break;
            case '2':
                printClientsMenu();
                break;
            case '3':
                searchClientMenu();
                break;
            case '4':
                regDeregMenu();
                break;
            case '5':
                customClient(AR_CLIENTES);
                break;
            case 27:
                mainMenu();
                break;
            default:
                printf("\n\n----->>>ERORR<<< Ingreso una opcion no valida------");
                getch();
                break;
            }
        }
}


///Menu para dar de alta o baja un cliente
void regDeregMenu ()
{
    char opcion = 0;

    while (opcion != 27)
        {
        system("cls");
        recuadro("\tBAJA O ALTA MENU");
        printf("\n\t>>>1) Alta de un cliente");
        printf("\n\t>>>2) Baja de un cliente");
        printf("\n\n\t>>>ESC) Volver al menu anterior");

        opcion = getch();
        system("cls");

        switch (opcion)
            {
            case '1':
                regClients(AR_CLIENTES);
                break;
            case '2':
                deregClient(AR_CLIENTES);
                break;
            case 27:
                clientMenu();
                break;
            default:
                printf(">>>[ERROR]<<< Ingreso una opcion no valida---");
                getch();
                break;
            }
        }
}



///Menu de mostrar clientes
void printClientsMenu ()
{
    char opcion = 0;

    while (opcion != 27)
        {
        system("cls");
        recuadro("\tMOSTRAR CLIENTES");
        printf("\n\t>>>1) Todos los clientes");
        printf("\n\t>>>2) Clientes dados de alta");
        printf("\n\t>>>3) Clientes dados de baja");
        printf("\n\n\t>>>ESC) Volver al menu anterior");

        opcion = getch();
        system("cls");

        switch(opcion)
            {
            case '1':
                recuadro("CLIENTES ORDENADOS POR ID");
                printArchivo(AR_CLIENTES);
                break;
            case '2':
                recuadro("CLIENTES DADOS DE ALTA");
                printRegClients(AR_CLIENTES);
                break;
            case '3':
                recuadro("CLIENTES DADOS DE BAJA");
                printDeregClients(AR_CLIENTES);
                break;
            case 27:
                clientMenu();
                break;
            default:
                recuadro(">>>ERROR<<< Ingreso una opcion no valida");
                getch();
                break;
            }
        }
}


///Menu de busqueda de clientes
void searchClientMenu ()
{
    char opcion = 0;

    while (opcion != 27)
        {
        system("cls");
        recuadro("\tBUSCAR CLIENTES");
        printf("\n\t>>>1) Buscar cliente por DNI");
        printf("\n\t>>>2) Buscar cliente por ID");
        printf("\n\t>>>3) Buscar cliente por nombre");
        printf("\n\t>>>4) Buscar cliente por apellido");
        printf("\n\t>>>5) Buscar cliente por celular");
        printf("\n\n\t>>>ESC) Volver al menu anterior");


        opcion = getch();
        system("cls");

        switch (opcion)
            {
            case '1':
                searchXDni(AR_CLIENTES);
                break;
            case '2':
                searchXId(AR_CLIENTES);
                break;
            case '3':
                searchXName(AR_CLIENTES);
                break;
            case '4':
                searchXSurname(AR_CLIENTES);
                break;
            case '5':
                searchXMobile(AR_CLIENTES);
                break;
            case 27:
                clientMenu();
                break;
            default:
                recuadro(">>>ERROR<<< Ingreso una opcion no valida");
                getch();
                break;
            }
        }
}







///Menu de consumos de clientes
void consumMenu ()
{
    char opcion = 0;



    while (opcion != 27)
        {
        system("cls");
        recuadro("\tAPARTADO DE CONSUMOS");
        printf("\n\t>>>1) Cargar un consumo de un cliente");
        printf("\n\t>>>2) Mostrar los consumos de un cliente");
        printf("\n\t>>>3) Modificar los consumos de un cliente");
        printf("\n\n\t>>>ESC) Volver al menu anterior");

        opcion = getch();
        system("cls");

        switch (opcion)
            {
            case '1':
                loadConsumption(AR_CONSUMPTIONS, AR_CLIENTES);
                break;
            case '2':
                printConClients(AR_CONSUMPTIONS, AR_CLIENTES);
                break;
            case '3':
                break;
            default:
                printf(">>>[ERROR]<<< Ingreso una opcion invalida---");
                getch();
                break;
            case 27:
                mainMenu();
                break;
            }
        }
}

