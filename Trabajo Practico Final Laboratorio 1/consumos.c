#include <stdio.h>
#include <stdlib.h>

#include "archi.h"
#include "clientes.h"
#include "consumos.h"




CON loadOneCon (CON con, CLI cli)
{
    con.idCliente = cli.id;

    printf(">>>Ingrese el dia: ");
    scanf("%d", &con.day);
    system("cls");

    while (con.day > 30 || con.day < 1)
        {

        printf(">>>[ERROR]<<< Cargue el dia desde 1 a 30: ");
        scanf("%d", &con.day);
        system("cls");
        }

    printf(">>>Ingrese el mes: ");
    scanf("%d", &con.month);
    system("cls");
    while (con.month > 12 || con.month < 1)
        {
        printf(">>>[ERROR]<<< Cargue el mes de 1 a 12: ");
        scanf("%d", &con.month);
        system("cls");
        }

    printf(">>>Ingrese el anio: ");
    scanf("%d", &con.year);
    system("cls");

    printf(">>>Ingrese el consumo del cliente (Mega bytes): ");
    scanf("%d", &con.megaBytes);

    return con;
}


void printOneCon (CON con)
{
    printf("\n                 Fecha: %02d/%02d/%d", con.day, con.month, con.year);
    printf("\n           Consumo(MB): %d", con.megaBytes);
}
