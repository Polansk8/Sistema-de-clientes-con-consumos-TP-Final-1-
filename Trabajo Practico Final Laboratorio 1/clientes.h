#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
{
    int id;
    char apellido[50];
    char name[50];
    char dni[50];
    char sexo;
    char celular[50];
    char email[50];
    int baja;           ///1 si esta de baja, 0 si esta de alta
}CLI;




///Carga un cliente
CLI loadOneClient (CLI c);
///Muestra un cliente
void printOneClient (CLI c);
///Carga un array de clientes
int loadClients (CLI c[],int dim, int v);
///Muestra un array de clientes
void printClients (CLI c[], int v);
///Intercambia la posicion de un cliente con otro en un array
void intercambioCLI (CLI *a, CLI *b);
///Busca la posicion del DNI mas bajo en un array de clientes
int searchPosMinorDni (CLI a[], int v, int pos);
///Ordena un array de clientes por DNI
void sortSelectDni (CLI a[], int v);


#endif // CLIENTES_H_INCLUDED
