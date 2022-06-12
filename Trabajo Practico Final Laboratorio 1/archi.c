#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

#include "archi.h"
#include "clientes.h"
#include "Menu.h"
#include "consumos.h"

#define AR_CLIENTES "clientes.dat"
#define AR_CLI_DNI "clientes ordenados por dni.dat"




/** \brief Carga un cliente en un archivo.
 *
 * \param Nombre del archivo
 * \return No return
 *
 */
void loadArchivoClient (char archivo[])
{
    FILE *client = fopen(archivo, "a+b");
    CLI c;
    CLI d;

    int flag = 0;
    int id;
    char opcion = 0;
    char agregar;

    if (client)
        {
        ///Retorna el ultimo id cargado para autoincrementarlo
        id = searchEndId(archivo);
        while (opcion != 27)
            {
            system("cls");
            flag = 0;
            recuadro("Cargando cliente");
            printf("\n>>>Ingrese el D.N.I.......: ");
            fflush(stdin);
            gets(c.dni);

            fseek(client, 0, SEEK_SET);

            ///Verifica en el archivo que no se encuentre el dni que acabo de ingresar
            while (!flag && fread(&d, sizeof(CLI), 1, client) > 0)
                {
                if (strcmp(d.dni, c.dni) == 0)
                    {
                    flag = 1;
                    }
                }

            ///Si el DNI no se encuentra prosigo con la carga del cliente
            if (flag == 0)
                {
                id++;
                c.id = id;
                c.baja = 0;
                c = loadOneClient(c);

                system("cls");
                recuadro("Desea ingresar este cliente? S/N");
                printOneClient(c);
                fflush(stdin);
                agregar = getch();
                system("cls");
                if(agregar == 's' || agregar == 'S')
                    {
                    fwrite(&c, sizeof(CLI), 1, client);
                    recuadro("Se agrego el nuevo cliente");
                    }
                else
                    {
                    recuadro("No se agrego el cliente");
                    }
                }
            else
                {
                ///Muestro que el cliente ya existe en caso de que se encuentre cargado
                system("cls");
                recuadro(">>>ERROR<<< El cliente ya fue ingresado");
                fseek(client, -1*sizeof(CLI), SEEK_CUR);
                fread(&c, sizeof(CLI), 1, client);
                printOneClient(c);
                }
            printf("\n\nPresione [ESC] para salir o cualquier tecla para ingresar otro cliente---");
            opcion = getch();
            }
        }
    else
        {
        printf(">>>ERROR<<< Ocurrio un fallo al intentar abrir el archivo---");
        }

    fclose(client);

    clientMenu();
}




void printArchivo (char archivo[])
{
    FILE *cliente = fopen (archivo, "rb");
    CLI c;

    if (cliente)
        {
        while (fread(&c, sizeof(CLI), 1, cliente) > 0)
            {
            printf("\n=============================================");
            printOneClient(c);
            }
        }
    else
        {
        printf("\n>>>ERROR<<< Ocurrio un fallo al mostrar los empleados---");
        }

    fclose(cliente);

    getch();
}



void searchXDni (char archivo[])
{
    FILE *cliente = fopen(archivo, "rb");
    CLI c;

    int flag = 0;
    char dni[50];

    if (cliente)
        {
        recuadro("BUSCANDO CLIENTE POR D.N.I.");
        printf("\n>>>Ingrese el dni a buscar: ");
        fflush(stdin);
        gets(dni);
        system("cls");

        while (!flag && fread(&c,sizeof(CLI),1,cliente) > 0)
            {
            if (strcmp(c.dni, dni) == 0)
                {
                flag = 1;
                }
            }
        }
    else
        {
        printf(">>>ERROR<<< Ocurrio un fallo al abrir el archivo---");
        }

    if (flag)
        {
        recuadro("CLIENTE ENCONTRADO");
        printOneClient(c);
        }
    else
        {
        printf(">>>ERROR<<< No existe un cliente con el D.N.I. [%s]---", dni);
        }

    fclose(cliente);

    getch();
}


void searchXId (char archivo[])
{
    FILE *clients = fopen(archivo, "rb");
    CLI c;

    int flag = 0;
    int id;

    if (clients)
        {
        recuadro("BUSCANDO CLIENTE POR ID");
        printf("\n>>>Ingrese el ID del cliente: ");
        scanf("%d", &id);
        system("cls");

        while (!flag && fread(&c, sizeof(CLI), 1, clients) > 0)
            {
            if (c.id == id)
                {
                flag = 1;
                }
            }
        }
    else
        {
        printf(">>>ERROR<<< Ocurrio un fallo al abrir el archivo---");
        }

    if (flag)
        {
        recuadro("CLIENTE ENCONTRADO");
        printOneClient(c);
        }
    else
        {
        printf(">>>ERROR<<< No existe un cliente con el ID [%d]---", id);
        }

    fclose(clients);

    getch();
}


void searchXName (char archivo[])
{
    FILE *clientes = fopen(archivo, "rb");

    CLI c;

    int flag = 0;
    char name[50];

    if (clientes)
        {
        recuadro("BUSCANDO CLIENTE POR NOMBRE");
        printf("\n>>>Ingrese el nombre del cliente: ");
        fflush(stdin);
        gets(name);
        system("cls");

        recuadro("CLIENTES CON ESE NOMBRE");
        while (fread(&c, sizeof(CLI), 1, clientes) > 0)
            {
            if (strcmpi(c.name, name) == 0)
                {
                flag = 1;
                printOneClient(c);
                }
            }
        if (!flag)
            {
            system("cls");
            printf(">>>ERROR<<< No se encuentra ningun cliente con el nombre [%s]---", name);
            }
        }
    else
        {
        printf("\n\n>>>ERROR<<< Ocurrio un fallo al buscar en el archivo---");
        }




    fclose(clientes);

    getch();
}


void searchXSurname (char archivo[])
{
    FILE *clients = fopen(archivo, "rb");
    CLI c;

    int flag = 0;
    char surname[50];

    if (clients)
        {
        recuadro("BUSCANDO CLIENTE POR APELLIDO");
        printf("\n>>>Ingrese el apellido del cliente: ");
        fflush(stdin);
        gets(surname);
        system("cls");

        recuadro("CLIENTES CON ESE APELLIDO");
        while (fread(&c, sizeof(CLI), 1, clients) > 0)
            {
            if (strcmpi(c.apellido, surname) == 0)
                {
                flag = 1;
                printf("\n======================================================");
                printOneClient(c);
                }
            }
        }
    else
        {
        printf(">>>ERROR<<< Ocurrio un fallo al abrir el archivo---");
        }

    if (!flag)
        {
        system("cls");
        printf("\n\n>>>ERROR<<< No existe ningun cliente con el apellido [%s]---", surname);
        }

    fclose(clients);

    getch();
}


///Busca un cliente por numero de celular
void searchXMobile (char archivo[])
{
    FILE *clients = fopen(archivo, "rb");
    CLI c;

    char numberPhone[50];
    int flag = 0;

    if (clients)
        {
        recuadro("BUSCANDO CLIENTE POR N° DE CELULAR");
        printf("\n>>>Ingrese el celular a buscar: ");
        fflush(stdin);
        gets(numberPhone);
        system("cls");

        while (!flag && fread(&c, sizeof(CLI), 1 ,clients))
            {
            if (strcmp(c.celular, numberPhone) == 0)
                {
                flag = 1;
                }
            }

        if (flag)
            {
            recuadro("CLIENTE ENCONTRADO");
            printOneClient(c);
            }
        else
            {
            printf(">>>[ERROR]<<< No existe un cliente con ese N° de celular---");
            }
        }
    else
        {
        printf(">>>[ERROR]<<< Ocurrio un fallo al abrir el archivo---");
        }

    fclose(clients);

    getch();
}





int searchEndId (char archivo [])
{
    FILE *client = fopen(archivo, "rb");

    int id = 0;

    CLI c;

    if (client)
        {
        fseek(client, -1*sizeof(CLI), SEEK_END);
        if(fread(&c, sizeof(CLI), 1, client) > 0)
            {
            id = c.id;
            }
        }
    else
        {
        recuadro(">>>ERROR<<< Ocurrio un fallo al abrir el archivo---");
        }

    return id;
}




int archi2Array (char archivo[], CLI c[], int dim)
{
    FILE *clients = fopen(archivo, "rb");

    int i = 0;

    if (clients)
        {
        while (i<dim && fread(&c[i], sizeof(CLI), 1, clients) > 0)
            {
            i++;
            }
        }
    else
        {
        recuadro(">>>ERROR<<< Ocurrio un fallo al abrir el archivo---");
        }

    fclose(clients);

    return i;
}





void sortXDni (CLI c[], int v)
{
    int i = 0;
    int j = 0;

    while (i<v-1)
        {
        while (j<v)
            {
            if (c[i].dni < c[j].dni)
                {
                intercambioCLI(&c[i], &c[j]);
                }
            j++;
            }
        j = i+1;
        i++;
        }
}






void array2Archi (char archivo[], CLI c[], int v)
{
    FILE *clients = fopen(archivo, "wb");

    int i = 0;


    if (clients)
        {
        while (i<v)
            {
            fwrite(&c[i], sizeof(CLI), 1, clients);
            i++;
            }
        }

    fclose(clients);
}


void deregClient (char archivo[])
{
    FILE *clients = fopen(archivo, "r+b");
    CLI c;
    int id;
    int flag = 0;
    char opcion = 0;

    if (clients)
        {
        printf("\n>>>Ingrese el ID del cliente para dar de baja: ");
        scanf("%d", &id);
        system("cls");

        while (c.id != id && fread(&c, sizeof(CLI), 1, clients) > 0)
            {
            if (c.id == id)
                {
                flag = 1;
                }
            }
        }
    else
        {
        printf(">>>[ERROR]<<< Ocurrio un fallo al abrir el archivo---");
        }


    if (!flag)
        {
        printf(">>>[ERROR]<<< No existe un cliente con ese ID---");
        }


    if (!c.baja)
        {
        if (flag)
            {
            recuadro("CLIENTE ENCONTRADO");
            printOneClient(c);

            printf("\n\n>>>Desea dar de baja este cliente? (S/N)");
            fflush(stdin);
            opcion = getch();
            system("cls");

            if (opcion == 's' || opcion == 'S')
                {
                c.baja = 1;
                recuadro("CLIENTE DADO DE BAJA");
                printOneClient(c);
                fseek(clients, -1*sizeof(CLI), SEEK_CUR);
                fwrite(&c, sizeof(CLI), 1, clients);
                }
            else
                {
                recuadro("CLIENTE SIN MODIFICACION");
                printOneClient(c);
                }
            }
        }
    else if (flag)
        {
        recuadro("CLIENTE YA DADO DE BAJA");
        printOneClient(c);
        }

    fclose(clients);

    getch();
}




void customClient (char archivo[])
{
    FILE *clients = fopen(archivo, "r+b");
    CLI c;
    int id;
    char opcion = 0;

    if (clients)
        {
        recuadro("MODIFICAR CLIENTE");
        printf("\n>>>Ingrese el ID del cliente a modificar: ");
        scanf("%d", &id);
        system("cls");

        fseek(clients, (id-1)*sizeof(CLI), SEEK_SET);
        fread(&c, sizeof(CLI), 1, clients);


        if (c.id == id)
            {
            recuadro("CLIENTE ENCONTRADO");
            printOneClient(c);
            printf("\n\n>>>Desea modificar los datos del cliente? (S/N)");
            opcion = getch();
            system("cls");

            if (opcion == 's' || opcion == 'S')
                {
                recuadro("MODIFICANDO CLIENTE");
                printf("\n");
                c = loadOneClient(c);
                system("cls");

                fseek(clients, -1*sizeof(CLI), SEEK_CUR);
                fwrite(&c, sizeof(CLI), 1, clients);

                recuadro("CLIENTE MODIFICADO");
                printOneClient(c);
                }
            else
                {
                recuadro("CLIENTE SIN MODIFICACION");
                printOneClient(c);
                }
            }
        else
            {
            printf(">>>[ERROR]<<< El cliente con ese ID no existe---");
            }
        }
    else
        {
        printf(">>>[ERROR]<<< Ocurrio un fallo al abrir el archivo---");
        }
    fclose(clients);

    getch();
}


void printDeregClients (char archivo[])
{
    FILE *clients = fopen(archivo, "rb");
    CLI c;
    int flag = 0;

    if (clients)
        {
        while (fread(&c, sizeof(CLI), 1, clients) > 0)
            {
            if (c.baja == 1)
                {
                flag = 1;
                printf("\n=============================================");
                printOneClient(c);
                }
            }
        if (!flag)
            {
            printf("\n>>>[ERROR]<<< No hay ningun cliente dado de baja---");
            }
        }
    else
        {
        printf(">>>[ERROR]<<< Ocurrio un fallo al abrir el archivo---");
        }



    fclose(clients);

    getch();
}



void regClients (char archivo[])
{
    FILE *clients = fopen(archivo, "r+b");
    CLI c;
    int flag = 0;
    int id;
    char opcion;

    if (clients)
        {
        printf(">>>Ingrese el id del cliente para dar de alta: ");
        scanf("%d", &id);
        system("cls");

        while (!flag && fread(&c, sizeof(CLI), 1, clients))
            {
            if (c.id == id)
                {
                flag = 1;
                }
            }

        if (!flag)
            {
            printf(">>>[ERROR]<<< No existe un cliente con ese ID---");
            }

        if (c.baja)
            {
            if (flag);
                recuadro("CLIENTE ENCONTRADO");
                printOneClient(c);

                printf("\n\n>>>Desea dar de alta el cliente? (S/N)");
                opcion = getch();
                system("cls");

                if (opcion == 's' || opcion == 'S')
                    {
                    c.baja = 0;

                    recuadro("CLIENTE DADO DE ALTA");
                    printOneClient(c);

                    fseek(clients, -1*sizeof(CLI), SEEK_CUR);
                    fwrite(&c, sizeof(CLI), 1, clients);
                    }
                else
                    {
                    recuadro("CLIENTE SIN MODIFICACION");
                    printOneClient(c);
                    }
            }
        else if (flag)
            {
            recuadro("CLIENTE YA DADO DE ALTA");
            printOneClient(c);
            }
        }
    else
        {
        printf(">>>[ERROR]<<< Ocurrio un fallo al abrir el archivo---");
        }




    fclose(clients);

    getch();

}



void printRegClients (char archivo[])
{
    FILE *clients = fopen(archivo, "rb");
    CLI c;

    int flag = 0;

    if (clients)
        {
        while (fread(&c, sizeof(CLI), 1, clients))
            {
            if (!c.baja)
                {
                flag = 1;
                printf("\n=============================================");
                printOneClient(c);
                }
            }
        if (!flag)
            {
            printf(">>>[ERROR]<<< No existe ningun cliente dado de alta---");
            }
        }
    else
        {
        printf(">>>[ERROR]<<< Ocurrio un fallo al abrir el archivo---");
        }

    fclose(clients);

    getch();
}




void loadConsumption (char arCon[], char arClient[])
{
    FILE *consumption = fopen(arCon, "a+b");
    FILE *clients = fopen(arClient, "rb");

    CLI cli;
    CLI cliAux;

    CON con;
    CON conAux;

    char opcion = 0;
    int flag;
    int flag2;

    if (consumption && clients)
        {
        while (opcion != 27)
            {
            system("cls");
            flag = 0;
            flag2 = 0;
            recuadro("CARGANDO CONSUMO");
            printf("\n>>>Ingrese el ID del cliente para agregar un consumo: ");
            scanf("%d", &cli.id);
            system("cls");

            while (!flag && fread(&cliAux, sizeof(CLI), 1, clients))
                {
                if (cli.id == cliAux.id)
                    {
                    flag = 1;
                    }
                }

            if (flag)
                {
                recuadro("CLIENTE ENCONTRADO");
                printOneClient(cliAux);

                printf("\n\n");
                con = loadOneCon(con, cli);
                system("cls");
                }
            else
                {
                printf(">>>ERROR<<< El cliente con ese ID no existe---");
                }
            while (!flag2 && fread(&conAux, sizeof(CON), 1, consumption) > 0)
                {
                if (conAux.day == con.day && conAux.month == con.month && conAux.year == con.year)
                    {
                    flag2 = 1;
                    }
                }

            if (flag && !flag2)
                {
                fseek(clients, -1*sizeof(CLI), SEEK_CUR);
                fread(&cli, sizeof(CLI), 1, clients);
                fwrite(&con, sizeof(CON), 1, consumption);

                recuadro("CONSUMO CARGADO");
                printOneClient(cli);
                printOneCon(con);


                }
            else if (flag && flag2)
                {
                con.megaBytes += conAux.megaBytes;
                fseek(clients, -1*sizeof(CLI), SEEK_CUR);
                fseek(consumption, -1*sizeof(CON), SEEK_CUR);
                fread(&cli, sizeof(CLI), 1, clients);
                fwrite(&con, sizeof(CON), 1, consumption);

                recuadro("CONSUMO AGREGADO A ESA FECHA");
                printOneClient(cli);
                printOneCon(con);
                }

            printf("\n\n");
            printf(">>>Presione [ESC] para salir o cualquier tecla para ingresar otro consumo---");
            opcion = getch();

            fseek(clients, 0, SEEK_SET);
            fseek(consumption, 0, SEEK_SET);
            }

        }
    else
        {
        printf(">>>[ERROR]<<< Ocurrio un fallo al abrir los archivos---");
        }

    fclose(clients);
    fclose(consumption);

    getch();
}




void printConClients (char arCon[], char arClient[])
{
    FILE *consumption = fopen(arCon, "rb");
    FILE *clients = fopen(arClient, "rb");

    CON con;
    CLI cli;

    int idClient;
    int flag = 0;
    int flag2 = 0;

    if (consumption && clients)
        {
        recuadro("BUSCAR CONSUMOS");
        printf("\n>>>Ingrese el ID del cliente para mostrar sus consumos: ");
        scanf("%d", &idClient);
        system("cls");

        while (!flag && fread(&cli, sizeof(CLI), 1, clients) > 0)
            {
            if (cli.id == idClient)
                {
                flag = 1;
                }
            }
        if (flag)
        {
        recuadro("CONSUMOS DEL CLIENTE");
        printOneClient(cli);
        while (fread(&con, sizeof(CON), 1, consumption) > 0)
            {
            if (con.idCliente == idClient)
                {
                flag2 = 1;
                printf("\n_______________________________________________");
                printOneCon(con);
                }
            }
        }
    else
        {
        printf(">>>[ERROR]<<< No existe ningun cliente con ese ID---");
        }

    if (!flag2 && flag)
        {
        printf("\n\n---El cliente no tiene ningun consumo---");
        }
        }
    else
        {
        printf(">>>[ERROR]<<< Ocurrio un fallo al abrir los archivos---");
        }




    fclose(consumption);

    getch();
}
