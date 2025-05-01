#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LARGO_CAD 81

void mostrar(FILE *x);
void mostrarVocales(FILE *x);
int contarVocales(char *x);


int main(){

    FILE *archivo;
    char origen[LARGO_CAD]="original.txt";

    if((archivo=fopen (origen, "r"))==NULL){
        printf("\n\n***El archivo %s no pudo abrirse ***\n", origen);
    }
    else
    {
        printf("\nEl archivo %s se ha abierto satisfactoriamente.\n", origen);
        printf("\nPresione una tecla para visualizar el contenido del archivo: %s\n", origen);
        getchar();

        rewind(archivo);
        printf("\nEl contenido del archivo de origen es:\n\n");
        mostrar(archivo);
        getchar();

        rewind(archivo);
        printf("\n\nCantidad de vocales por renglón:\n\n");
        mostrarVocales(archivo);

        printf("\nFin del programa...(presione cualquier tecla para terminar)\n");
        getchar();
        fclose(archivo);
    }

return 0;
}


// Mostrar contenido del archivo
void mostrar(FILE *x) {
    char cad[LARGO_CAD];
    while (fgets(cad, sizeof(cad), x) != NULL) {
        printf("%s", cad);
    }
}

// Mostrar cantidad de vocales por línea
void mostrarVocales(FILE *x) {
    char cad[LARGO_CAD];
    int renglon = 1;
    while (fgets(cad, sizeof(cad), x) != NULL) {
        printf("El renglon %d posee %d vocales\n", renglon, contarVocales(cad));
        renglon++;
    }
}

// Contar vocales en una línea
int contarVocales(char *x) {
    int contador = 0;
    for (int i = 0; x[i] != '\0'; i++) {
        char c = tolower(x[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contador++;
        }
    }
    return contador;
}
