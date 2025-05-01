#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LARGO_CAD 81

void mostrar(FILE *x);
int cantAlum(FILE *x);

typedef struct{

    char nombre[LARGO_CAD];
    char apellido[LARGO_CAD];
    char materia[LARGO_CAD];
    int notaFinal;

}Alumnos;

int main(){

    FILE *archivo;
    char origen[LARGO_CAD]="DB.txt";
    Alumnos alumno[cantAlum()];

    if((archivo=fopen (origen, "r"))==NULL){
        printf("\n\n***El archivo %s no pudo abrirse ***\n", origen);
    }
    else
    {
        printf("\nEl archivo %s se ha abierto satisfactoriamente.\n", origen);
        printf("\nPresione una tecla para visualizar el contenido del archivo: %s\n", origen);
        getchar();


    }

return 0;
}


int cantAlum(){


}
