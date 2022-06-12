#ifndef CONSUMOS_H_INCLUDED
#define CONSUMOS_H_INCLUDED

typedef struct
{
    int idCliente;
    int day;
    int month;
    int year;
    int megaBytes;
}CON;


///Carga el consumo de un cliente
CON loadOneCon (CON con, CLI cli);
///Muestra los consumos de un cliente
void printOneCon (CON c);

#endif // CONSUMOS_H_INCLUDED
