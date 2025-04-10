#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


void Suma (int,int,int*);

int main(){

    //Asignar variables
    int i,j,k;

    //Inicializar variables
    printf("Ingrese un numero:");
    scanf("%d",&i);
    printf("Ingrese otro numero:");
    scanf("%d",&j);

    // Llamar a la funcion
    Suma(3,2,&k);

    //Imprimir resultados
    printf("%d\n",k);

    return 0;
}

void Suma (int a,int b,int *s){
    if (b==0){
        *s=a;
    }
    else{
        Suma(a,b-1,s);
        *s=*s+1;
    }
}
