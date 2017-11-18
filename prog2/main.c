#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define MAX 20


int main()
{

    char seguir='s';
    char opcion;
    system("color 17");
    ePersona personas[MAX];
    inicializar(personas, MAX);

    while(seguir=='s')
    {
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n\n");


        fflush(stdin);
        opcion=getchar();

        switch(opcion)
        {
        case '1':
            system("cls");
            cargarPersonas(personas, MAX);

            break;
        case '2':
            system("cls");
            eliminarPersona(personas, MAX);
            break;
        case '3':
            system("cls");

            ordenarPersona(personas, MAX);

            break;
        case '4':
            graficoPersona(personas,MAX);
            break;
        case '5':
            seguir = 'n';
            break;
        default:
            printf("La opcion es incorrecta.Ingrese un numero entre 1 y 5\n");
            break;
        }
    }


    return 0;
}
