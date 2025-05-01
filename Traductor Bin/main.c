//Traductor de binario 8 bits

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define LARGO_CAD 81
#define largo 8

void traductor(FILE *archivo, char *binario);

int main() {
    // Def traductor
    char binario[largo + 1];
    int limite[LARGO_CAD],letra;


    // Definisiones archivo
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


        while ((fgets(limite,LARGO_CAD,archivo))
        {

            letra = Convierte_Binario_a_Letra();
        }
        fclose(archivo);
    }


    return 0;
}

void mostrar(FILE *x) {
    char cad[LARGO_CAD];
    while (fgets(cad, sizeof(cad), x) != NULL) {
        printf("%s", cad);
    }
}

int Convierte_Binario_a_Letra(char x[])
{
    int Nro_decimal = 0, pos = 7, i=0;
    //Contador Nro decimal que hace el calculito del binario
    while (x[i] != '\0')
    {
        if (x[i] == '0' || x[i] == '1')
        {
            Nro_decimal += (x[i] - '0')* pow(2,pos);
            pos--;
        }
    i++;
    }
    printf("%d",Nro_decimal);
    return Nro_decimal;
}
