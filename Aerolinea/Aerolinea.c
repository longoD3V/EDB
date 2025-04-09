#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILAS 25
#define COLUMNAS 4

// Definición de la estructura Asiento
typedef struct {
    int fila;
    char columna;
    int ocupado; // 0 = libre, 1 = ocupado
    char pasajero[50];
} Asiento;

// Matriz de asientos
Asiento avion[FILAS][COLUMNAS];

// Prototipos de funciones
void inicializarAsientos(Asiento avion[][COLUMNAS]);
void pausa(void);
int menu(void);
void reservarAsiento(Asiento avion[][COLUMNAS]);
void cancelarReserva(Asiento avion[][COLUMNAS]);
void mostrarEstado(Asiento avion[][COLUMNAS]);
void consultarReservas(Asiento avion[][COLUMNAS]);

int main() {
    int op;
    inicializarAsientos(avion);

    do {
        op = menu();
        system("cls");
        switch (op) {
            case 1:
                reservarAsiento(avion);
                break;
            case 2:
                cancelarReserva(avion);
                break;
            case 3:
                mostrarEstado(avion);
                break;
            case 4:
                consultarReservas(avion);
                break;
        }
    } while (op < 5);

    return 0;
}

// Inicializa todos los asientos como disponibles
void inicializarAsientos(Asiento avion[][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            avion[i][j].fila = i + 1;
            avion[i][j].columna = 'A' + j;
            avion[i][j].ocupado = 0;
            strcpy(avion[i][j].pasajero, "");
        }
    }
}

// Muestra el menú y devuelve la opción elegida
int menu(void) {
    int op;
    do {
        printf("\n\t\t\t MENU DE RESERVAS\n");
        printf("\n 1. Reservar un asiento\n");
        printf(" 2. Cancelar una reserva\n");
        printf(" 3. Mostrar asientos ocupados y libres\n");
        printf(" 4. Consultar reservas por pasajero\n");
        printf(" 5. Salir\n");
        printf(" Ingrese una opcion [1-5]:  ");
        scanf("%d", &op);
    } while (op < 1 || op > 5);
    return op;
}

// Permite reservar un asiento si está disponible
void reservarAsiento(Asiento avion[][COLUMNAS]) {
    int fila;
    char columna;
    printf("Ingrese la fila (1-25): ");
    scanf("%d", &fila);
    printf("Ingrese la columna (A-D): ");
    scanf(" %c", &columna);

    if (fila < 1 || fila > 25 || columna < 'A' || columna > 'D') {
        printf("Ubicacion invalida.\n");
        return;
    }

    int col = columna - 'A';
    if (avion[fila - 1][col].ocupado) {
        printf("El asiento ya está reservado.\n");
    } else {
        printf("Ingrese el nombre del pasajero: ");
        scanf(" %[^\n]", avion[fila - 1][col].pasajero);
        avion[fila - 1][col].ocupado = 1;
        printf("Reserva confirmada para %s.\n", avion[fila - 1][col].pasajero);
    }
}

// Permite cancelar una reserva si el asiento está ocupado
void cancelarReserva(Asiento avion[][COLUMNAS]) {
    int fila;
    char columna;
    printf("Ingrese la fila (1-25): ");
    scanf("%d", &fila);
    printf("Ingrese la columna (A-D): ");
    scanf(" %c", &columna);

    if (fila < 1 || fila > 25 || columna < 'A' || columna > 'D') {
        printf("Ubicacion invalida.\n");
        return;
    }

    int col = columna - 'A';
    if (avion[fila - 1][col].ocupado) {
        avion[fila - 1][col].ocupado = 0;
        strcpy(avion[fila - 1][col].pasajero, "");
        printf("Reserva cancelada.\n");
    } else {
        printf("El asiento ya está libre.\n");
    }
}

// Muestra todos los asientos y su estado
void mostrarEstado(Asiento avion[][COLUMNAS]) {
    printf("\nEstado de los asientos:\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("Fila %d Columna %c: %s\n", avion[i][j].fila, avion[i][j].columna,
                   avion[i][j].ocupado ? avion[i][j].pasajero : "Libre");
        }
    }
}

// Permite buscar reservas por nombre del pasajero
void consultarReservas(Asiento avion[][COLUMNAS]) {
    char nombre[50];
    int encontrados = 0, libres = 0, ocupados = 0;

    printf("Ingrese el nombre del pasajero: ");
    scanf(" %[^\n]", nombre);

    printf("\nReservas a nombre de %s:\n", nombre);
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (avion[i][j].ocupado) {
                ocupados++;
                if (strcmp(avion[i][j].pasajero, nombre) == 0) {
                    printf("Fila %d, Columna %c\n", avion[i][j].fila, avion[i][j].columna);
                    encontrados++;
                }
            } else {
                libres++;
            }
        }
    }

    if (!encontrados) {
        printf("No se encontraron reservas a nombre de %s.\n", nombre);
    }

    printf("\nAsientos disponibles: %d\n", libres);
    printf("Asientos ocupados: %d\n", ocupados);
}

