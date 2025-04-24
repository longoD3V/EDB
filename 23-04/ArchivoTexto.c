#include <stdio.h>
#include <stdlib.h>
#define p printf
#define s scanf
#define LARGO_CAD 81

void CrearArchivo(FILE*);
void LeerArchivo(FILE*);

int main() {

FILE *archivo;
char nombre[LARGO_CAD]="ArchivoTexto.txt";

    if((archivo=fopen (nombre, "a+"))==NULL)
        p("\n\n***El archivo %s no pudo abrirse ***\n", nombre);
    else{
            CrearArchivo(archivo);
            rewind(archivo);
            p("---------------Contenido del archivo---------------\n");
            LeerArchivo(archivo);
            fclose(archivo);
        }

return 0;
}

void CrearArchivo(FILE *archivo){

    char cad[LARGO_CAD];
    p("\n\nPara pasar de linea ingresar ENTER\n");
    p("\nPresionar Ctrl-z para finalizar\n");
        while((gets(cad)) != NULL){
            fputs(cad,archivo);
            fputc('\n',archivo);
        }
    p("\n");
}

void LeerArchivo(FILE *archivo){

    char cad[LARGO_CAD];
        while(fgets(cad,81,archivo))
            p("%s",cad);
            p("\n\n**FIN**\n");
            getch();

}
