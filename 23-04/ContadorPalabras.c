#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define p printf
#define s scanf
#define LARGO_CAD 81

void contarArchivo(FILE*);


int main(){

    FILE *archivo;
    char origen[LARGO_CAD]="Origen.txt";

        if((archivo=fopen (origen, "r"))==NULL)
            p("\n\n***El archivo %s no pudo abrirse ***\n", origen);
        else{
            contarArchivo(archivo);
            rewind(archivo);
            fclose(archivo);
        }

return 0;
}

void contarArchivo(FILE *archivo)
{
    char cad[LARGO_CAD];
    int numero_renglon = 1;

    while (fgets(cad, LARGO_CAD, archivo) != NULL)
    {
        int contador_palabras = 0;
        int en_palabra = 0;


        for (int i = 0; cad[i] != '\0'; i++)
        {

            if (cad[i] == ' ' || cad[i] == '\t' || cad[i] == '\n' || cad[i] == '\r')
            {
                en_palabra = 0;
            }
            else if (!en_palabra)
            {
                contador_palabras++;
                en_palabra = 1;
            }
        }

        printf("La cantidad de palabras en la linea %d es: %d\n", numero_renglon, contador_palabras);
        numero_renglon++;
    }
}
