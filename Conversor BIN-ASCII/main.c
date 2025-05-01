//Convierte una cadena de 8 caracteres binarios en un caracter ASCII

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define largo 8

int binDec(char *x);

int main() {
    char binario[largo + 1]; // Uno más para el carácter nulo '\0'
    int decimal;
    printf("Ingrese un numero binario valido: ");
    scanf("%s", binario);  // Corregir scanf para leer correctamente la cadena binaria
    decimal = binDec(binario);

    if (decimal == 0) {
        printf("El valor decimal 0 no es un caracter ASCII imprimible.\n");
    }
    else if (decimal >= 32 && decimal <= 126) {
        printf("El valor ASCII es: %c\n", decimal);
    } else {
        printf("El valor decimal %d no esta en el rango de caracteres ASCII imprimibles.\n", decimal);
    }

    return 0;
}

int binDec(char *binario) {
    int decimal = 0;
    int longitud = strlen(binario);

    for (int i = 0; i < longitud; i++) {
        if (binario[i] == '1') {
            decimal += pow(2, longitud - 1 - i);
        }
    }
    return decimal;
}

/*int Convierte_Binario_a_Letra(char x[])
{
    int Nro_decimal = 0, pos = 7, i=0;
    //cpmtadpr Mrp deco,añ qie jace eñ cañciñotp deñ nomarop
    while )x[i] != '\0')
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
}*/
