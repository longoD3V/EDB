#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define p printf
#define s scanf
#define LARGO_CAD 81

void copiarArchivo(FILE*,FILE*);


int main(){

    FILE *archivo;
    FILE *archivo2;
    char origen[LARGO_CAD]="Origen.txt";
    char destino[LARGO_CAD]= "Destino.txt";

        if((archivo2=fopen (destino, "w+"))==NULL)
                p("\n\n***El archivo %s no pudo abrirse ***\n", destino);

        if((archivo=fopen (origen, "r"))==NULL)
            p("\n\n***El archivo %s no pudo abrirse ***\n", origen);
        else{
            copiarArchivo(archivo,archivo2);
            rewind(archivo);
            fclose(archivo);
        }

return 0;
}

void copiarArchivo(FILE *archivo,FILE *archivo2){

    char cad[LARGO_CAD];

        while(fgets(cad,81,archivo)!=NULL)
            {
                p("Copiando Archivo...\n");
                //sleep(1);
                fputs(cad,archivo2);

            }
    p(" -------------------------------\n");
    p("|%9cCopia exitosa%9c|\n",' ',' ');
    p(" -------------------------------");
}
