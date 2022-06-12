#ifndef ARCHI_H_INCLUDED
#define ARCHI_H_INCLUDED
#include "clientes.h"


///Carga un archivo de clientes
void loadArchivoClient (char archivo[]);
///Muestra un archivo de clientes
void printArchivo (char archivo[]);
///Busca un cliente por DNI
void searchXDni (char archivo[]);
///Busca un cliente por ID
void searchXId (char archivo[]);
///Busca un cliente por nombre
void searchXName (char archivo[]);
///Busca un cliente por el apellido
void searchXSurname (char archivo[]);
///Busca un cliente por numero de celular
void searchXMobile (char archivo[]);
///Busca el ultimo ID
int searchEndId (char archivo []);
///Pasa los registros de un archivo de clientes a un array de clientes
int archi2Array (char archivo[], CLI c[], int dim);
///Ordena por DNI un arreglo de clientes
void sortClientsXDni(CLI c[], int v);
///Da de baja un cliente
void deregClient (char archivo[]);
///Muestra lo clientes dados de alta
void printRegClients(char archivo[]);
///Muestra los clientes dados de baja
void printDeregClients (char archivo[]);
///Da de alata un cliente
void regClients (char archivo[]);
///Modifica un cliente
void customClient (char archivo[]);




///Carga un archivo con los consumos de un cliente
void loadConsumption (char arCon[], char arClient[]);
///Muestra los consumos de un cliente determinado
void printConClients (char arCon[], char arClient[]);


#endif // ARCHI_H_INCLUDED
