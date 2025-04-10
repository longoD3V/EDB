#include <stdio.h>


void leerCadena(char*,int,int);

int main(){

    char cadena[100];

    printf("Ingrese una frase(Enter para terminar): ");
    leerCadena(cadena,0,sizeof(cadena));

    printf("Cadena Ingresada: %s\n",cadena);

    return 0;
}

void leerCadena(char *cadena,int indice,int max_longitud){
    if (indice >= max_longitud - 1 || (cadena[indice] = getchar()) == '\n'){
        cadena[indice] = '\0';
        return;
    }
    leerCadena(cadena,indice+1,max_longitud);
}

