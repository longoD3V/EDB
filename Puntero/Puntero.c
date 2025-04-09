#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    //Comprender relacion entre variable y direccion de moemoria
    //Entender como los punteros pueden referenciar valores
    // Mostrar diferentes formas de acceder y manipular datos


    //Conceptos clave:
    //& (Operador de direccion): Obtiene la direccion de memoria variable.
    //* (Operador de desreferencia): accede al valor almacenado en ka dureccuib de un puntero.

    //Declaracion Variables
    int i,a;
    int *ptr;

    //Ingreso de datos
    printf("Ingrese el valor de i:");
    scanf("%d",&i);
    printf("Ingrese el valor de a:");
    scanf("%d",&a);

    //Modificacion de variables
    ptr = &i;
    a = *ptr;

    //Muestra de valores y direcciones
    printf("Contenido de i = %d y direccion de i: %p\n",i, &i);
    printf("Contenido de a = %d y direccion de a: %p\n",a, &a);
    printf("Contenido de ptr = %d y direccion de ptr: %p\n",*ptr,(void*)ptr);


    //Modificacion de variable
    *ptr = 9;

    //Muestra de valores y direcciones post modificacion de *ptr
    printf("Direccion de a: %p\n",(void*)&a);
    printf("Valor de i = %d direccion de i: %p \n",i,(void*)&i);
    printf("Contenido de ptr: %p\n",(void*)ptr);
    printf("Contenido de ptr: %p\n",&ptr);
    return 0;
}



/*cadena = (char *)malloc(capacidad * sizeof(char)); //(char*) es un casteo
    //Verificar asignacion memoria
    if (cadena == NULL){
        printf("Error al asignar memoria. \n");

        exit(1);
    }
    free(cadena);*/
