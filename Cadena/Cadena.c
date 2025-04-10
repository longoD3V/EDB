#include <stdio.h>
#include <ctype.h>

int LargoCad();
char Mayu (char[],char[]);


int main()
{
    char cadena[50];
    char cadena2[50];

    printf("Ingrese una frase: ");
    fgets(cadena,sizeof(cadena),stdin);

    int longitud = LargoCad(cadena);
    if (cadena[longitud-1] == '\n')
        {
            cadena[longitud-1] = '\0';
            longitud--;
        }
    printf("La frase ingresa es: %s\n",cadena);
    printf("El largo de la frase es: %d\n",longitud);
    printf("La cadena en mayuscula es: %s",Mayu(cadena,cadena2));

    return 0;
}

int LargoCad(char cadena[])
{
    int i = 0;
    while(cadena[i] != '\0')
    {
     i++;
    }
return i;
}

char Mayu(char cadena[],char cadena2[])
{
    char cad[50];
    char cad2[50];
    strcmp(cadena,cad);
    cad2[50] = toupper(cad);
}
