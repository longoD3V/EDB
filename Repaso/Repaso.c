#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Asiento
typedef struct
    {
    int fila;
    char columna;
    int ocupado; // 0 = libre, 1 = ocupado
    char pasajero[50];
    } Asiento;

// Definición de la matriz de asientos
#define FILAS 25
#define COLUMNAS 4
Asiento avion[FILAS][COLUMNAS];

// Prototipos de funciones
void inicializarAsientos(Asiento avion[][COLUMNAS]);
int menu(void);
void reservarAsiento(Asiento avion[][COLUMNAS]);
void cancelarReserva(Asiento avion[][COLUMNAS]);
void mostrarEstado(Asiento avion[][COLUMNAS]);
void consultarReservas(Asiento avion[][COLUMNAS]);

int main()
{
int op;
inicializarAsientos(avion);

    do
    {
        op = menu();
        system("cls");
        switch (op)
        {
            case 1: mostrarEstado(avion);
            break;
            /*case 2: reservarAsiento(avion);
            break;
            case 3: cancelarReserva(avion);
            break;
            case 4: consultarReservas(avion);
            break;*/
        }
    } while (op < 5);

return 0;
}

void inicializarAsientos(Asiento avion[][COLUMNAS])
{
    for (int i = 0; i < FILAS; i++)
        {
        for (int j = 0; j < COLUMNAS; j++)
            {
            avion[i][j].fila = i + 1;
            avion[i][j].columna = 'A' + j;
            avion[i][j].ocupado = 0;
            strcpy(avion[i][j].pasajero, "");
            }
        }
}

void mostrarEstado(Asiento avion[FILAS][COLUMNAS])
{
    printf("Estado actual de los asientos\n");
    printf(" A B C D\n ");
    for(int i=0; i<FILAS; i++)
        {
        printf("%2d",i+1);
        for (int j = 0; j < COLUMNAS; j++)
            {
                printf("%c",avion[i][j].ocupado? 'X' : 'O');
            }
        printf("\n");
        }
}

/*void reservarAsiento(Asiento avion[][COLUMNAS])
{
    printf("Ingrese la fila: ");
    scanf("%d", avion.fila);
    printf("Ingrese la columna: ");
    scanf("%c", avion.columna);

    for (int i = 0; i < FILAS; i++)
        {
        for (int j = 0; j < COLUMNAS; j++)
            {
            avion[i][j].fila = i + 1;
            avion[i][j].columna = 'A' + j;
            avion[i][j].ocupado = 0;
            strcpy(avion[i][j].pasajero, "");
            }
        }
}*/

int menu(void)
{
    int op;
    do
        {
        system("cls");
        printf("\n\t\t\t MENU DE RESERVAS DE LA AEROLINEA \n");
        printf("\n 1. Mostrar asientos ocupados y libres\n");
        printf(" 2. Reservar un asiento\n");
        printf(" 3. Cancelar una reserva\n");
        printf(" 4. Consultar reservas por pasajero\n");
        printf(" 5. Salir\n");
        printf(" Ingrese una opcion [1-5]: ");
        scanf("%d", &op);
        } while (op < 1 || op > 5);
return op;
}
